#include "Map.h"

namespace pacman {
namespace map {

Map::Map(int height, int width) : _height(height), _width(width) {
  std::shared_ptr<MapGenerator> map_gen =
      std::make_shared<MapGenDFS>(height, width);
  _map = map_gen->generate();
}

void Map::print() const {
  for (const auto &v : _map) {
    for (size_t i = 0; i < v.size(); i++) {
      std::cout << v[i] << " ";
    }
    std::cout << std::endl;
  }
}

utils::Block &Map::operator()(int i, int j) { return _map[i][j]; }

const utils::Block &Map::operator()(int i, int j) const { return _map[i][j]; }

} // namespace map
} // namespace pacman