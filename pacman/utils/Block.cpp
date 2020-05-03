#include "Block.h"

std::ostream &operator<<(std::ostream &os, const pacman::Block b) {
  switch (b) {
  case pacman::Block::wall:
    os << "\u25A0";
    break;
  case pacman::Block::empty:
    os << "\u25A1";
    break;
  default:
    break;
  }
  return os;
}