#include "gtest/gtest.h"

#include <memory>

#include "map/MapGenDFS.h"

TEST(mapgen, generate) {
  std::shared_ptr<pacman::map::MapGenerator> a =
      std::make_shared<pacman::map::MapGenDFS>(3, 5);
  auto b = a->generate();
  ASSERT_EQ(b.size(), 3);
  ASSERT_EQ(b[0].size(), 5);
}