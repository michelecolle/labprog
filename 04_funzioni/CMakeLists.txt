# Minimum required version for CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(HelloWorld_Project LANGUAGES CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_SOURCE_DIR}/04_funzioni/build
)
# Create an executable named 'run' from the source file 'ex02.cpp'
add_executable(ex04 ex04.cpp)