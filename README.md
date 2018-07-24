# HASH-TEST

Comparison of various hashing algorithms.

After reading the excellent hash algorithm comparion on the
[Software Engineering Stack Exchange](https://softwareengineering.stackexchange.com/a/145633)
I realized that the [author](https://softwareengineering.stackexchange.com/users/6654/ian-boyd)
didn't include a source code repository with his code.

The code that I have written is not as complete as what he had, but serves my
purpose of running various algorithms and comparing their speed and collision
rate.

# Usage

Simply build and run the `hash-test` executable. It will run each supported
hash algorithm with a list of english words, a series of randomly generated
type-4 UUID values to simulate how a database would hash a UUID for a primary
key, and a series of random 1 kB BLOBs to simulate how a key-value store would
hash a BLOB to generate the key. Output from the `hash-test` executable
includes the average hash time, the number of buckets generated, and the
number of hash collisions for each combination of algorithm and data.

# Building

I highly recommend building outside of the source tree so that build products
do not pollute the repository. The simplest way to accomplish this witht the
default system compiler is as follows:

    $ mkdir build
    $ cd build
    $ cmake ..
    $ make

Flags that can be passed to CMake that affect the build include:

* Generate a release build that optimizes the executable for speed:

    `cmake -DCMAKE_BUILD_TYPE=release ..`

* Use the version of clang++ installed via [Homebrew](https://brew.sh/):

    `cmake -DCMAKE_CXX_COMPILER=/usr/local/opt/llvm/bin/clang++ ..`

* Use the version of g++ installed via [Homebrew](https://brew.sh/):

    `cmake -DCMAKE_CXX_COMPILER=/usr/local/opt/gcc/bin/g++-8 ..`

## Dependencies

Build tools:

* [CMake](http://www.cmake.org) 3.11.4 or newer
* C++ compiler. The following have been tested:
  * [AppleClang](https://developer.apple.com/xcode/) 9.0.0 included in Xcode 9.2
  * [clang++](http://clang.llvm.org) 6.0.12
  * [g++](https://gcc.gnu.org) 8.1.0

External source code downloaded during the build:

* [English Word List](https://github.com/dwyl/english-words)

  List of english words that were originally from InfoChimps. `hash-test` uses
  the file that contains words with only alphabetic characters.

* [SMHasher](https://github.com/aappleby/smhasher)

  The author of the SMHasher test suite also created the MurmurHash family of
  hashing functions.

# Contributing

1. Fork it
2. Create a feature branch (`git checkout -b new-feature`)
3. Commit changes (`git commit -am "Added new feature xyz"`)
4. Push the branch (`git push origin new-feature`)
5. Create a new pull request.

# Maintainers

* [Paul Howes](http://github.com/PaulHowes/)

# License

`hash-test` comparison tool copyright 2015 Paul Howes and is licensed under
the Apache License.
