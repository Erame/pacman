cmake_minimum_required(VERSION 3.0)

project(pacman VERSION 1.0)

configure_file(pacman/config.h.in config.h)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(pacman pacman/main.cpp)

target_include_directories(
    pacman PUBLIC 
    "${PROJECT_BINARY_DIR}"
)