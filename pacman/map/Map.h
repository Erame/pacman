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
  std::pair<int, int> _entrance, _exit;

public:
  utils::Block &operator()(int i, int j);
  const utils::Block &operator()(int i, int j) const;

  Map() = delete;
  Map(int height, int width);

  void print() const;
};

} // namespace map
} // namespace pacman