// Copyright 2023 Dylan Thomas
#include <algorithm>
#include <iostream>
#include <vector>

#include "../../include/cli.hpp"
#include "../../include/day1.hpp"

int main(int narg, char const *argv[]) {
    int error = check_cli(narg, argv);
    // Exit if bad CLI arguments
    if (error != EXIT_SUCCESS) {
        return error;
    }

    std::vector<int> calorie_counts = parse_input(argv[1]);

    std::size_t elf;
    int max_calories = 0;
    for (std::size_t ii = 0; ii < calorie_counts.size(); ii++) {
        if (calorie_counts[ii] > max_calories) {
            max_calories = calorie_counts[ii];
            elf = ii;
        }
    }

    std::cout << "The elf at " << elf << " has " << max_calories << " calories" << std::endl;
    return EXIT_SUCCESS;
}
