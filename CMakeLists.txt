# TODO: Improve CMake builds
#   1. Finish top-level CMake options, see CPP best-practices, etc.
#   2. Create top-level Makefile that has debug/release targets that invoke CMake.
#   3. Fix executable build by converting to CMake-based
#   4. How to properly add compiler flags?
cmake_minimum_required(VERSION 3.21)


# strongly encouraged to enable this globally to avoid conflicts between
# -Wpedantic being enabled and -std=c++20 and -std=gnu++20 for example
# when compiling with PCH enabled
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the project name and language
project(
    AdventOfCode
    VERSION 0.0
    DESCRIPTION "Dylan's Advent of Code Solutions"
    LANGUAGES CXX
)


if(PROJECT_IS_TOP_LEVEL)
    include(cmake/StandardProjectSettings.cmake)
    # Only set the cxx_standard if it is not set by someone else
    if (NOT DEFINED CMAKE_CXX_STANDARD)
        set(CMAKE_CXX_STANDARD 17)
    endif()
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

add_subdirectory(src)
