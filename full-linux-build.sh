#!/bin/sh

set -e

rm -rf build/
mkdir -p build
cd build
cmake ..
cmake --build .
./pacman
ctest --output-on-failure
cd ..