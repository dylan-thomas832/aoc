// Copyright 2023 Dylan Thomas
#ifndef DJT_AOC_2022_DAY3
#define DJT_AOC_2022_DAY3
// Standard Library
#include <fstream>
#include <string>
#include <tuple>
#include <vector>

namespace day3 {

using RuckSack = std::string;

std::vector<RuckSack> parse_input(const std::string filename) {
    std::ifstream file(filename);
    std::vector<RuckSack> rucksacks;

    // Read input file stream line-by-line
    for (std::string line; getline(file, line);) {
        rucksacks.push_back(line);
    }

    return rucksacks;
}

}  // namespace day3

#endif  // DJT_AOC_2022_DAY3
