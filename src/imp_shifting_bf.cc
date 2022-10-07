#include "filter_policy.h"
#include "hash.h"

#include <iostream>
#include <bitset>

#define FILTER_SIZE_SHBF 100000000 // 1e8的容量

class ImproveShiftingBloomFilterPolicy : public FilterPolicy
{
private:
    std::bitset<FILTER_SIZE_SHBF + 24> bits; // m + c
    std::bitset<FILTER_SIZE_SHBF> bits_bak;
    size_t k_; // 使用的时候只有 k / 2
    size_t w = 24;
    uint32_t *q;

public:
    ImproveShiftingBloomFilterPolicy(size_t k) : k_(k)
    {
        bits.reset();
        q = reinterpret_cast<uint32_t *>(&bits);
    }

    const char *Name() const override { return "ImproveShiftingBloomFilterPolicy"; }

    const size_t K() const override { return k_; }

    // override
    void Add(const char *key) override
    {
        uint32_t offset = Hash(key, (k_ >> 1) + 1 - 1) % (w - 1) + 1;
        bits_bak[Hash(key, (k_ >> 1) + 1 - 1) % FILTER_SIZE_SHBF] = 1;
        for (int i = 0; i < k_ / 2; i++)
        {
            uint32_t h = Hash(key, i) % FILTER_SIZE_SHBF;
            uint32_t *t = (uint32_t *)((char *)q + (h >> 3));
            *t = *t | (1 << (h % 8)) | (1 << (h % 8 + offset));
        }
    }

    // override
    bool Contains(const char *key) const override
    {
        uint32_t offset = Hash(key, (k_ >> 1) + 1 - 1) % (w - 1) + 1;
        if (!bits_bak[Hash(key, (k_ >> 1) + 1 - 1) % FILTER_SIZE_SHBF])
            return false;
        for (int i = 0; i < k_ / 2; i++)
        {
            uint32_t h = Hash(key, i) % FILTER_SIZE_SHBF;
            uint32_t *t = (uint32_t *)((char *)q + (h >> 3));
            if (((*t >> (h % 8)) & 1) == 0 || ((*t >> (h % 8 + offset)) & 1) == 0)
                return false;
        }
        return true;
    }

    void Reset() override
    {
        bits.reset();
        bits_bak.reset();
    }
};

FilterPolicy *NewImproveShiftingBloomFilterPolicy(size_t k = 6)
{
    return new ImproveShiftingBloomFilterPolicy(k);
}
