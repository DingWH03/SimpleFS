# Makefile for SimpleFS Project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = 

# Directories
SRC_DIR = src
INC_DIR = include
TEST_DIR = tests
BUILD_DIR = build
TOOLS_DIR = tools

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
TOOL_SRCS = $(wildcard $(TOOLS_DIR)/*.c)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
TOOL_OBJS = $(patsubst $(TOOLS_DIR)/%.c, $(BUILD_DIR)/%.o, $(TOOL_SRCS))
TEST_OBJS = $(patsubst $(TEST_DIR)/%.c, $(BUILD_DIR)/%.o, $(TEST_SRCS))

# Executable names
EXEC = SimpleFS
TOOLS = mkfs_SimpleFS dump_tool
TEST_EXEC = test_SimpleFS

# Default rule
all: $(EXEC) $(TOOLS)

# Main executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Tools executables
$(TOOLS): $(TOOL_OBJS) $(OBJS)
	$(CC) $(CFLAGS) -o $(TOOLS_DIR)/mkfs_SimpleFS $(BUILD_DIR)/mkfs_SimpleFS.o $(OBJS) $(LDFLAGS)
	$(CC) $(CFLAGS) -o $(TOOLS_DIR)/dump_tool $(BUILD_DIR)/dump_tool.o $(OBJS) $(LDFLAGS)

# Test executable
$(TEST_EXEC): $(TEST_OBJS) $(OBJS)
	$(CC) $(CFLAGS) -o $(TEST_EXEC) $^ $(LDFLAGS)

# Build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(BUILD_DIR)/%.o: $(TOOLS_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up build files
clean:
	rm -rf $(BUILD_DIR) $(EXEC) $(TOOLS_DIR)/$(TOOLS) $(TEST_EXEC)

# Run tests
test: $(TEST_EXEC)
	./$(TEST_EXEC)

.PHONY: all clean test
