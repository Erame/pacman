#include "Pacman.h"
#include "MazeSolverDFS.h"
#include "MazeSolverDijkstra.h"

namespace pacman {
namespace pacman {

Pacman::Pacman(map::Map &map, MazeSolverAlgs alg) : _map(map), _alg(alg) {
  switch (alg) {
  case MazeSolverAlgs::DFS:
    _solver = std::make_shared<MazeSolverDFS>(_map);
    break;
  case MazeSolverAlgs::Dijkstra:
    _solver = std::make_shared<MazeSolverDijkstra>(_map);
    break;
  }
}

void Pacman::solve() {
  _map.clear();
  _solver->solve();
}

} // namespace pacman
} // namespace pacman