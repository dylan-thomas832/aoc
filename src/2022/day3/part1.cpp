// Copyright 2023 Dylan Thomas
// Standard Library
#include <iostream>
#include <string>
#include <vector>
// Local
#include "../include/cli.hpp"
#include "day3.hpp"  // NOLINT(build/include_subdir)

// Start a = 1
const char a = 'a';
const uint64_t lower = 1;
// Start A = 27
const char A = 'A';
const uint64_t upper = 27;

int main(int narg, char const* argv[]) {
    int error = aoc::check_cli(narg, argv);
    // Exit if bad CLI arguments
    if (error != EXIT_SUCCESS) {
        return error;
    }

    const std::string filename(argv[1]);
    std::vector<day3::RuckSack> rucksacks = day3::parse_input(filename);

    uint64_t priority_sum = 0;
    for (auto rucksack : rucksacks) {
        std::size_t split = rucksack.size() / 2;
        std::string first = rucksack.substr(0, split);
        std::string second = rucksack.substr(split);

        char found;
        for (auto item : first) {
            if (second.find(item) != second.npos) {
                found = item;
                break;
            }
        }

        uint64_t priority;
        if (islower(found)) {
            priority = (found - a) + lower;
        } else {
            priority = (found - A) + upper;
        }

        // NOTE: Debug print
        // std::cout << first << "  " << second << "  " << found << "  " << priority << std::endl;
        priority_sum += priority;
    }
    std::cout << "Priority sum  " << priority_sum << std::endl;

    return EXIT_SUCCESS;
}
