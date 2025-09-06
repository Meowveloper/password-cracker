# Compiler to use
CC = gcc


# Compiler flags:
#	- Wall => Turn on all warnings
#	- -g => Add debugging information
CFLAGS = -Wall -g -Isrc/dictionary_attack -Isrc/utils

LDFLAGS = -lcrypto


# The name of the executable to create
TARGET = password-cracker

# The source files
SRCS = src/main.c src/dictionary_attack/dictionary_attack.c src/utils/utils.c


# Default target, executed when just run 'make'
all: $(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) $(LDFLAGS)

# Target to clean up the project directory
clean: 
	rm -f $(TARGET)