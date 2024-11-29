#!/bin/sh

# Variables
SOURCE_DIR="src"        # Directory containing C source files
OUTPUT_DIR="bin"        # Directory to store the output binary
EXECUTABLE_NAME="metrobud"   # Name of the final executable
EXT=".exe"

# Compiler settings
CC=gcc                  # Compiler
CFLAGS="-Wall -Wextra -Iinclude -Llib -g"  # Compiler flags
LDFLAGS="-lglfw3dll -lopengl32 -lgdi32"              # Linker flags

# Ensure output directory exists
mkdir -p $OUTPUT_DIR

# Find all .c files in the source directory
SOURCES=$(find $SOURCE_DIR -name "*.c")

# Compile the project
echo "Compiling..."
$CC $CFLAGS $SOURCES -o $OUTPUT_DIR/$EXECUTABLE_NAME$EXT $LDFLAGS

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Build failed!"
    exit 1  
fi

echo "Build successful! Executable: $OUTPUT_DIR/$EXECUTABLE_NAME$EXT | [R]un?"
read -r run_command
if [ "$run_command" = "r" ]; then
    ./$OUTPUT_DIR/$EXECUTABLE_NAME$EXT
fi