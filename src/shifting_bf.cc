#include "filter_policy.h"
#include "hash.h"

#include <iostream>
#include <bitset>

#define FILTER_SIZE_SHBF 1000000000 // 1e9的容量

class ShiftingBloomFilterPolicy : public FilterPolicy
{
private:
    std::bitset<FILTER_SIZE_SHBF + 25> bits; // m + c
    size_t k_;                               // 使用的时候只有 k / 2
    size_t w = 25;

public:
    ShiftingBloomFilterPolicy(size_t k) : k_(k)
    {
        bits.reset();
    }

    const char *Name() const override { return "ShiftingBloomFilterPolicy"; }

    // override
    void Add(const char *key) override
    {
        uint32_t offset = Hash(key, k_ / 2 + 1 - 1) % (w - 1) + 1;
        for (int i = 0; i < k_ / 2; i++)
        {
            uint32_t h = Hash(key, i);
            bits[h % FILTER_SIZE_SHBF] = 1;
            bits[h % FILTER_SIZE_SHBF + offset] = 1;
        }
    }

    // override
    bool Contains(const char *key) const override
    {
        uint32_t offset = Hash(key, k_ / 2 + 1 - 1) % (w - 1) + 1;
        for (int i = 0; i < k_ / 2; i++)
        {
            uint32_t h = Hash(key, i);
            if (!bits.test(h % FILTER_SIZE_SHBF) ||
                !bits.test(h % FILTER_SIZE_SHBF + offset))
                return false;
        }
        return true;
    }
};

FilterPolicy *NewShiftingBloomFilterPolicy(size_t k = 6)
{
    return new ShiftingBloomFilterPolicy(k);
}
