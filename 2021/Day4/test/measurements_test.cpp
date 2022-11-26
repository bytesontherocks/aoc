#include <gtest/gtest.h>
#include "measurements.hpp"


TEST(measurementsTest, firstExercice)
{
  std::ifstream input_file;
  input_file.open("/home/aos_dev/source/repos/aoc/Day4/test/input_test", std::ios::out);

  EXPECT_EQ(measurements::calculateFirstExercice(input_file), 4512);
}


TEST(measurementsTest, secondExercice)
{
  std::ifstream input_file;
  input_file.open("/home/aos_dev/source/repos/aoc/Day4/test/input_test", std::ios::out);

  EXPECT_EQ(measurements::calculateSecondExercice(input_file), 1924);
}

