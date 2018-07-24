/**
 */

#include "djb2_hash.hpp"
#include "fnv_hash.hpp"
#include "hash_types.hpp"
#include "loselose_hash.hpp"
#include "murmur_hash.hpp"
#include "sdbm_hash.hpp"
#include "spooky_hash.hpp"

// Hashing words from the English language is interesting only to see how
// many collisions occur.
words_ptr_t read_words() {
    // Holds the words read from the file.
    auto words = words_ptr_t(new words_t);

    // Opens the file.
    std::ifstream words_file("words_alpha.txt");
    if (!words_file) {
        std::cerr << "Error opening `words_alpha.txt`." << std::endl;
        exit(1);
    }

    // Reads each line, converts it to lowercase, and saves it.
    std::string line;
    while (std::getline(words_file, line)) {
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        if (line.size() > 0) {
            words->push_back(line);
        }
    }

    return words;
}

// Version 4 UUIDs are randomly created which matches the use-case of a SQL
// database generating UUID keys for each new row and then creating a hash
// for the key in the index.
words_ptr_t create_uuids(const unsigned int quantity) {
    auto words = words_ptr_t(new words_t);

    uuid_t* uuid;
    char* str;

    uuid_create(&uuid);

    for (unsigned int i = 0; i < quantity; ++i) {
        uuid_make(uuid, UUID_MAKE_V4);
        str = nullptr;
        uuid_export(uuid, UUID_FMT_STR, &str, NULL);
        words->push_back(std::string(str));
        free(str);
    }

    uuid_destroy(uuid);
    return words;
}

words_ptr_t create_blobs(const unsigned int quantity) {
    // Length of the blobs to create.
    const unsigned int blob_length = 1024;

    // Strings returned to the caller.
    auto strings = words_ptr_t(new words_t);

    // Initialize the random number generator.
    std::random_device rdev;
    std::default_random_engine r;
    r.seed(rdev());

    // Buffer used to generate the strings.
    char* str = new char[blob_length + 1];

    // Generator
    for (auto q = 0; q < quantity; ++q) {
        for (auto i = 0; i < blob_length; ++i) {
            // Generate bytes with range [1,255] so that it can be zero-terminated.
            str[i] = (r() % 255) + 1;
        }

        str[blob_length] = L'\0';

        strings->push_back(str);
    }

    return strings;
}

int main() {

    // Generate the strings to test.
    std::cout << "Generating test data..." << std::endl;
    std::cout << "  Reading words file" << std::endl;
    auto words = read_words();
    std::cout << "  Generating UUIDs" << std::endl;
    auto uuids = create_uuids(words->size());
    std::cout << "  Generating BLOBs" << std::endl;
    auto strings = create_blobs(words->size());

    // Generate the header.
    std::cout << "Test arrays contain " << words->size() << " entries." << std::endl << std::endl;
    std::cout << std::setw(16) << "Algorithm / Data" << std::setw(16) << "Time (ns)" << std::setw(16) << "Buckets" << std::setw(16) << "Collisions" << std::endl;
    std::cout << std::setw(16) << "================" << std::setw(16) << "=========" << std::setw(16) << "=======" << std::setw(16) << "==========" << std::endl;

    // Test all of the hashing algorithms.
    djb2().run_test(words, uuids, strings);
    fnv1().run_test(words, uuids, strings);
    fnv1a().run_test(words, uuids, strings);
    loselose().run_test(words, uuids, strings);
    murmurhash1().run_test(words, uuids, strings);
    murmurhash1_aligned().run_test(words, uuids, strings);
    murmurhash2().run_test(words, uuids, strings);
    murmurhash64a().run_test(words, uuids, strings);
    murmurhash64b().run_test(words, uuids, strings);
    murmurhash2a().run_test(words, uuids, strings);
    murmurhashneutral2().run_test(words, uuids, strings);
    murmurhashaligned2().run_test(words, uuids, strings);
    murmurhash3_x86_32().run_test(words, uuids, strings);
    sdbm().run_test(words, uuids, strings);
    spookyhash32().run_test(words, uuids, strings);
    spookyhash64().run_test(words, uuids, strings);

    // Crashes with g++ compiler optimization flags.
    //murmurhash3_x86_128().run_test(words, uuids, strings);

    // Crashes with clang compiler optimization flags.
    //murmurhash3_x64_128().run_test(words, uuids, strings);

    return 0;
}
