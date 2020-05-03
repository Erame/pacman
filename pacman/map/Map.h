#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "MapGenDFS.h"
#include "utils/Block.h"

namespace pacman {

class Map {
  std::vector<std::vector<Block>> _map;
  const size_t _height;
  const size_t _width;

public:
  Map() = delete;
  Map(int height, int width);

  void print() const;
};

} // namespace pacman