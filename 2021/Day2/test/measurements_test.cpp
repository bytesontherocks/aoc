#include <gtest/gtest.h>
#include "measurements.hpp"

const std::vector<std::pair<direction, int32_t>> v_test =
{
    {direction::forward, 5},
    {direction::down, 5},
    {direction::forward, 8},
    {direction::up, 3},
    {direction::down,8},
    {direction::forward,2},
};

TEST(measurementsTest, firstExercice)
{

  EXPECT_EQ(measurements::calculatePosition(v_test), 150);
}

TEST(measurementsTest, secondExercice)
{

  EXPECT_EQ(measurements::calculatePositionWithAim(v_test), 900);
}