#include "filter_policy.h"
#include "hash.h"

#include <iostream>
#include <vector>
#include <cstring>

#define FILTER_SIZE_SBF 100000000 // 1e8的容量
#define max(x, y) x > y ? x : y

class SpatialBloomFilterPolicy : public FilterPolicy
{
private:
    std::vector<uint16_t> bits;
    size_t k_;

private:
    uint16_t GetArea(const char *key) const
    {
        return Hash(key, 20) % UINT16_MAX + 1;
    }

public:
    SpatialBloomFilterPolicy(size_t k) : k_(k)
    {
        bits.resize(FILTER_SIZE_SBF, 0);
    }

    ~SpatialBloomFilterPolicy()
    {
        std::vector<uint16_t>().swap(bits);
    }

    const char *Name() const override { return "SpatialBloomFilterPolicy"; }

    const size_t K() const override { return k_; }

    // override
    void Add(const char *key) override
    {
        uint16_t area = GetArea(key);
        for (int i = 0; i < k_; i++)
        {
            uint32_t h = Hash(key, i) % FILTER_SIZE_SBF;
            bits[h] = max(area, bits[h]);
        }
    }

    // override
    bool Contains(const char *key) const override
    {
        uint16_t area = GetArea(key);
        bool flg = false;
        for (int i = 0; i < k_; i++)
        {
            uint32_t h = Hash(key, i) % FILTER_SIZE_SBF;
            if (bits[h] < area)
                return false;
            if (bits[h] == area)
                flg = true;
        }
        return flg;
    }

    void Reset() override
    {
        std::vector<uint16_t> tmp(FILTER_SIZE_SBF, 0);
        bits.swap(tmp);
    }
};

FilterPolicy *NewSpatialBloomFilterPolicy(size_t k)
{
    return new SpatialBloomFilterPolicy(k);
}
