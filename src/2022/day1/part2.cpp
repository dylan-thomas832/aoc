// Copyright 2023 Dylan Thomas
// Standard Library
#include <algorithm>
#include <iostream>
#include <vector>
// Local
#include "../include/cli.hpp"
#include "day1.hpp"  // NOLINT(build/include_subdir)

int main(int narg, char const* argv[]) {
    int error = aoc::check_cli(narg, argv);
    // Exit if bad CLI arguments
    if (error != EXIT_SUCCESS) {
        return error;
    }

    std::vector<int> calorie_counts = day1::parse_input(argv[1]);

    // Sort backwards for descending
    std::sort(calorie_counts.rbegin(), calorie_counts.rend());
    int top_three = calorie_counts.at(0) + calorie_counts.at(1) + calorie_counts.at(2);
    std::cout << "The top three elves at have " << top_three << " calories" << std::endl;

    return EXIT_SUCCESS;
}
