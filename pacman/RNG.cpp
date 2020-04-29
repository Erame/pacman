#include <cstdlib>
#include <ctime>

#include "RNG.h"

#define _frand() ((double)rand() / (double)(RAND_MAX + 1.0))

namespace pacman {

RNG::RNG() {
  if (!initialized) {
    _seed = (unsigned int)time(nullptr);
  }
  srand(_seed);
  initialized = true;
}

void RNG::manual_seed(unsigned int seed) {
  _seed = seed;
  initialized = true;
}

const RNG &RNG::get() {
  static RNG instance;
  return instance;
}

double RNG::frand() const { return _frand(); }

int RNG::randint(int low, int high) const {
  return static_cast<int>(frand() * (high + 1 - low) + low);
}

} // namespace pacman