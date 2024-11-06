# Makefile to (1) compile and (2) clean
#  - Rule for compilation should create solution.exe
#     - Should only recompile code when any source code changed
#  - Rule for clean should remove solution.exe
#     - Should not show error if the file does not exist
#  - Use GCC compiler toolchain
#  - Specify the following options:
#     - Disable optimization
#     - Disable generation of debug information
#     - Enable all general warnings
#     - Enable conversion warnings

# Compiler and flags
CC = gcc
CFLAGS = -O0 -w -Wall -Wconversion

# Target executable
TARGET = solution.exe

# Source files
SRCS = solution.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default rule to compile the target
all: $(TARGET)

# Rule to create the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean the build
clean:
	@rm -f $(TARGET) $(OBJS)

# Phony targets
.PHONY: all clean