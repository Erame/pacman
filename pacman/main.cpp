#include <iostream>

#include "config.h"

#include "Map.h"

int main() {
  printf("hello world\n");

  std::cout << "versions " << std::endl
            << "major " << VERSION_MAJOR << std::endl
            << "minor " << VERSION_MINOR << std::endl;

  auto map = pacman::Map(3, 5);
  map.print();

  return 0;
}