#include "gtest/gtest.h"

#include <memory>

#include "map/MapGenDFS.h"

TEST(mapgen, generate) {
  int height = 5;
  int width = 7;

  std::shared_ptr<pacman::map::MapGenerator> a =
      std::make_shared<pacman::map::MapGenDFS>(height, width);

  std::pair<int, int> entrance, exit;
  std::vector<std::vector<pacman::utils::Block>> b;

  std::tie(b, entrance, exit) = a->generate();
  ASSERT_EQ(b.size(), height);
  ASSERT_EQ(b[0].size(), width);

  ASSERT_TRUE(entrance.first == 0 || entrance.second == 0);
  ASSERT_TRUE(exit.first == height - 1 || exit.second == width - 1);
}