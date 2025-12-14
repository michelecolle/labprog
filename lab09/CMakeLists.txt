cmake_minimum_required(VERSION 3.10)
project(lab09 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-fno-elide-constructors)

add_library(lab09 INTERFACE)

target_include_directories(lab09 INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

add_executable(main
    src/main.cpp
    src/InertialDriver.cpp
    src/Lettura.cpp
)

target_link_libraries(main PRIVATE lab09)
