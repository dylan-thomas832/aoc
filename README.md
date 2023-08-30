# Dylan's Advent of Code

This holds my attempts at [Advent of Code](https://adventofcode.com/) solutions.
The solutions will mostly be in C++ and Python for practicing.

## Installation

This project uses a few Python packages for C++ linting/etc.
On first setup, follow the instructions to properly setup your build environment.

1. Clone the repo:
   ```bash
   git clone git@github.com:dylan-thomas832/aoc.git
   ```
1. Change directory:
   ```bash
   cd aoc
   ```
1. Create a development Python environment:
   ```bash
   python -m venv .venv
   ```
1. Activate the environment:
   ```bash
   source .venv/bin/activate
   ```
1. Install Python packages via `pip`:
   ```bash
   pip install -r requirements.txt
   ```
1. Install `pre-commit` hooks:
   ```bash
   pre-commit install
   ```

Once you completed the developer install, you only have to repeat Step 4 when starting to work.

## Building

This project uses `cmake` to build, and is currently only tested to build on Linux using GCC.
`cmake` is installed via `pip` in the previous section, but you'll need to make sure a valid GCC is installed with version 8 or higher.

The project executables can be built simply by running `make` which will configure, build, and install everything via `cmake`.
By default, it builds in `RelWithDebInfo` mode, but running `make debug all` or `make release all` can change the build type.

To clean the project, removing built object files & executables, run `make clean`.
A complete rebuild, including forcing `cmake` to reconfigure is done via `make new`.

## Running

Once built and installed, each day/part has a separate executable that can be run independently.
The input file will be co-located with the day's source code:

```bash
$ ./src/2022/day1/run_part1.exe src/2022/day1/input.txt
The elf at 224 has 68923 calories
```

## To DO

- [x] Improve CMake build types
- [ ] Figure out how to debug
- [x] Create top-level `include` and `src` directories with years under it
- [ ] ~Create script to compare outputs of each version~
- [x] Create installation instructions

## Progress

Days are deleted once completed & verified.
This includes both versions.

- 2022
  - Day 4
  - Day 5
  - Day 6
  - Day 7
  - Day 8
  - Day 9
  - Day 10
  - Day 11
  - Day 12
  - Day 13
  - Day 14
  - Day 15
  - Day 16
  - Day 17
  - Day 18
  - Day 19
  - Day 20
  - Day 21
  - Day 22
  - Day 23
  - Day 24
  - Day 25
