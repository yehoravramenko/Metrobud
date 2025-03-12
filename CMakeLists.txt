cmake_minimum_required(VERSION 3.20)

project(
  Metrobud 
  VERSION "0.0.1"
  LANGUAGES C CXX)

set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_GENERATOR_PLATFORM "x64")

link_directories("vendor/lib")

add_definitions(-DGLFW_INCLUDE_NONE)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
        # Release-specific settings
        message(STATUS "Configuring for Release build")
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG") # Optimize and disable assertions
        set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/Release")
else()
        # Debug-specific settings
        message(STATUS "Configuring for Debug build")
        add_definitions(-DDEBUG) # Example: Define a DEBUG_MODE macro
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic") # Add extra warnings
        set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/Debug")
endif()

add_subdirectory(src/AuraEngine)
add_subdirectory(src/Metrobud)