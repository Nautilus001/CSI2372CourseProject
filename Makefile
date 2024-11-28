# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

# Directories
SRC_DIR = src
BEANS_SRC_DIR = $(SRC_DIR)/beans
INCLUDE_DIR = include
BEANS_INCLUDE_DIR = $(INCLUDE_DIR)/beans

# Output
BIN = main

# Find all source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(BEANS_SRC_DIR)/*.cpp)

# Generate object file names for each source file
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(BIN)

# Build the executable
$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule for compiling each source file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean target to remove object files and the executable
clean:
	rm -f $(OBJS) $(BIN)

# Phony targets (not associated with actual files)
.PHONY: all clean
