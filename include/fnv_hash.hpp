/**
 * @file    fnv_hash.hpp
 */
#pragma once

#include "hash_base.hpp"

/**
 * @brief   Public-domain hashing algorithm.
 * 
 * https://en.wikipedia.org/wiki/Fowler–Noll–Vo_hash_function
 */
class fnv1 : public hash_base<fnv1, uint32_t> {
public:
    std::string do_name() {
        return "FNV1";
    }

    uint32_t do_hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        const uint32_t PRIME = 0x01000193;
        const uint32_t BASIS = 0x811C9DC5;
        const unsigned char* str = reinterpret_cast<const unsigned char*>(data);
        uint32_t hash = BASIS;
        int c = 0;

        while ((c = *str++)) {
            hash = (PRIME * hash) ^ c;
        }

        return hash;
    }
};

/**
 * @brief   Public-domain hashing algorithm.
 * 
 * https://en.wikipedia.org/wiki/Fowler–Noll–Vo_hash_function
 */
class fnv1a : public hash_base<fnv1a, uint32_t> {
public:
    std::string do_name() {
        return "FNV1A";
    }

    uint32_t do_hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        const uint32_t PRIME = 0x01000193;
        const uint32_t BASIS = 0x811C9DC5;
        const unsigned char* str = reinterpret_cast<const unsigned char*>(data);
        uint32_t hash = BASIS;
        int c = 0;

        while ((c = *str++)) {
            hash = PRIME * (hash ^ c);
        }

        return hash;
    }
};
