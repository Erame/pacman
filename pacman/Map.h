#pragma once

#include <vector>

#include "Block.h"

namespace pacman {

class Map {
  std::vector<std::vector<Block>> _map;
  size_t _height;
  size_t _width;

  void _init(int height, int width);

public:
  Map() = delete;
  Map(int height, int width) { _init(height, width); }
};

} // namespace pacman