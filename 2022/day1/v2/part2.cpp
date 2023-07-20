// Copyright 2023 Dylan Thomas
#include <algorithm>
#include <iostream>
#include <vector>

#include "../../include/cli.hpp"
#include "../include/day1.hpp"

int main(int narg, char const *argv[]) {
    int error = check_cli(narg, argv);
    // Exit if bad CLI arguments
    if (error != EXIT_SUCCESS) {
        return error;
    }

    std::vector<int> calorie_counts = parse_input(argv[1]);

    int first = 0;
    int second = 0;
    int third = 0;
    for (std::size_t ii = 0; ii < calorie_counts.size(); ii++) {
        if (calorie_counts[ii] > first) {
            third = second;
            second = first;
            first = calorie_counts[ii];
        } else if (calorie_counts[ii] > second) {
            third = second;
            second = calorie_counts[ii];
        } else if (calorie_counts[ii] > third) {
            third = calorie_counts[ii];
        }
    }

    int top_three = first + second + third;
    std::cout << "The top three elves at have " << top_three << " calories" << std::endl;
    return EXIT_SUCCESS;
}
