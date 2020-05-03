#pragma once

#include "map/Map.h"

namespace pacman {
namespace pacman {

class Pacman {
  map::Map &_map;

public:
  Pacman(map::Map &map) : _map(map) {}
  Pacman() = delete;
};

} // namespace pacman
} // namespace pacman