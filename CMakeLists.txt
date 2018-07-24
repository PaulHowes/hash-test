cmake_minimum_required(VERSION 3.11.4)
project(hash-test)

# Configures the compiler, regardless of the build type.
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
    add_compile_options(-std=c++1z)
    if("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")
        add_compile_options(-stdlib=libc++)
    endif()
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options(-std=c++17)
endif()

# Sets the `hash` target as an executable.
add_executable(hash-test)

# The header files necessary to build the `hash` target.
target_include_directories(hash-test
    PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/include"
    "/usr/local/opt/ossp-uuid/include"
)

# Libraries
target_link_libraries(hash-test
    PRIVATE
    "/usr/local/opt/ossp-uuid/lib/libuuid.a"
)

# The source files necessary to build the `hash` target.
target_sources(hash-test
    PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/src/hash_main.cpp"
)

include(FetchContent)

# External sources for the various hash algorithms being tested.
FetchContent_Declare(
    smhasher
    GIT_REPOSITORY  "https://github.com/aappleby/smhasher.git"
)
FetchContent_GetProperties(smhasher)
if(NOT smhasher_POPULATED)
    FetchContent_Populate(smhasher)
    target_include_directories(hash-test
        PRIVATE
        "${smhasher_SOURCE_DIR}/src"
    )
    target_sources(hash-test
        PRIVATE
        "${smhasher_SOURCE_DIR}/src/MurmurHash1.cpp"
        "${smhasher_SOURCE_DIR}/src/MurmurHash2.cpp"
        "${smhasher_SOURCE_DIR}/src/MurmurHash3.cpp"
        "${smhasher_SOURCE_DIR}/src/Spooky.cpp"
    )
endif()

# Dictionary of english words.
FetchContent_Declare(
    english_words
    GIT_REPOSITORY  "https://github.com/dwyl/english-words.git"
)
FetchContent_GetProperties(english_words)
if(NOT english_words_POPULATED)
    FetchContent_Populate(english_words)
    file(COPY "${english_words_SOURCE_DIR}/words_alpha.txt" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()
