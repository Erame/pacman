#pragma once

#include <iostream>

namespace pacman {
namespace utils {

enum Block { wall, empty, entrance, exit, path };

} // namespace utils
} // namespace pacman

std::ostream &operator<<(std::ostream &os, const pacman::utils::Block b);