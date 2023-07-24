// Copyright 2023 Dylan Thomas
#include <algorithm>
#include <iostream>
#include <vector>

#include "../../include/cli.hpp"
#include "../../include/day1.hpp"

int main(int narg, char const* argv[]) {
    int error = check_cli(narg, argv);
    // Exit if bad CLI arguments
    if (error != EXIT_SUCCESS) {
        return error;
    }

    std::vector<int> calorie_counts = day1::parse_input(argv[1]);

    // Find the maximum calories and the corresponding elf
    auto max_calories = std::max_element(calorie_counts.begin(), calorie_counts.end());
    auto elf = std::distance(calorie_counts.begin(), max_calories);
    std::cout << "The elf at " << elf << " has " << *max_calories << " calories" << std::endl;

    return EXIT_SUCCESS;
}
