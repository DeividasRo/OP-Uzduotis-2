cmake_minimum_required(VERSION 3.13)  # CMake version check
project(prog)
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

set(SOURCE_FILES src/main.cpp src/studentu_suvestine.cpp src/skaiciavimai.cpp)

add_executable(prog ${SOURCE_FILES})