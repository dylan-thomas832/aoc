// Copyright 2023 Dylan Thomas
#include <algorithm>
#include <iostream>
#include <vector>

#include "../../include/cli.hpp"
#include "../../include/day2.hpp"

int main(int narg, char const *argv[]) {
    int error = check_cli(narg, argv);
    // Exit if bad CLI arguments
    if (error != EXIT_SUCCESS) {
        return error;
    }

    return EXIT_SUCCESS;
}
