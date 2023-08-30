// Copyright 2023 Dylan Thomas
// Standard Library
#include <string>
// Local
#include "../include/cli.hpp"
#include "day3.hpp"  // NOLINT(build/include_subdir)

// Start a = 1
const char a = 'a';
const uint64_t lower = 1;
// Start A = 27
const char A = 'A';
const uint64_t upper = 27;

const std::size_t GROUP_SIZE = 3;
using Group = std::array<day3::RuckSack, GROUP_SIZE>;

int main(int narg, char const* argv[]) {
    int error = aoc::check_cli(narg, argv);
    // Exit if bad CLI arguments
    if (error != EXIT_SUCCESS) {
        return error;
    }

    const std::string filename(argv[1]);
    std::vector<day3::RuckSack> rucksacks = day3::parse_input(filename);

    uint64_t priority_sum = 0;
    std::vector<day3::RuckSack>::iterator it;
    for (std::size_t ii = 0; ii < rucksacks.size(); ii += GROUP_SIZE) {
        Group group = {rucksacks[ii], rucksacks[ii + 1], rucksacks[ii + 2]};

        char found;
        for (auto item : group[0]) {
            if (group[1].find(item) == std::string::npos) {
                continue;
            }
            if (group[2].find(item) == std::string::npos) {
                continue;
            }
            found = item;
            break;
        }

        uint64_t priority;
        if (islower(found)) {
            priority = (found - a) + lower;
        } else {
            priority = (found - A) + upper;
        }

        // NOTE: Debug print
        // std::cout << found << "  " << priority << std::endl;
        priority_sum += priority;
    }
    std::cout << "Priority sum  " << priority_sum << std::endl;

    return EXIT_SUCCESS;
}
