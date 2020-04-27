cmake_minimum_required(VERSION 3.0)

# build specs

project(pacman 
    VERSION 1.0 
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# source files, links, and includes

file(GLOB_RECURSE pacman_src
    "pacman/*.cpp"
    "pacman/*.hpp"
    "pacman/*.h"
)
list(REMOVE_ITEM pacman_src "pacman/main.cpp")

# build pacman lib

add_library(pacman_lib ${pacman_src})
set_target_properties(pacman_lib PROPERTIES
    OUTPUT_NAME "pacman")
target_include_directories(pacman_lib PUBLIC ${PROJECT_BINARY_DIR})

# build pacman exe (link to libpacman)

add_executable(pacman_exe
    ${CMAKE_SOURCE_DIR}/pacman/main.cpp)
set_target_properties(pacman_exe PROPERTIES
    OUTPUT_NAME "pacman")
target_link_libraries(pacman_exe pacman_lib)

configure_file(pacman/config.h.in config.h)
target_include_directories(pacman_exe 
    PUBLIC "${PROJECT_BINARY_DIR}")

# build tests

enable_testing()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/googletest)

file(GLOB test_srcs ${CMAKE_SOURCE_DIR}/tests/*.cpp)

foreach(test_src ${test_srcs})
    get_filename_component(test_name ${test_src} NAME_WE)
    add_executable(${test_name} ${test_src})
    target_link_libraries(${test_name} gtest_main pacman_lib)
    target_include_directories(${test_name} PUBLIC ${CMAKE_SOURCE_DIR}/pacman)
    set_target_properties(${test_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests)
    add_test(NAME ${test_name}_test COMMAND ${test_name})
endforeach()