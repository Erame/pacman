#pragma once

#include "MazeSolver.h"

namespace pacman {
namespace pacman {

struct MazeSolverDFS : public MazeSolver {
  std::vector<std::pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  void solve() override;

  bool is_walkable(const std::pair<int, int> &point);

  MazeSolverDFS(map::Map &map) : MazeSolver(map) {}
  MazeSolverDFS() = delete;
};

} // namespace pacman
} // namespace pacman