#include "Map.h"

namespace pacman {
namespace map {

Map::Map(int height, int width) : _height(height), _width(width) {
  std::shared_ptr<MapGenerator> map_gen =
      std::make_shared<MapGenDFS>(height, width);
  std::tie(_map, _entrance, _exit) = map_gen->generate();
}

void Map::print() const {
  for (const auto &v : _map) {
    for (size_t i = 0; i < v.size(); i++) {
      std::cout << v[i] << " ";
    }
    std::cout << std::endl;
  }
}

inline utils::Block &Map::operator()(int i, int j) { return _map[i][j]; }
inline const utils::Block &Map::operator()(int i, int j) const {
  return _map[i][j];
}

inline utils::Block &Map::operator()(const std::pair<int, int> &p) {
  return _map[p.first][p.second];
}
inline const utils::Block &Map::operator()(const std::pair<int, int> &p) const {
  return _map[p.first][p.second];
}

} // namespace map
} // namespace pacman