#ifndef FILTER_POLICY_H_
#define FILTER_POLICY_H_

#include <stdint.h>
#include <stddef.h>

class FilterPolicy
{
public:

    /**
     * @brief Return the name of filter
     * 
     * @return const char* 
     */
    virtual const char* Name() const = 0;

    /**
     * @brief Return the number of Hash fucntions
     * 
     * @return const size_t 
     */
    virtual const size_t K() const = 0;

    /**
     * @brief Add Key to Bloom Filter
     * 
     * @param key [string]
     */
    virtual void Add(const char* key) = 0;

    /**
     * @brief Whether ccontains the Key
     * 
     * @param key [string]
     * @return true 
     * @return false 
     */
    virtual bool Contains(const char* key) const = 0;

    /**
     * @brief reset
     * 
     */
    virtual void Reset() = 0;
};

FilterPolicy* NewBloomFilterPolicy(size_t data_size, size_t k);
FilterPolicy* NewShiftingBloomFilterPolicy(size_t k);
FilterPolicy* NewSpatialBloomFilterPolicy(size_t k);
FilterPolicy* NewImproveShiftingBloomFilterPolicy(size_t k);

#endif // FILTER_POLICY_H_