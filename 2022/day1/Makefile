########## Settings ##########

##### Makefile Settings #####
SHELL := bash
MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules

##### Files #####

INCLUDE =

# Executable to build
EXEC=run.exe

# Translation units to compile - one per .cpp file
OBJS = \
	src/main.o 		\

##### Compiler Settings #####

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -fsanitize=address

########## TARGETS ##########

# Run `make all` by default
.DEFAULT_GOAL := all

# Phony tarets; useful to deconflict from "actual" targets (file named 'clean')
.PHONY: all clean

# Main make entry point
all: $(EXEC)

# Link objects together into executable target
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into translation units
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean the repo up
clean:
	rm -f $(EXEC) $(OBJS)
