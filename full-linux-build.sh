#!/bin/bash

set -e

python clang-format.py -r pacman/ tests/

if [[ "$1" = '--full' ]]; then
    rm -rf build/
    mkdir -p build
    cd build
    cmake ..
    cd ..
fi

cd build/
cmake --build .
./pacman
ctest --output-on-failure
cd ..