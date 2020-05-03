#pragma once

#include "map/Map.h"

namespace pacman {
namespace pacman {

struct MazeSolver {
  map::Map &_map;

  virtual void solve() = 0;

  MazeSolver(map::Map &map) : _map(map) {}
  MazeSolver() = delete;
};

} // namespace pacman
} // namespace pacman