#include "hash.h"

#include <cstring>
#include <stdint.h>
#include <stddef.h>

const uint32_t seeds[30] = {12323, 12401, 12487, 12553, 12641, 12739, 12829, 12923, 13007, 13109,
                            13187, 13309, 13411, 13499, 15149, 15259, 15319, 15401, 15497, 15607,
                            15679, 15773, 15881, 15971, 16069, 16183, 16267, 16381, 16481, 17891};

uint32_t Hash(const char *data, int seed_index)
{
    seed_index = seed_index < 0 ? 0 : seed_index > 29 ? 29
                                                      : seed_index;
    uint32_t _hash = 1;
    uint32_t p = 1e9 + 7;
    uint32_t mod = 1610612741;
    for (size_t i = 0; i < strlen(data); i++)
    {
        _hash = (_hash * p + static_cast<uint32_t>(data[i])) % mod;
    }
    _hash = (_hash * p + seeds[seed_index]) % mod;
    return _hash;
}