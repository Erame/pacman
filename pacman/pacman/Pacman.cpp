#include "Pacman.h"
#include "MazeSolverDFS.h"

namespace pacman {
namespace pacman {

Pacman::Pacman(map::Map &map) : _map(map) {
  _solver = std::make_shared<MazeSolverDFS>(_map);
}

void Pacman::solve() { _solver->solve(); }

} // namespace pacman
} // namespace pacman