// Copyright 2023 Dylan Thomas
// Standard Library
#include <string>
// Local
#include "../include/cli.hpp"
#include "day3.hpp"  // NOLINT(build/include_subdir)

int main(int narg, char const* argv[]) {
    int error = aoc::check_cli(narg, argv);
    // Exit if bad CLI arguments
    if (error != EXIT_SUCCESS) {
        return error;
    }

    const std::string filename(argv[1]);
    std::vector<day3::RuckSack> rucksacks = day3::parse_input(filename);

    return EXIT_SUCCESS;
}
