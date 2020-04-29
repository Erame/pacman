#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "Block.h"
#include "MapGenDFS.h"

namespace pacman {

class Map {
  std::vector<std::vector<Block>> _map;
  size_t _height;
  size_t _width;

  void _init(const int height, const int width, const Block b = Block::wall);

public:
  Map() = delete;
  Map(int height, int width) {
    _init(height, width);

    std::shared_ptr<MapGenerator> map_gen =
        std::make_shared<MapGenDFS>(height, width);
    _map = map_gen->generate();
  }

  void print() const;
};

} // namespace pacman