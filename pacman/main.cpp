#include <iostream>

#include "config.h"

#include "map/Map.h"
#include "utils/RNG.h"

int main() {
  printf("hello world\n");

  std::cout << "versions " << std::endl
            << "major " << VERSION_MAJOR << std::endl
            << "minor " << VERSION_MINOR << std::endl;

  pacman::utils::RNG::manual_seed(42);

  auto map = pacman::map::Map(50, 50);
  map(0, 0) = pacman::utils::Block::path;
  map(0, 1) = pacman::utils::Block::path;
  map.print();

  auto &rng = pacman::utils::RNG::get();
  std::cout << rng.frand() << std::endl;

  return 0;
}