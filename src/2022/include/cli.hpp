// Copyright 2023 Dylan Thomas
#ifndef DJT_AOC_2022_CLI_HPP_
#define DJT_AOC_2022_CLI_HPP_
// Standard Library
#include <fstream>
#include <iostream>
#include <string>

namespace aoc {

int check_cli(int narg, char const* argv[]) {
    if (narg < 2) {
        std::cout << "Must provide the input file as the first CLI argument" << std::endl;
        return EXIT_FAILURE;
    }

    const std::string filename = argv[1];
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Unable to open file: " + filename << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

}  // namespace aoc

#endif  // DJT_AOC_2022_CLI_HPP_
