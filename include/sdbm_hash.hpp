/**
 * @file    sdbm_hash.hpp
 */
#pragma once

#include "hash_base.hpp"

/**
 * @brief   Hashing algorithm used in databases.
 * 
 * This was created for SDBM which is a public-domain implementation of NDBM. The actual function is
 * `hash(i) = hash(i - 1) * 65599 + str[i]`. What appears below is a faster version used in `gawk`.
 */
class sdbm : public hash_base<sdbm, uint32_t> {
public:
    std::string do_name() {
        return "SDBM";
    }

    uint32_t do_hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        const unsigned char* str = reinterpret_cast<const unsigned char*>(data);
        uint32_t hash = 0;
        int c = 0;

        while ((c = *str++)) {
            hash = c + (hash << 6) + (hash << 16) - hash;
        }

        return hash;
    }
};
