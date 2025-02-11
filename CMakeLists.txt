# Minimum CMake version
cmake_minimum_required(VERSION 3.20)

# Define the project
project(Metrobud VERSION 1.0.0 LANGUAGES CXX C)

# Set C++ standard for all projects
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directories to match premake structure
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})

# Define platform-specific variables (matching your premake defines)
if(WIN32)
    add_compile_definitions(AE_PLATFORM_WINDOWS)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif()

# Add configuration-specific definitions
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(AE_DEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_definitions(AE_RELEASE)
endif()

# Add subdirectories for each project
add_subdirectory(AuraEngine)
add_subdirectory(Metrobud)