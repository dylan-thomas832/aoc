// Copyright 2023 Dylan Thomas
#pragma once

#include <fstream>
#include <string>
#include <utility>
#include <vector>

const char EMPTY_LINE[] = "";

// TODO(djt): Make this use shared_ptr
std::vector<std::pair<char, char>> parse_input(const std::string filename) {
    std::ifstream file(filename);
    std::vector<std::pair<char, char>> rounds;

    // Read input file stream line-by-line
    for (std::string line; getline(file, line);) {
        rounds.push_back(std::make_pair(line[0], line[-1]));
    }

    return rounds;
}
