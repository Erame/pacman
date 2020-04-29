#include "gtest/gtest.h"

#include "Map.h"

TEST(map, print) {
  ASSERT_NO_THROW({
    auto map = pacman::Map(3, 5);
    map.print();
  });
}