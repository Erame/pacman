#include <iostream>

#include "config.h"

#include "map/Map.h"
#include "utils/RNG.h"

int main() {
  printf("hello world\n");

  std::cout << "versions " << std::endl
            << "major " << VERSION_MAJOR << std::endl
            << "minor " << VERSION_MINOR << std::endl;

  // pacman::utils::RNG::manual_seed(42);

  auto map = pacman::map::Map(20, 20);
  map.print();

  auto &rng = pacman::utils::RNG::get();
  std::cout << rng.frand() << std::endl;

  return 0;
}