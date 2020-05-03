#pragma once

#include <iostream>

namespace pacman {
enum Block { wall, empty, entrance, exit };
}

std::ostream &operator<<(std::ostream &os, const pacman::Block b);