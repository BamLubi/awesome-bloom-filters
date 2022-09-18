#include "filter_policy.h"

#include <iostream>
#include <bitset>

class ShiftingBloomFilterPolicy : public FilterPolicy
{
private:
public:
    const char *Name() const override { return "ShiftingBloomFilterPolicy"; }

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

FilterPolicy *NewShiftingBloomFilterPolicy()
{
    return new ShiftingBloomFilterPolicy();
}
