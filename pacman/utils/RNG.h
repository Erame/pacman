#pragma once

#include <random>

// RNG singleton

namespace pacman {

class RNG {
  using Engine = std::mt19937_64;

public:
  static const RNG &get();
  static void manual_seed(unsigned int seed);
  static Engine &get_engine();

  double frand() const;
  int randint(int low, int high) const;

private:
  inline static uint64_t _seed;
  inline static bool _initialized = false;
  inline static std::random_device _rd = std::random_device();
  inline static Engine _engine = Engine(0);

  RNG();

public:
  RNG(const RNG &) = delete;
  RNG(RNG &&) = delete;
  void operator=(const RNG &) = delete;
  void operator=(RNG &&) = delete;
};

} // namespace pacman