#ifndef HASH_H_
#define HASH_H_

#include <cstring>
#include <stdint.h>
#include <stddef.h>

uint32_t Hash(const char *data, int seed_index);

#endif // HASH_H_