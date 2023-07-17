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

CC = g++

CFLAGS_BASE = -std=c++17 -Wall -Wextra
CFLAGS_REL = -03
CFLAGS_DBG = -g -fsanitize=address

LDFLAGS_BASE =
LDFLAGS_DBG =  -fsanitize=address

# Set actual variables
CFLAGS = $(CFLAGS_BASE)
LDFLAGS = $(LDFLAGS_BASE)

########## TARGETS ##########

# Run `make all` by default
.DEFAULT_GOAL := all

# Phony tarets; useful to deconflict from "actual" targets (file named 'clean')
.PHONY: all clean debug release

# Main make entry point
all: $(EXEC)

debug:
	$(eval CFLAGS = $(CFLAGS_BASE) $(CFLAGS_DBG))
	$(eval LDFLAGS = $(LDFLAGS_BASE) $(LDFLAGS_DBG))

release:
	$(eval CFLAGS = $(CFLAGS_BASE) $(CFLAGS_REL))

# Link objects together into executable target
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@ $(LDFLAGS)

# Compile source files into translation units
%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

# Clean the repo up
clean:
	rm -f $(EXEC) $(OBJS)
