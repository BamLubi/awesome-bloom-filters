#include "filter_policy.h"
#include "hash.h"

#include <iostream>
#include <bitset>

#define FILTER_SIZE 1000000000 // 1e9的容量

class BloomFilterPolicy : public FilterPolicy
{
private:
    mutable std::bitset<FILTER_SIZE> bits;
    size_t k_ = 10;

public:
    BloomFilterPolicy(size_t data_size = 1e8) {
        bits.reset();
        size_t bits_per_key = FILTER_SIZE / data_size;
        k_ = static_cast<size_t>(bits_per_key * 0.69);  // 0.69 =~ ln(2)
        k_ = k_ < 1 ? 1 : k_;
        k_ = k_ > 30 ? 30 : k_;
    }

    const char *Name() const override { return "BloomFilterPolicy"; }

    // override
    void Add(const char* key) override
    {
        uint32_t h = Hash(key);
        const uint32_t delta = (h >> 17) | (h << 15);  // Rotate right 17 bits
        for(size_t i = 0; i < k_; i++){
            bits[h % FILTER_SIZE] = 1;
            h += delta;
        }
    }

    // override
    bool Contains(const char* key) const override
    {
        uint32_t h = Hash(key);
        const uint32_t delta = (h >> 17) | (h << 15);  // Rotate right 17 bits
        // Set k_ hash functions
        for(size_t i = 0; i < k_; i++){
            if(!bits[h % FILTER_SIZE]) return false;
            h += delta;
        }
        return true;
    }

    unsigned long getBits(){
        return bits.to_ulong();
    }
};

FilterPolicy *NewBloomFilterPolicy(size_t data_size = 1e8)
{
    return new BloomFilterPolicy(data_size);
}