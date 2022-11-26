#include <gtest/gtest.h>
#include "measurements.hpp"

std::vector<size_t>v = {3,4,3,1,2};


TEST(measurementsTest, firstExercice)
{
  EXPECT_EQ(measurements::calculateFirstExercice(v, 18), 26);
  EXPECT_EQ(measurements::calculateFirstExercice(v, 80), 5934);
}


TEST(measurementsTest, secondExercice)
{
  EXPECT_EQ(measurements::calculateSecondExercice(v, 256), (uint64_t)26984457539);
}

