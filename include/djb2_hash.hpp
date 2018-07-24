/**
 * @file    djb2_hash.hpp
 */
#pragma once

#include "hash_base.hpp"

/**
 * @brief   This algorithm was first reported by Dan Berstein in comp.lang.c
 */
class djb2 : public hash_base<djb2, uint32_t> {
public:
    std::string do_name() {
        return "DJB2";
    }

    uint32_t do_hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        const unsigned char* str = reinterpret_cast<const unsigned char*>(data);
        uint32_t hash = 5381;
        int c = 0;

        while ((c = *str++)) {
            hash = ((hash << 5) + hash) + c;
        }

        return hash;
    }
};
