/**
 * @file    loselose_hash.hpp
 */
#pragma once

#include "hash_base.hpp"

/**
 * @brief   This appeared in K&R 1st Ed. with the warning not to use it due to its extreme simplicity.
 */
class loselose : public hash_base<loselose, uint32_t> {
public:
    std::string do_name() {
        return "LoseLose";
    }

    uint32_t do_hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        const unsigned char* str = reinterpret_cast<const unsigned char*>(data);
        uint32_t hash = 0;
        int c = 0;

        while ((c = *str++)) {
            hash += c;
        }

        return hash;
    }
};
