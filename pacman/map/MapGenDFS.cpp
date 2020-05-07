#include <algorithm>
#include <random>
#include <stack>
#include <tuple>
#include <utility>

#include "MapGenDFS.h"
#include "utils/RNG.h"

namespace pacman {
namespace map {

using Block = utils::Block;
using Point = std::pair<int, int>;
using Vec1 = std::vector<Block>;
using Vec2 = std::vector<std::vector<Block>>;

bool MapGenDFS::is_breakable(const Point &point) {
  int i = point.first;
  int j = point.second;

  if (!found_exit && j == _width - 1) {
    found_exit = true;
    _exit = {i, j};
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

std::tuple<std::vector<std::vector<utils::Block>>, std::pair<int, int>,
           std::pair<int, int>>
MapGenDFS::generate() {
  found_exit = false;
  _map = Vec2(_height, Vec1(_width, Block::wall));

  _entrance = {0, 1};

  Point start = _entrance;
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

    std::shuffle(dirs.begin(), dirs.end(), utils::RNG::get_engine());

    for (const auto &dir : dirs) {
      int inext = i + dir.first;
      int jnext = j + dir.second;

      st.push({inext, jnext});
    }
  }

  _map[_entrance.first][_entrance.second] = Block::entrance;
  _map[_exit.first][_exit.second] = Block::exit;
  return std::make_tuple(std::move(_map), _entrance, _exit);
}

} // namespace map
} // namespace pacman