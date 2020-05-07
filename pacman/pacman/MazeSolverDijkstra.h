#pragma once

#include "MazeSolver.h"

namespace pacman {
namespace pacman {

struct MazeSolverDijkstra : public MazeSolver {
  std::vector<std::pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  void solve() override;

  bool is_walkable(const std::pair<int, int> &point);

  MazeSolverDijkstra(map::Map &map) : MazeSolver(map) {}
  MazeSolverDijkstra() = delete;
};

} // namespace pacman
} // namespace pacman