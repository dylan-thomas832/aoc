// Copyright 2023 Dylan Thomas
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "../../include/cli.hpp"
#include "../../include/day2.hpp"

int main(int narg, char const* argv[]) {
    int error = check_cli(narg, argv);
    // Exit if bad CLI arguments
    if (error != EXIT_SUCCESS) {
        return error;
    }

    const std::string filename(argv[1]);
    std::vector<day2::Round> rounds = day2::parse_input(filename);

    return EXIT_SUCCESS;
}
