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

  utils::Block &operator()(const std::pair<int, int> &point);
  const utils::Block &operator()(const std::pair<int, int> &point) const;

  size_t height() const { return _height; }
  size_t width() const { return _width; }

  const std::pair<int, int> &entrance() { return _entrance; };
  const std::pair<int, int> &exit() { return _exit; };

  Map() = delete;
  Map(int height, int width);

  void print() const;
};

} // namespace map
} // namespace pacman