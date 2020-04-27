#include "Block.h"

std::ostream &operator<<(std::ostream &os, const pacman::Block b) {
  switch (b) {
  case pacman::Block::wall:
    os << '@';
    break;
  case pacman::Block::empty:
    os << ' ';
    break;
  default:
    break;
  }
  return os;
}