##### Makefile Settings #####

# Default to using bash
SHELL := bash
# Don't allow builtin rules & suppress "entering directory" lines.
MAKEFLAGS += --no-builtin-rules --no-print-directory

# Build directory
build_path := build

# Source root directory
source_path := .

# Compiler and linker options
CC = gcc
CXX = g++
CMAKE_CXX_COMPILER := g++
CMAKE_OPTS =

# Number cores to use for building
CORES := 10

# Finds all built *.exe files for cleaning
executables := $(shell find $(source_path) -name '*.exe')

# Run all target by default
.DEFAULT = all

# Target: all - compile & install executables
.PHONY: all
all: install

# Target: build command - depends on build/Makefile
%.exe: $(build_path)/Makefile
	cmake --build $(build_path) -- -j${CORES}

# Target: configure commad - depends on CMakeLists.txt
$(build_path)/Makefile: CMakeLists.txt
	cmake -S $(source_path) -B $(build_path) ${CMAKE_OPTS}

# Target: install command - depends on executable
install: %.exe
	cmake --install $(build_path)

# Target: debug - set build type to Debug
.PHONY: debug
debug:
	$(eval CMAKE_OPTS = -DCMAKE_BUILD_TYPE=Debug)

# Target: release - set build type to Debug
.PHONY: release
release:
	$(eval CMAKE_OPTS = -DCMAKE_BUILD_TYPE=Release)

# Target: clean - remove object files and executables to trigger a new build
.PHONY: clean
clean:
	cmake --build $(build_path) --target clean
	rm -rf $(executables)

# Target: new - remove entire build directory also
.PHONY: new
new: clean
	rm -rf $(build_path)
