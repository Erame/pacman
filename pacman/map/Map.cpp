#include "Map.h"

namespace pacman {
namespace map {

using Block = pacman::utils::Block;

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
  std::cout << std::endl;
}

void Map::clear() {
  for (int i = 0; i < _height; i++) {
    for (int j = 0; j < _width; j++) {
      if (_map[i][j] == Block::path) {
        _map[i][j] = Block::empty;
      }
    }
  }
}

int Map::path_count() const {
  int res = 0;
  for (int i = 0; i < _height; i++) {
    for (int j = 0; j < _width; j++) {
      if (_map[i][j] == Block::path)
        res++;
    }
  }
  return res;
}

utils::Block &Map::operator()(int i, int j) { return _map[i][j]; }
const utils::Block &Map::operator()(int i, int j) const { return _map[i][j]; }

utils::Block &Map::operator()(const std::pair<int, int> &p) {
  return _map[p.first][p.second];
}
const utils::Block &Map::operator()(const std::pair<int, int> &p) const {
  return _map[p.first][p.second];
}

} // namespace map
} // namespace pacman