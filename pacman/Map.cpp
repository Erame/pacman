#include "Map.h"

namespace pacman {
void Map::_init(const int height, const int width, const Block b) {
  _map = std::vector<std::vector<Block>>(height, std::vector<Block>(width, b));
  _height = height;
  _width = width;
}

void Map::print() const {
  for (const auto &v : _map) {
    for (size_t i = 0; i < v.size(); i++) {
      std::cout << v[i];
    }
    std::cout << std::endl;
  }
}
} // namespace pacman