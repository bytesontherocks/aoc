#include <gtest/gtest.h>
#include "measurements.hpp"

std::vector<size_t>v = {16,1,2,0,4,2,7,1,2,14};


TEST(measurementsTest, firstExercice)
{
  EXPECT_EQ(measurements::calculateFirstExercice(v), 37);
}


TEST(measurementsTest, secondExercice)
{
  EXPECT_EQ(measurements::calculateSecondExercice(v), 168);
}

