#include "gtest/gtest.h"

#include "Map.h"

TEST(test_map, print) {
    auto map = pacman::Map(3, 5);
    map.print();
}