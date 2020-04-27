cmake_minimum_required(VERSION 3.0)

# build specs

project(pacman 
    VERSION 1.0 
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# build tests

enable_testing()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/googletest)

file(GLOB test_srcs ${CMAKE_SOURCE_DIR}/tests/*.cpp)

foreach(test_src ${test_srcs})
    get_filename_component(test_name ${test_src} NAME_WE)
    add_executable(${test_name} ${test_src})
    target_link_libraries(${test_name} gtest_main)
    set_target_properties(${test_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests)
    add_test(NAME ${test_name}_test COMMAND ${test_name})
endforeach()

# source files, links, and includes

file(GLOB_RECURSE pacman_cpp_src
    "pacman/*.cpp"
    "pacman/*.hpp"
    "pacman/*.h"
)

include_directories(${CMAKE_SOURCE_DIR}/pacman)

add_executable(pacman 
    ${pacman_cpp_src}
)

configure_file(pacman/config.h.in config.h)
target_include_directories(
    pacman PUBLIC 
    "${PROJECT_BINARY_DIR}"
)