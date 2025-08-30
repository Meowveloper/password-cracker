# Compiler to use
CC = gcc


# Compiler flags:
#	- Wall => Turn on all warnings
#	- -g => Add debugging information
CFLAGS = -Wall -g


# The name of the executable to create
TARGET = password-cracker

# The source files
SRCS = src/main.c src/dictionary_attack.c


# Default target, executed when just run 'make'
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Target to clean up the project directory
clean: 
	rm -f $(TARGET)