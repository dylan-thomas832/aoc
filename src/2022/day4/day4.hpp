// Copyright 2023 Dylan Thomas
#ifndef DJT_AOC_2022_DAY4_
#define DJT_AOC_2022_DAY4_
// Standard Library
#include <fstream>
#include <string>
#include <vector>

namespace day4 {

std::vector<std::string> parse_input(const std::string filename) {
    std::ifstream file(filename);
    std::vector<std::string> lines;

    // Read input file stream line-by-line
    for (std::string line; getline(file, line);) {
        lines.push_back(line);
    }

    return lines;
}

}  // namespace day4

#endif  // DJT_AOC_2022_DAY4_
