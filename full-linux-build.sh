#!/bin/sh

set -e

python clang-format.py -r pacman/ tests/
rm -rf build/
mkdir -p build
cd build
cmake ..
cmake --build .
./pacman
ctest --output-on-failure
cd ..