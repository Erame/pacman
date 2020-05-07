#include "MazeSolverDijkstra.h"

#include <queue>

namespace pacman {
namespace pacman {

using Block = utils::Block;
using Point = std::pair<int, int>;
using Vec1 = std::vector<Block>;
using Vec2 = std::vector<std::vector<Block>>;

map::Map *p_map = nullptr;

struct PointComparer {
  PointComparer() {
    if (p_map == nullptr) {
      throw std::logic_error("map pointer p_map is not set!");
    }
  }

  bool operator()(const Point &lhs, const Point &rhs) const {
    auto dist = [](const Point &a, const Point &b) -> int {
      return abs(a.first - b.first) + abs(a.second - b.second);
    };

    int d1 = dist(lhs, p_map->entrance()) - 3 * dist(lhs, p_map->exit());
    int d2 = dist(rhs, p_map->entrance()) - 3 * dist(rhs, p_map->exit());

    return d1 < d2;
  }
};

bool MazeSolverDijkstra::is_walkable(const Point &point) {
  int i = point.first;
  int j = point.second;

  if (i < 0 || j < 0 || i >= _map.height() || j >= _map.width()) {
    return false;
  }

  const auto &block = _map(point);

  if (block == Block::entrance || block == Block::empty ||
      block == Block::exit) {
    return true;
  }

  return false;
}

void MazeSolverDijkstra::solve() {
  p_map = &_map;

  auto st = std::priority_queue<Point, std::vector<Point>, PointComparer>();
  st.push(_map.entrance());

  while (!st.empty()) {
    auto top = st.top();
    st.pop();

    if (top == _map.exit()) {
      return;
    }

    if (top != _map.entrance()) {
      if (is_walkable(top)) {
        _map(top) = Block::path;
      } else {
        continue;
      }
    }

    int i = top.first;
    int j = top.second;

    for (const auto &dir : dirs) {
      int inext = i + dir.first;
      int jnext = j + dir.second;

      st.push({inext, jnext});
    }
  }

  p_map = nullptr;
}

} // namespace pacman
} // namespace pacman