#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <random>
#include <stdio.h>
using namespace std;

default_random_engine generator(2022);
normal_distribution<double> dist_normal(0, 1.0);
uniform_real_distribution<double> dist_uniform(0, 10);
exponential_distribution<double> dist_exp(100);

// 高斯分布
int gen_normal()
{
    return static_cast<int>(dist_normal(generator) * 100000000);
}

// 均匀分布
int gen_uniform()
{
    return static_cast<int>(dist_uniform(generator) * 10000000);
}

// 指数分布
int gen_exp()
{
    return static_cast<int>(dist_exp(generator) * 10000000);
}

/**
 * @brief 生成数据
 * 
 * @param path 输出文件路径
 * @param file ofstream
 * @param data 数据分布
 */
void gen_data(const char *path, ofstream &file, int (*data)())
{
    unordered_map<int, int> hash;
    int cnt = 0;
    file.open(path, ofstream::out | ofstream::app);
    // 100000000
    for (int i = 0; i <= 100000000; i++)
    {
        int number = (*data)();
        file << number;
        if (!hash[number])
        {
            file << " 0\n";
            hash[number] = 1;
        } else {
            cnt++;
            file << " 1\n";
        }
        if (i % 10000000 == 0) cout << i << endl;
    }
    file.close();
    cout << "Repeat: " << (double)cnt / 100000000 << endl;
}

int main()
{
    ofstream ofs;
    // 1. 生成高斯分布数据集
    gen_data("./test_normal.txt", ofs, gen_normal);

    // 2. 生成均匀分布数据集
    gen_data("./test_uniform.txt", ofs, gen_uniform);

    // 3. 生成指数分布数据集
    gen_data("./test_exp.txt", ofs, gen_exp);
    return 0;
}