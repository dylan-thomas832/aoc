// Copyright 2023 Dylan Thomas
// Standard Library
#include <iostream>
#include <string>
#include <vector>
// Local
#include "../include/cli.hpp"
#include "day4.hpp"  // NOLINT(build/include_subdir)

int main(int narg, char const* argv[]) {
    int error = aoc::check_cli(narg, argv);
    // Exit if bad CLI arguments
    if (error != EXIT_SUCCESS) {
        return error;
    }

    const std::string filename(argv[1]);
    std::vector<std::string> lines = day4::parse_input(filename);

    return EXIT_SUCCESS;
}
