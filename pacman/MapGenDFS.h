#pragma once

#include "MapGenerator.h"

namespace pacman {

struct MapGenDFS : public MapGenerator {
  std::vector<std::vector<Block>> generate() {
    return std::vector<std::vector<Block>>(
        _height, std::vector<Block>(_width, Block::wall));
  }

  MapGenDFS(int height, int width) : MapGenerator(height, width) {}
  MapGenDFS() = delete;
};

} // namespace pacman