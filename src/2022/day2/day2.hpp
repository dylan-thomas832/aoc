// Copyright 2023 Dylan Thomas
#ifndef DJT_AOC_2022_DAY2_
#define DJT_AOC_2022_DAY2_
// Standard Library
#include <fstream>
#include <string>
#include <tuple>
#include <vector>

namespace day2 {

using Round = std::tuple<char, char>;

// TODO(djt): Make this use shared_ptr
std::vector<Round> parse_input(const std::string filename) {
    std::ifstream file(filename);
    std::vector<Round> rounds;

    // Read input file stream line-by-line
    for (std::string line; getline(file, line);) {
        auto round = std::make_tuple(line.front(), line.back());
        rounds.push_back(round);
    }

    return rounds;
}

}  // namespace day2

#endif  // DJT_AOC_2022_DAY2_
