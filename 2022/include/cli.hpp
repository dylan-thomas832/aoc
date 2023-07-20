// Copyright 2023 Dylan Thomas
#pragma once

#include <fstream>
#include <iostream>
#include <string>

int check_cli(int narg, char const *argv[]) {
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
