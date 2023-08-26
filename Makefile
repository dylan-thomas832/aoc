##### Makefile Settings #####
SHELL := bash
# MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules
MAKEFLAGS += -s

# Build directory
builddir := build

# Source root directory
sourcedir := .

# Compiler and compiler options
CC = gcc
CXX = g++
CMAKE_CXX_COMPILER := g++
# CMAKE_OPTS =

# CFLAGS_BASE = -std=c++17 -Wall -Wextra
# CFLAGS_REL = -03
# CFLAGS_DBG = -g -fsanitize=address


define to_lower_case
$(shell echo $(1) | tr '[:upper:]' '[:lower:]')
endef

define find_in_list
$(shell resolved_value=$$(for candidate in $(2); do \
		if [ "$(call to_lower_case,$(1))" = "$$(echo $$candidate | tr '[:upper:]' '[:lower:]')" ]; then \
			echo $$candidate; \
		fi; \
	done); \
	echo "$${resolved_value:-$(1)}";)
endef

define exists_in_list
$(shell resolved_value=$$(for candidate in $(2); do \
		if [ "$(call to_lower_case,$(1))" = "$$(echo $$candidate | tr '[:upper:]' '[:lower:]')" ]; then \
			echo true; \
		fi; \
	done); \
	echo "$${resolved_value:-false}";)
endef

# =============================================================================
# Variables
# =============================================================================

project_name:=?
project_lang:=?
type:=debug
generator:=$(shell if [ -x "$$(which ninja)" ]; then echo "Ninja"; else echo "Unix Makefiles"; fi)
build_path:=$(shell echo "build/$(call to_lower_case,$(type))")

override cores:=$(shell if [ "$$(uname)" = "Darwin" ]; then sysctl -n hw.ncpu; elif [ "$$(uname)" = "Linux" ]; then nproc --all; else echo 1; fi)

override valid_generators:="Unix Makefiles" "Ninja" "Xcode"
override valid_types:=Release Debug RelWithDebInfo MinSizeRel
override debug_types:=Debug RelWithDebInfo

override cmake_build_type_arg:=$(call find_in_list,$(type),$(valid_types))
override cmake_generator_arg:=$(call find_in_list,$(generator),$(valid_generators))
override is_debug:=$(call exists_in_list,$(type),$(debug_types))

# Finds all built *.exe files for cleaning
executables := $(shell find $(sourcedir) -name '*.exe')

.PHONY: all install debug release clean new

all: %.exe

configure: $(build_path)/Makefile

%.exe: $(build_path)/Makefile
	cmake --build $(build_path) -- -j$(cores)

$(build_path)/Makefile: CMakeLists.txt
	cmake -S $(sourcedir) -B $(build_path)

install: all
	@cmake --install $(build_path)

debug:
	$(eval CMAKE_OPTS = -DCMAKE_BUILD_TYPE=Debug)

release:
	$(eval CMAKE_OPTS = -DCMAKE_BUILD_TYPE=Release)

clean:
	@cmake --build $(build_path) --target clean
	rm -rf $(executables)

new: clean
	rm -rf $(build_path)
