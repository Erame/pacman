#include "Block.h"

using Block = pacman::utils::Block;

std::ostream &operator<<(std::ostream &os, const Block b) {
  switch (b) {
  case Block::wall:
    os << "\u25A0";
    break;
  case Block::empty:
    os << "\u25A1";
    break;
  default:
    break;
  }
  return os;
}