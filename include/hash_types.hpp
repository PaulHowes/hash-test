/**
 * @file    hash_types.hpp
 * @brief   Complex type definitions used throughout the program.
 */

#pragma once

// Standard C++ library
#include <algorithm>
#include <codecvt>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <locale>
#include <memory>
#include <random>
#include <string>
#include <vector>

// OSSP-UUID generator, installed via Homebrew.
#include <ossp/uuid.h>

typedef std::vector<std::string>    words_t;
typedef std::unique_ptr<words_t>    words_ptr_t;
