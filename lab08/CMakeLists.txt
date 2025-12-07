cmake_minimum_required(VERSION 3.10)
project(lab08
 LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${PROJECT_SOURCE_DIR}/include)



file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.c*)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.h*)

add_executable(lab08 main.cpp ${sources} ${headers})
configure_file(${PROJECT_SOURCE_DIR}/input.txt ${CMAKE_CURRENT_BINARY_DIR}/input.txt COPYONLY)