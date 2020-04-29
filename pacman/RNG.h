#pragma once

// RNG singleton

namespace pacman {

class RNG {
public:
  static const RNG &get();
  static void manual_seed(unsigned int seed);

  double frand() const;
  int randint(int low, int high) const;

private:
  inline static unsigned int _seed;
  inline static bool initialized = false;

  RNG();

public:
  RNG(const RNG &) = delete;
  RNG(RNG &&) = delete;
  void operator=(const RNG &) = delete;
  void operator=(RNG &&) = delete;
};

} // namespace pacman