#ifndef HASH_H_
#define HASH_H_

#include <cstring>
#include <stdint.h>
#include <stddef.h>

uint32_t Hash(const char* data){
    // id(x) = (int)x;
    // hash[i] = (hash[i-1]*p + id(s[i])) % mod;
    // p = 1e9+7
    // mod = 1610612741
    uint32_t hash = 1;
    uint32_t p = 1e9+7;
    uint32_t mod = 1610612741;
    for(size_t i=0; i<strlen(data); i++){
        hash = (hash * p + static_cast<uint32_t>(data[i])) % mod;
    }
    return static_cast<uint32_t>(hash);
};

#endif  // HASH_H_