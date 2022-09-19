#include "filter_policy.h"
#include "hash.h"

#include <iostream>
#include <bitset>

#define FILTER_SIZE_BF 1000000000 // 1e9的容量

class BloomFilterPolicy : public FilterPolicy
{
private:
    std::bitset<FILTER_SIZE_BF> bits;
    size_t k_;

public:
    BloomFilterPolicy(size_t data_size) {
        bits.reset();
        size_t bits_per_key = FILTER_SIZE_BF / data_size;
        k_ = static_cast<size_t>(bits_per_key * 0.69);  // 0.69 =~ ln(2)
        k_ = k_ < 1 ? 1 : k_ > 30 ? 30 : k_;
    }

    BloomFilterPolicy(size_t data_size, size_t k) {
        bits.reset();
        k_ = k;
        k_ = k_ < 1 ? 1 : k_ > 30 ? 30 : k_;
    }

    const char *Name() const override { return "BloomFilterPolicy"; }

    // override
    void Add(const char* key) override
    {
        for(size_t i = 0; i < k_; i++){
            uint32_t h = Hash(key, i);
            bits[h % FILTER_SIZE_BF] = 1;
        }
    }

    // override
    bool Contains(const char* key) const override
    {
        // Set k_ hash functions
        for(size_t i = 0; i < k_; i++){
            uint32_t h = Hash(key, i);
            if(!bits.test(h % FILTER_SIZE_BF)) return false;
        }
        return true;
    }
};

FilterPolicy *NewBloomFilterPolicy(size_t data_size = 1e8, size_t k = 6)
{
    return new BloomFilterPolicy(data_size, k);
}