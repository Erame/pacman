#include "RNG.h"

namespace pacman {

RNG::RNG() {
  if (!_initialized) {
    _seed = _rd();
  }
  _engine = Engine(_seed);

  _initialized = true;
}

void RNG::manual_seed(unsigned int seed) {
  _seed = seed;
  _initialized = true;
}

const RNG &RNG::get() {
  static RNG instance;
  return instance;
}

RNG::Engine &RNG::get_engine() {
  if (!_initialized) {
    get();
  }
  return _engine;
}

double RNG::frand() const {
  static auto _gen = std::uniform_real_distribution<double>();
  return _gen(_engine);
}

int RNG::randint(int low, int high) const {
  static auto _gen = std::uniform_int_distribution<int>(low, high);
  return _gen(_engine);
}

} // namespace pacman