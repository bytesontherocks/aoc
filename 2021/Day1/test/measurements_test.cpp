#include <gtest/gtest.h>
#include "measurements.hpp"

const std::vector<uint32_t> v { 199, 200, 208, 210, 200, 207, 240, 269, 260, 263};

TEST(measurementsTest, increaseTable) {

  EXPECT_EQ(measurements::getNumberOfIncreases(v), 7);
}

TEST(measurementsTest, increaseWindow) {

  EXPECT_EQ(measurements::getNumberOfIncreasesWindow(v), 5);
}