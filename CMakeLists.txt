# Set the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Define the main project name and enable C++ language support (which selects g++ by default)
project(MultiExecutableProject LANGUAGES CXX)

# Specify the C++ standard to use (e.g., C++17)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-fno-elide-constructors)

# We are no longer using the 'src' folder directly. Instead, we use subdirectories
# for each independent application/assignment.

# Add the first sub-project (e.g., Homework 1)
# This command tells CMake to look inside the '01HW' directory for another CMakeLists.txt
#add_subdirectory(01HW)

# Add the second sub-project (e.g., Classes Assignment)
# This command tells CMake to look inside the '02Classes' directory for another CMakeLists.txt
add_subdirectory(02_oggetti_espressioni_istruzioni) 
add_subdirectory(04_funzioni)
add_subdirectory(08_interfacce_const_ecc)

# Add all subdirectories starting with 'lab'
file(GLOB LAB_SUBDIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "lab*")
foreach(LAB_DIR ${LAB_SUBDIRS})
    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${LAB_DIR})
        add_subdirectory(${LAB_DIR})
    endif()
endforeach()

# NOTE: The output directory setting for individual executables has been removed
# and will now be handled inside the respective sub-project CMakeLists.txt files
# or the executables will go to the default location (e.g., build/01HW and build/02Classes).
