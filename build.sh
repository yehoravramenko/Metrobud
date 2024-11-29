#!/bin/sh

# Variables
SOURCE_DIR="src"        # Directory containing C source files
OUTPUT_DIR="bin"        # Directory to store the output binary
EXECUTABLE_NAME="metrobud"   # Name of the final executable
EXT=".exe"

# Compiler settings
CC=gcc                  # Compiler
CFLAGS="-Wall -Wextra -Iinclude -Llib -g -std=c23"  # Compiler flags
LDFLAGS="-lglfw3dll -lopengl32 -lgdi32 bin/glad.dll"              # Linker flags

# Ensure output directory exists
mkdir -p $OUTPUT_DIR

# Find all .c files in the source directory
SOURCES=$(find $SOURCE_DIR -name "*.c")
echo $SOURCES

# Compile the project
echo "Compiling..."
if [ "$1" = "debug" ]; then
    echo "->Debug Configuration"
    $CC $CFLAGS $SOURCES -o $OUTPUT_DIR/$EXECUTABLE_NAME$EXT $LDFLAGS -DDEBUG -mconsole
elif [ "$1" = "glad" ]; then
    echo "->Building glad.dll"
    $CC -Iinclude glad/glad.c -shared -Os -s -o bin/glad.dll -DGLAD_GLAPI_EXPORT -DGLAD_GLAPI_EXPORT_BUILD
else
    echo "->Release Configuration"
    $CC $CFLAGS $SOURCES -o $OUTPUT_DIR/$EXECUTABLE_NAME$EXT $LDFLAGS -mwindows
fi

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