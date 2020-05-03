#include <iostream>

#include "config.h"

#include "Map.h"
#include "RNG.h"

int main() {
  printf("hello world\n");

  std::cout << "versions " << std::endl
            << "major " << VERSION_MAJOR << std::endl
            << "minor " << VERSION_MINOR << std::endl;

  pacman::RNG::manual_seed(42);

  auto map = pacman::Map(50, 50);
  map.print();

  auto &rng = pacman::RNG::get();
  std::cout << rng.frand() << std::endl;

  return 0;
}