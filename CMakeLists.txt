cmake_minimum_required(VERSION 3.0)

# build specs

project(pacman 
    VERSION 1.0 
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# source files

file(GLOB_RECURSE pacman_cpp_src
    "pacman/*.cpp"
    "pacman/*.hpp"
    "pacman/*.h"
)

configure_file(pacman/config.h.in config.h)

# links and includes

include_directories(${CMAKE_SOURCE_DIR})

add_executable(pacman 
    ${pacman_cpp_src}
)

target_include_directories(
    pacman PUBLIC 
    "${PROJECT_BINARY_DIR}"
)