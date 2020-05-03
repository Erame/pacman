#pragma once

#include "MapGenerator.h"

namespace pacman {
namespace map {

struct MapGenDFS : public MapGenerator {
  std::vector<std::pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  std::vector<std::vector<utils::Block>> _map;
  bool found_exit = false;

  std::pair<int, int> _entrance;
  std::pair<int, int> _exit;

  inline bool is_breakable(const std::pair<int, int> &point);

  std::tuple<std::vector<std::vector<utils::Block>>, std::pair<int, int>,
             std::pair<int, int>>
  generate() override;

  MapGenDFS(int height, int width) : MapGenerator(height, width) {}
  MapGenDFS() = delete;
};

} // namespace map
} // namespace pacman