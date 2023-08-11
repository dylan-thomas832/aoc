// Copyright 2023 Dylan Thomas
#pragma once

#include <fstream>
#include <string>
#include <vector>

namespace day1 {

const char EMPTY_LINE[] = "";

// TODO(djt): Make this use shared_ptr
std::vector<int> parse_input(const std::string filename) {
    std::ifstream file(filename);

    int current_calorie_sum = 0;
    std::vector<int> calorie_counts;
    // Read input file stream line-by-line
    for (std::string line; getline(file, line);) {
        if (line == EMPTY_LINE) {
            // New line indicates new Elf's inventory. Add count and reset sum
            calorie_counts.push_back(current_calorie_sum);
            current_calorie_sum = 0;
        } else {
            // Increment the calorie count
            current_calorie_sum += std::stoi(line);
        }
    }

    return calorie_counts;
}

};  // namespace day1
