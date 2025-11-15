cmake_minimum_required(VERSION 3.10)
project(lab04 LANGUAGES CXX)



include_directories(${PROJECT_SOURCE_DIR}/include)



file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

add_executable(lab05 lab05.cpp ${sources} ${headers})
