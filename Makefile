# Define directories
SRC_DIR := src
HEADER_DIR := header

# Source and header files
SOURCE_FILES := $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)/*.c))
HEADERS := $(wildcard $(HEADER_DIR)/*.h)

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -I$(HEADER_DIR)

# Output executable
OUTPUT := stree

# Default target
all: build

# Compilation rule
build: $(SRC_DIR)/main.c $(SOURCE_FILES) $(HEADERS)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(SRC_DIR)/main.c $(SOURCE_FILES)

# Run program
run: build
	./$(OUTPUT)

# Cleanup rule
clean:
	rm -rf $(OUTPUT) rezultat_valgrind.txt 

# Check using checker script
check: build
	./checker.sh
