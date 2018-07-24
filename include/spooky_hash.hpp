/**
 * @file    spooky_hash.hpp
 * @brief   Provides implementations for the versions 
 */
#pragma once

#include "hash_base.hpp"
#include "Spooky.h"

class spookyhash32 : public hash_base<spookyhash32, uint32_t> {
public:
    std::string do_name() {
        return "Spooky 32-bit Hash";
    }

    uint32_t do_hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        return SpookyHash::Hash32(data, data_length, seed);
    }
};

class spookyhash64 : public hash_base<spookyhash64, uint64_t> {
public:
    std::string do_name() {
        return "Spooky 64-bit Hash";
    }

    uint64_t do_hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        return SpookyHash::Hash64(data, data_length, seed);
    }
};

/*
class spookyhash128 : public hash_base<spookyhash128, uint128_t> {
public:
    std::string do_name() {
        return "Spooky 128-bit Hash";
    }

    uint128_t do_hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        uint64_t hash1 = seed;
        uint64_t hash2 = seed;
        SpookyHash::Hash64(data, data_length, &hash1, &hash2);
        
    }
};
*/