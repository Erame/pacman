#include <iostream>

#include "config.h"

int main() {
    printf("hello world\n");

    std::cout << "versions " << std::endl
              << "major " << VERSION_MAJOR << std::endl
              << "minor " << VERSION_MINOR << std::endl;

    return 0;
}