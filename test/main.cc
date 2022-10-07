#include "filter_policy.h"
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <chrono>
#include <fstream>
#include <vector>

/**
 * @brief 测试
 * 
 * @param path 测试数据集路径
 * @param filter 过滤器
 */
void test(const char *path, FilterPolicy *filter)
{
    printf("\nTest Path: %s; Filter: %s; Hash Functions: %ld\n", path, filter->Name(), filter->K());
    std::ifstream file;
    std::string s;
    std::vector<float> time_stat;
    std::vector<float> fault_stat;
    int total = 0;
    int fault = 0;

    // 打开文件
    file.open(path, std::ios_base::in);
    filter->Reset();

    // 设置计时器
    auto t_start_init = std::chrono::high_resolution_clock::now();
    auto t_start = std::chrono::high_resolution_clock::now();
    auto t_end = std::chrono::high_resolution_clock::now();

    // 读取文件
    while (getline(file, s))
    {
        const char *key = s.substr(0, s.size() - 2).c_str();
        const bool value = s[s.length() - 1] - '0';
        total++;
        bool flg = filter->Contains(key);
        if (flg != value)
            fault++;
        if (!flg)
            filter->Add(key);
        if (total % 10000000 == 0)
        {
            fault_stat.push_back((float)fault / total);
            t_end = std::chrono::high_resolution_clock::now();
            time_stat.push_back(std::chrono::duration<float, std::milli>(t_end - t_start).count() / 1000);
            t_start = t_end;
        }
    }
    t_end = std::chrono::high_resolution_clock::now();
    float t_total = std::chrono::duration<float, std::milli>(t_end - t_start_init).count() / 1000;

    // 打印统计信息
    // FAULT
    printf("FAULT: ");
    for (auto t : fault_stat)
        std::cout << t << " ";
    // TOTAL FAULT
    printf("\nTOTAL FAULT: %f %%", (float)fault / total);
    // TIME
    printf("\nTIME: ");
    for (auto t : time_stat)
        printf("%f ", t);
    // TOTAL TIME
    printf("\nTOTAL TIME: %f s.\n", t_total);
    file.close();
}

/**
 * @brief 简易测试, 只测试一个元素
 *
 * @param filter 过滤器
 */
void simple_test(FilterPolicy *filter)
{
    std::cout << "\nTest : " << filter->Name() << std::endl;
    const char *key = "asfafsaf";
    bool flg = filter->Contains(key);
    if (!flg)
    {
        std::cout << key << " not exits!" << std::endl;
        filter->Add(key);
        std::cout << key << " adding ..." << std::endl;
    }
    flg = filter->Contains(key);
    if (flg == 1)
    {
        std::cout << key << " exits! SUCCESSFUL!" << std::endl;
    }
    else
    {
        std::cout << key << " not exits! FAIL!" << std::endl;
    }
}

int main()
{
    { // 测试一: 测试三种不同数据集分布下不同过滤器的差距
        FilterPolicy *bloom = NewBloomFilterPolicy(1e8, 10);
        FilterPolicy *shift_bloom = NewShiftingBloomFilterPolicy(10);
        FilterPolicy *spatial_bloom = NewSpatialBloomFilterPolicy(10);

        // 1.1 高斯分布
        test("../datasets/test_normal.txt", bloom);
        test("../datasets/test_normal.txt", shift_bloom);
        test("../datasets/test_normal.txt", spatial_bloom);
        // 1.2 均匀分布
        test("../datasets/test_uniform.txt", bloom);
        test("../datasets/test_uniform.txt", shift_bloom);
        test("../datasets/test_uniform.txt", spatial_bloom);
        // 1.3 指数分布
        test("../datasets/test_exp.txt", bloom);
        test("../datasets/test_exp.txt", shift_bloom);
        test("../datasets/test_exp.txt", spatial_bloom);
    }

    { // 测试二: 不同 K 值对过滤器的影响，使用均匀分布的数据集
        int k_list[] = {2, 4, 6, 8, 10, 12, 14};
        for (auto k : k_list)
        {
            FilterPolicy *bloom = NewBloomFilterPolicy(1e8, k);
            FilterPolicy *shift_bloom = NewShiftingBloomFilterPolicy(k);
            FilterPolicy *spatial_bloom = NewSpatialBloomFilterPolicy(k);
            test("../datasets/test_uniform.txt", bloom);
            test("../datasets/test_uniform.txt", shift_bloom);
            test("../datasets/test_uniform.txt", spatial_bloom);
            delete bloom;
            delete shift_bloom;
            delete spatial_bloom;
        }
    }

    { // 测试三: 测试对 Shifting Bloom Filter 的改进
        FilterPolicy *imp_shift_bloom = NewImproveShiftingBloomFilterPolicy(10);
        test("../datasets/test_normal.txt", imp_shift_bloom);
        test("../datasets/test_uniform.txt", imp_shift_bloom);
        test("../datasets/test_exp.txt", imp_shift_bloom);
    }

    return 0;
}
