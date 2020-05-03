#include "MazeSolverDFS.h"

#include <stack>

namespace pacman {
namespace pacman {

using Block = utils::Block;
using Point = std::pair<int, int>;
using Vec1 = std::vector<Block>;
using Vec2 = std::vector<std::vector<Block>>;

bool MazeSolverDFS::is_walkable(const Point &point) {
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

void MazeSolverDFS::solve() {
  auto st = std::stack<Point>();
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
}

} // namespace pacman
} // namespace pacman