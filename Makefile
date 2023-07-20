##### Makefile Settings #####
SHELL := bash
MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules

# Build directory
builddir := .build

# Source root directory
sourcedir := .

.PHONY: all clean debug release

# Compiler and compiler options
CC = gcc
CMAKE_CXX_COMPILER := g++
CMAKE_OPTS =


all:
	@cmake -S $(sourcedir) -B $(builddir) $(CMAKE_OPTS)
	@cmake --build $(builddir)

install: all
	@cmake --install $(builddir)

debug:
	$(eval CMAKE_OPTS = -DCMAKE_BUILD_TYPE=Debug)

release:
	$(eval CMAKE_OPTS = -DCMAKE_BUILD_TYPE=Release)

# Finds all built *.exe files for cleaning
executables := $(shell find $(SOURCEDIR) -name '*.exe')
clean:
	@cmake --build $(builddir) --target clean
	rm -rf $(executables)
