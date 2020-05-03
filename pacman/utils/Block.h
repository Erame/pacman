#pragma once

#include <iostream>

namespace pacman {
namespace utils {

enum Block { wall, empty, entrance, exit };

} // namespace utils
} // namespace pacman

std::ostream &operator<<(std::ostream &os, const pacman::utils::Block b);