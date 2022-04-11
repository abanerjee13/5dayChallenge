# Makefile
# Build rules for EECS 280 project 2

# Compiler
CXX ?= g++

# Compiler flags
CXXFLAGS ?= --std=c++11 -Wall -Werror -pedantic -g

LinkedListBasics.exe: LinkedListBasics.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
