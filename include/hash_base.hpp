/**
 * @file    hash_base.hpp
 * @brief   Defines the interface for a test harness that exercises a hash algorithm.
 */

#pragma once

#include <chrono>
#include <cstdint>
#include <set>

#include "hash_types.hpp"

/**
 * @class hash_base
 * @brief Defines the hash algorithm test harness interface.
 */
template <typename _derived_t, typename _hash_t> class hash_base {

public:

    /**
     * Runs the hashing tests
     */
    void run_test(const words_ptr_t& words, const words_ptr_t& uuids, const words_ptr_t& strings) {
        std::cout << name() << std::endl;

        std::cout << std::setw(16) << "Words";
        run_single_test(words);
        std::cout << std::setw(16) << "UUID v4";
        run_single_test(uuids);
        std::cout << std::setw(16) << "BLOBs";
        run_single_test(strings);
    }

    /**
     * Runs a single test.
     */
    void run_single_test(const words_ptr_t& words) {
        std::chrono::high_resolution_clock clock;
        std::set<_hash_t> buckets;
        uint collisions = 0;
        std::chrono::nanoseconds elapsed(0);
        words_t::iterator it;

        for (it = words->begin(); it != words->end(); it++) {
            std::string& s = *it;
            auto start_time = clock.now();
            _hash_t h = hash(s.c_str(), s.length(), 1337);
            auto end_time = clock.now();
            elapsed += (end_time - start_time);

            if (buckets.count(h) == 0) {
                buckets.insert(h);
            }
            else {
                ++collisions;
            }
        }

        std::cout << std::setw(16) << elapsed.count() / words->size() << std::setw(16) << buckets.size() << std::setw(16) << collisions << std::endl;
    }

    /**
     * Gets the name of the hashing function.
     */
    std::string name() {
        return static_cast<_derived_t*>(this)->do_name();
    }

    /**
     * Generates a hash for the data and returns it.
     */
    _hash_t hash(const void* data, const uint32_t data_length, const uint32_t seed) {
        return static_cast<_derived_t*>(this)->do_hash(data, data_length, seed);
    }
};
