# Minimum CMake version
cmake_minimum_required(VERSION 3.20)

# Define the project
project(Metrobud VERSION "0.0.1" LANGUAGES CXX C)

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

# Set up SDL3 paths
set(SDL3_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/thirdparty/include/SDL3")
set(SDL3_LIBRARY "${CMAKE_SOURCE_DIR}/thirdparty/lib/SDL3/SDL3.lib")

# Add the SDL3 library directory to the search path
link_directories(${CMAKE_SOURCE_DIR}/thirdparty/lib/SDL3)

# Create an imported target for SDL3
add_library(SDL3 SHARED IMPORTED)
set_target_properties(SDL3 PROPERTIES
        IMPORTED_IMPLIB "${SDL3_LIBRARY}"
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/thirdparty/lib/SDL3/SDL3.dll"
        INTERFACE_INCLUDE_DIRECTORIES "${SDL3_INCLUDE_DIR}"
)

# Add subdirectories for each project
add_subdirectory(AuraEngine)
add_subdirectory(Metrobud)