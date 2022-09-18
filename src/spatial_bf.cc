#include "filter_policy.h"

#include <iostream>
#include <bitset>

class SpatialBloomFilterPolicy : public FilterPolicy
{
private:
public:
    const char *Name() const override { return "SpatialBloomFilterPolicy"; }

    // override
    void Add(const char* key) override
    {
    }

    // override
    bool Contains(const char* key) const override
    {
        return true;
    }
};

FilterPolicy *NewSpatialBloomFilterPolicy()
{
    return new SpatialBloomFilterPolicy();
}
