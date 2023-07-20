##### Makefile Settings #####
SHELL := bash
MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules

# Build directory
builddir := .build

# Source root directory
sourcedir := .

# Compiler and compiler options
CC = gcc
CXX = g++
CMAKE_CXX_COMPILER := g++
CMAKE_OPTS =

CFLAGS_BASE = -std=c++17 -Wall -Wextra
CFLAGS_REL = -03
CFLAGS_DBG = -g -fsanitize=address

.PHONY: all install debug release clean new

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

new: clean
	rm -rf $(builddir)
