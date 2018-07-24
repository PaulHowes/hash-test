/**
 * @file    murmur_hash.hpp
 */
#pragma once

#include "hash_base.hpp"
#include "MurmurHash1.h"
#include "MurmurHash2.h"
#include "MurmurHash3.h"

class murmurhash1 : public hash_base<murmurhash1, uint32_t> {
public:
    std::string do_name() {
        return "MurmerHash1";
    }

    uint32_t do_hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        return MurmurHash1(data, data_length, seed);
    }
};

class murmurhash1_aligned : public hash_base<murmurhash1_aligned, uint32_t> {
public:
    std::string do_name() {
        return "MurmerHash1Aligned";
    }

    uint32_t do_hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        return MurmurHash1Aligned(data, data_length, seed);
    }
};

class murmurhash2 : public hash_base<murmurhash2, uint32_t> {
public:
    std::string do_name() {
        return "MurmurHash2";
    }

    uint32_t do_hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        return MurmurHash2(data, data_length, seed);
    }
};

class murmurhash64a : public hash_base<murmurhash64a, uint64_t> {
public:
    std::string do_name() {
        return "MurmurHash64A";
    }

    uint64_t do_hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        return MurmurHash64A(data, data_length, seed);
    }
};

class murmurhash64b : public hash_base<murmurhash64b, uint64_t> {
public:
    std::string do_name() {
        return "MurmurHash64B";
    }

    uint64_t do_hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        return MurmurHash64B(data, data_length, seed);
    }
};

class murmurhash2a : public hash_base<murmurhash2a, uint32_t> {
public:
    std::string do_name() {
        return "MurmurHash2A";
    }

    uint32_t do_hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        return MurmurHash2A(data, data_length, seed);
    }
};

class murmurhashneutral2 : public hash_base<murmurhashneutral2, uint32_t> {
public:
    std::string do_name() {
        return "MurmurHashNeutral2";
    }

    uint32_t do_hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        return MurmurHashNeutral2(data, data_length, seed);
    }
};

class murmurhashaligned2 : public hash_base<murmurhashaligned2, uint32_t> {
public:
    std::string do_name() {
        return "MurmurHashAligned2";
    }

    uint32_t do_hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        return MurmurHashAligned2(data, data_length, seed);
    }
};

class murmurhash3_x86_32 : public hash_base<murmurhash3_x86_32, uint32_t> {
public:
    std::string do_name() {
        return "MurmurHash3 x86 32-bit";
    }

    uint32_t do_hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        uint32_t hash;
        MurmurHash3_x86_32(data, data_length, seed, &hash);
        return hash;
    }
};

class murmurhash3_x86_128 : public hash_base<murmurhash3_x86_128, uint32_t> {
public:
    std::string do_name() {
        return "MurmurHash3 x86 128-bit";
    }

    uint32_t do_hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        uint32_t hash;
        MurmurHash3_x86_128(data, data_length, seed, &hash);
        return hash;
    }
};

class murmurhash3_x64_128 : public hash_base<murmurhash3_x64_128, uint64_t> {
public:
    std::string do_name() {
        return "MurmurHash3 x64 128-bit";
    }

    uint64_t do_hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        uint64_t hash;
        MurmurHash3_x64_128(data, data_length, seed, &hash);
        return hash;
    }
};
