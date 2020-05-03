#include <algorithm>
#include <random>
#include <stack>
#include <utility>

#include "MapGenDFS.h"
#include "utils/RNG.h"

namespace pacman {

using Point = std::pair<int, int>;
using Vec1 = std::vector<Block>;
using Vec2 = std::vector<std::vector<Block>>;

inline bool MapGenDFS::is_breakable(const Point &point) {
  int i = point.first;
  int j = point.second;

  if (!found_exit && (i == _height - 1 || j == _width - 1)) {
    found_exit = true;
    return true;
  }
  if (i <= 0 || j <= 0 || i >= _height - 1 || j >= _width - 1)
    return false;
  if (_map[i][j] == Block::empty)
    return false;

  int a = (_map[i - 1][j] == Block::wall) + (_map[i + 1][j] == Block::wall) +
          (_map[i][j - 1] == Block::wall) + (_map[i][j + 1] == Block::wall);

  return a > 2;
}

Vec2 MapGenDFS::generate() {
  found_exit = false;
  _map = Vec2(_height, Vec1(_width, Block::wall));

  Point start = {0, 1};
  _map[start.first][start.second] = Block::empty;

  auto st = std::stack<Point>();
  st.push({start.first + 1, start.second});

  while (!st.empty()) {
    auto top = st.top();
    st.pop();

    int i = top.first;
    int j = top.second;

    if (is_breakable(top)) {
      _map[i][j] = Block::empty;
    } else {
      continue;
    }

    std::shuffle(dirs.begin(), dirs.end(), RNG::get_engine());

    for (const auto &dir : dirs) {
      int inext = i + dir.first;
      int jnext = j + dir.second;

      st.push({inext, jnext});
    }
  }

  return std::move(_map);
}

} // namespace pacman