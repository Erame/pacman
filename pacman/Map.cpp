#include "Map.h"

namespace pacman {
void Map::_init(int height, int width) {
  _map = std::vector<std::vector<Block>>(
      height, std::vector<Block>(width, Block::empty));
  _height = height;
  _width = width;
}
} // namespace pacman