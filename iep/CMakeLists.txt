# CMake version
cmake_minimum_required(VERSION 3.0)

set(projectName "Project")
#Project name
project(${projectName})

# Define the search path for header files
#include_directories(inc)

# Specify the required C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Define the executable
add_executable(${PROJECT_NAME}
               src/Vehicul.cpp
               src/Vehicul1.cpp
               src/Vehicul3.cpp
               src/Masina.cpp
               src/main.cpp)
