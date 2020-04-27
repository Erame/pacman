rmdir /s /q build
mkdir build
cd build
cmake ..
cmake --build .
.\Debug\pacman.exe
ctest -C Debug --output-on-failure
cd ..