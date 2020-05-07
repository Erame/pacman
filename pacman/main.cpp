#include <iostream>

#include "config.h"

#include "map/Map.h"
#include "pacman/Pacman.h"
#include "utils/RNG.h"

int main() {
  printf("hello world\n");

  std::cout << "versions " << std::endl
            << "major " << VERSION_MAJOR << std::endl
            << "minor " << VERSION_MINOR << std::endl;

  pacman::utils::RNG::manual_seed(42);

  auto &rng = pacman::utils::RNG::get();
  std::cout << rng.frand() << std::endl;

  auto map = pacman::map::Map(40, 100);
  // map.print();

  auto pm = pacman::pacman::Pacman(map, pacman::pacman::MazeSolverAlgs::DFS);
  pm.solve();
  std::cout << map.path_count() << std::endl;
  map.print();

  auto pm1 =
      pacman::pacman::Pacman(map, pacman::pacman::MazeSolverAlgs::Dijkstra);
  pm1.solve();
  std::cout << map.path_count() << std::endl;
  map.print();

  return 0;
}