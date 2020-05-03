#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "MapGenDFS.h"
#include "utils/Block.h"

namespace pacman {
namespace map {

class Map {
  std::vector<std::vector<utils::Block>> _map;
  const size_t _height;
  const size_t _width;

public:
  Map() = delete;
  Map(int height, int width);

  void print() const;
};

} // namespace map
} // namespace pacman