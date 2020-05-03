#pragma once

#include "MapGenerator.h"

namespace pacman {

struct MapGenDFS : public MapGenerator {
  std::vector<std::pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  std::vector<std::vector<Block>> _map;
  bool found_exit = false;

  inline bool is_breakable(const std::pair<int, int> &point);

  std::vector<std::vector<Block>> generate();

  MapGenDFS(int height, int width) : MapGenerator(height, width) {}
  MapGenDFS() = delete;
};

} // namespace pacman