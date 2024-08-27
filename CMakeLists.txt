cmake_minimum_required(VERSION 3.10)

# Project name and version
project(ParaFetch VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
set(SOURCE_FILES
    src/main.cpp
)

# Create the executable
add_executable(ParaFetch ${SOURCE_FILES})
