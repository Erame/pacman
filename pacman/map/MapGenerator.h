#pragma once

#include <vector>

#include "utils/Block.h"

namespace pacman {
namespace map {

struct MapGenerator {
  virtual std::vector<std::vector<utils::Block>> generate() = 0;

  const int _height;
  const int _width;
  MapGenerator(int height, int width) : _height(height), _width(width) {}
  MapGenerator() = delete;
};

} // namespace map
} // namespace pacman
