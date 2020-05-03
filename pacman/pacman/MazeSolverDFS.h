#pragma once

#include "MazeSolver.h"

namespace pacman {
namespace pacman {

struct MazeSolverDFS : public MazeSolver {
  void solve() override;

  MazeSolverDFS(map::Map &map) : MazeSolver(map) {}
  MazeSolverDFS() = delete;
};

} // namespace pacman
} // namespace pacman