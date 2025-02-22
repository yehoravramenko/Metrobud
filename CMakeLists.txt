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

# add_subdirectory(vendor/glfw)

add_subdirectory(src)