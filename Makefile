builddir := .build
sourcedir := .

.PHONY: all clean debug release

CC = gcc
CMAKE_CXX_COMPILER := g++
CMAKE_OPTS =

all:
	@cmake -S $(sourcedir) -B $(builddir) $(CMAKE_OPTS)
	@cmake --build $(builddir)

debug:
	$(eval CMAKE_OPTS = -DCMAKE_BUILD_TYPE=Debug)

release:
	$(eval CMAKE_OPTS = -DCMAKE_BUILD_TYPE=Release)

clean:
	rm -rf $(builddir)
