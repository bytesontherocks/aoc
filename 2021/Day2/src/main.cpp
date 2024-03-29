
#include "measurements.hpp"
#include <iostream>


namespace {

    std::vector<std::pair<direction, int32_t>> meas = 
    {
        {direction::forward,7},
        {direction::down,8},
        {direction::forward,5},
        {direction::down,3},
        {direction::forward,6},
        {direction::down,9},
        {direction::down,2},
        {direction::forward,1},
        {direction::down,2},
        {direction::down,9},
        {direction::forward,8},
        {direction::down,8},
        {direction::up,6},
        {direction::forward,8},
        {direction::down,3},
        {direction::forward,9},
        {direction::up,3},
        {direction::up,7},
        {direction::forward,6},
        {direction::up,3},
        {direction::down,5},
        {direction::up,9},
        {direction::down,6},
        {direction::up,1},
        {direction::forward,7},
        {direction::up,2},
        {direction::forward,3},
        {direction::forward,3},
        {direction::up,9},
        {direction::down,9},
        {direction::up,4},
        {direction::forward,9},
        {direction::down,8},
        {direction::up,1},
        {direction::forward,8},
        {direction::forward,6},
        {direction::up,8},
        {direction::down,5},
        {direction::up,7},
        {direction::up,5},
        {direction::up,5},
        {direction::up,4},
        {direction::up,3},
        {direction::forward,8},
        {direction::forward,9},
        {direction::down,9},
        {direction::forward,7},
        {direction::forward,1},
        {direction::forward,2},
        {direction::forward,4},
        {direction::up,2},
        {direction::forward,4},
        {direction::up,3},
        {direction::down,7},
        {direction::forward,6},
        {direction::down,9},
        {direction::down,3},
        {direction::down,4},
        {direction::forward,4},
        {direction::forward,8},
        {direction::forward,9},
        {direction::down,8},
        {direction::forward,3},
        {direction::forward,3},
        {direction::forward,7},
        {direction::forward,3},
        {direction::down,7},
        {direction::forward,6},
        {direction::down,8},
        {direction::forward,6},
        {direction::up,3},
        {direction::forward,9},
        {direction::down,7},
        {direction::down,6},
        {direction::down,6},
        {direction::down,5},
        {direction::forward,7},
        {direction::down,9},
        {direction::down,9},
        {direction::forward,6},
        {direction::forward,5},
        {direction::forward,6},
        {direction::up,3},
        {direction::forward,1},
        {direction::forward,8},
        {direction::down,5},
        {direction::up,2},
        {direction::up,7},
        {direction::up,9},
        {direction::forward,5},
        {direction::forward,3},
        {direction::down,6},
        {direction::forward,8},
        {direction::forward,6},
        {direction::down,8},
        {direction::down,2},
        {direction::forward,5},
        {direction::down,8},
        {direction::forward,7},
        {direction::down,6},
        {direction::down,2},
        {direction::forward,3},
        {direction::down,6},
        {direction::up,3},
        {direction::down,4},
        {direction::down,5},
        {direction::down,6},
        {direction::forward,9},
        {direction::down,8},
        {direction::down,9},
        {direction::forward,3},
        {direction::up,5},
        {direction::up,2},
        {direction::up,6},
        {direction::forward,3},
        {direction::down,4},
        {direction::down,6},
        {direction::forward,7},
        {direction::forward,9},
        {direction::up,3},
        {direction::up,8},
        {direction::up,4},
        {direction::down,4},
        {direction::up,9},
        {direction::up,9},
        {direction::down,1},
        {direction::forward,6},
        {direction::down,8},
        {direction::forward,4},
        {direction::down,1},
        {direction::forward,8},
        {direction::up,1},
        {direction::up,4},
        {direction::forward,8},
        {direction::forward,8},
        {direction::down,9},
        {direction::forward,6},
        {direction::forward,4},
        {direction::forward,6},
        {direction::forward,7},
        {direction::down,2},
        {direction::down,6},
        {direction::forward,1},
        {direction::forward,8},
        {direction::up,4},
        {direction::forward,3},
        {direction::forward,5},
        {direction::down,2},
        {direction::forward,5},
        {direction::forward,6},
        {direction::forward,9},
        {direction::forward,3},
        {direction::down,6},
        {direction::down,5},
        {direction::down,1},
        {direction::forward,2},
        {direction::forward,7},
        {direction::forward,2},
        {direction::forward,2},
        {direction::down,3},
        {direction::down,5},
        {direction::forward,2},
        {direction::forward,7},
        {direction::forward,6},
        {direction::forward,8},
        {direction::up,8},
        {direction::forward,9},
        {direction::down,4},
        {direction::down,7},
        {direction::forward,4},
        {direction::down,9},
        {direction::up,1},
        {direction::forward,5},
        {direction::forward,5},
        {direction::up,3},
        {direction::forward,3},
        {direction::up,2},
        {direction::forward,4},
        {direction::down,6},
        {direction::down,6},
        {direction::down,5},
        {direction::forward,5},
        {direction::forward,9},
        {direction::down,8},
        {direction::forward,9},
        {direction::forward,5},
        {direction::forward,4},
        {direction::up,4},
        {direction::forward,9},
        {direction::forward,2},
        {direction::forward,2},
        {direction::up,8},
        {direction::up,4},
        {direction::forward,8},
        {direction::forward,3},
        {direction::forward,6},
        {direction::forward,1},
        {direction::up,8},
        {direction::forward,2},
        {direction::forward,6},
        {direction::up,6},
        {direction::down,5},
        {direction::up,9},
        {direction::forward,1},
        {direction::down,5},
        {direction::forward,5},
        {direction::down,1},
        {direction::down,6},
        {direction::up,3},
        {direction::up,4},
        {direction::down,3},
        {direction::forward,3},
        {direction::down,2},
        {direction::forward,3},
        {direction::down,1},
        {direction::down,6},
        {direction::forward,6},
        {direction::down,7},
        {direction::up,2},
        {direction::forward,2},
        {direction::forward,9},
        {direction::forward,7},
        {direction::up,5},
        {direction::up,8},
        {direction::up,8},
        {direction::down,4},
        {direction::up,5},
        {direction::forward,6},
        {direction::up,1},
        {direction::forward,4},
        {direction::forward,5},
        {direction::up,4},
        {direction::up,8},
        {direction::up,2},
        {direction::down,4},
        {direction::up,3},
        {direction::down,2},
        {direction::forward,1},
        {direction::down,8},
        {direction::forward,5},
        {direction::up,2},
        {direction::forward,7},
        {direction::down,4},
        {direction::down,5},
        {direction::forward,4},
        {direction::forward,7},
        {direction::down,9},
        {direction::up,9},
        {direction::forward,2},
        {direction::up,3},
        {direction::up,8},
        {direction::up,3},
        {direction::up,3},
        {direction::down,3},
        {direction::forward,1},
        {direction::forward,2},
        {direction::forward,6},
        {direction::forward,3},
        {direction::up,4},
        {direction::forward,1},
        {direction::down,2},
        {direction::forward,4},
        {direction::down,9},
        {direction::forward,5},
        {direction::down,6},
        {direction::down,5},
        {direction::forward,9},
        {direction::forward,3},
        {direction::forward,9},
        {direction::forward,3},
        {direction::forward,8},
        {direction::down,3},
        {direction::forward,5},
        {direction::down,1},
        {direction::forward,7},
        {direction::forward,6},
        {direction::down,7},
        {direction::down,8},
        {direction::up,9},
        {direction::down,2},
        {direction::forward,7},
        {direction::down,9},
        {direction::forward,5},
        {direction::forward,3},
        {direction::down,1},
        {direction::forward,6},
        {direction::down,6},
        {direction::up,8},
        {direction::down,6},
        {direction::up,9},
        {direction::forward,2},
        {direction::down,1},
        {direction::forward,2},
        {direction::down,8},
        {direction::down,2},
        {direction::down,6},
        {direction::up,9},
        {direction::down,3},
        {direction::down,5},
        {direction::up,4},
        {direction::down,4},
        {direction::down,3},
        {direction::up,2},
        {direction::forward,2},
        {direction::down,1},
        {direction::down,2},
        {direction::forward,8},
        {direction::forward,3},
        {direction::down,6},
        {direction::forward,9},
        {direction::up,5},
        {direction::down,5},
        {direction::down,1},
        {direction::forward,1},
        {direction::down,3},
        {direction::down,7},
        {direction::down,5},
        {direction::forward,6},
        {direction::up,4},
        {direction::down,2},
        {direction::forward,8},
        {direction::down,9},
        {direction::up,8},
        {direction::forward,9},
        {direction::forward,5},
        {direction::down,6},
        {direction::up,4},
        {direction::forward,1},
        {direction::forward,2},
        {direction::forward,5},
        {direction::up,3},
        {direction::up,2},
        {direction::up,8},
        {direction::up,6},
        {direction::forward,9},
        {direction::down,3},
        {direction::down,7},
        {direction::down,7},
        {direction::up,5},
        {direction::forward,1},
        {direction::down,3},
        {direction::forward,9},
        {direction::down,5},
        {direction::up,6},
        {direction::down,4},
        {direction::up,5},
        {direction::up,4},
        {direction::up,9},
        {direction::forward,2},
        {direction::up,7},
        {direction::down,7},
        {direction::up,3},
        {direction::up,1},
        {direction::forward,6},
        {direction::down,1},
        {direction::down,9},
        {direction::down,9},
        {direction::down,4},
        {direction::forward,1},
        {direction::forward,6},
        {direction::up,9},
        {direction::down,3},
        {direction::up,8},
        {direction::forward,7},
        {direction::forward,3},
        {direction::down,6},
        {direction::up,9},
        {direction::forward,3},
        {direction::up,9},
        {direction::down,3},
        {direction::up,6},
        {direction::down,4},
        {direction::up,3},
        {direction::down,2},
        {direction::forward,9},
        {direction::forward,2},
        {direction::down,1},
        {direction::forward,4},
        {direction::down,5},
        {direction::up,4},
        {direction::forward,6},
        {direction::down,4},
        {direction::down,8},
        {direction::forward,4},
        {direction::down,8},
        {direction::down,9},
        {direction::up,4},
        {direction::up,7},
        {direction::down,7},
        {direction::forward,6},
        {direction::up,9},
        {direction::down,9},
        {direction::down,7},
        {direction::forward,3},
        {direction::up,4},
        {direction::up,8},
        {direction::down,2},
        {direction::down,5},
        {direction::down,9},
        {direction::forward,3},
        {direction::forward,2},
        {direction::up,6},
        {direction::down,8},
        {direction::forward,2},
        {direction::forward,7},
        {direction::up,4},
        {direction::forward,4},
        {direction::forward,7},
        {direction::forward,7},
        {direction::forward,3},
        {direction::down,2},
        {direction::down,6},
        {direction::up,6},
        {direction::down,8},
        {direction::down,4},
        {direction::forward,2},
        {direction::down,2},
        {direction::forward,2},
        {direction::forward,7},
        {direction::forward,2},
        {direction::down,1},
        {direction::down,1},
        {direction::down,3},
        {direction::down,3},
        {direction::forward,4},
        {direction::down,9},
        {direction::forward,2},
        {direction::forward,4},
        {direction::forward,1},
        {direction::forward,7},
        {direction::forward,3},
        {direction::down,1},
        {direction::down,7},
        {direction::forward,9},
        {direction::forward,7},
        {direction::up,2},
        {direction::down,5},
        {direction::forward,4},
        {direction::down,8},
        {direction::down,8},
        {direction::forward,5},
        {direction::down,3},
        {direction::up,6},
        {direction::down,3},
        {direction::forward,3},
        {direction::forward,8},
        {direction::up,9},
        {direction::up,8},
        {direction::up,7},
        {direction::forward,4},
        {direction::forward,6},
        {direction::forward,6},
        {direction::down,6},
        {direction::forward,1},
        {direction::up,8},
        {direction::down,6},
        {direction::forward,1},
        {direction::down,3},
        {direction::down,2},
        {direction::up,7},
        {direction::forward,5},
        {direction::down,2},
        {direction::down,6},
        {direction::down,8},
        {direction::up,2},
        {direction::forward,6},
        {direction::forward,3},
        {direction::forward,9},
        {direction::up,8},
        {direction::up,2},
        {direction::down,4},
        {direction::forward,3},
        {direction::down,9},
        {direction::forward,9},
        {direction::forward,2},
        {direction::down,7},
        {direction::forward,6},
        {direction::up,4},
        {direction::forward,1},
        {direction::down,5},
        {direction::forward,7},
        {direction::up,6},
        {direction::down,2},
        {direction::up,2},
        {direction::forward,6},
        {direction::down,6},
        {direction::forward,1},
        {direction::forward,5},
        {direction::down,8},
        {direction::down,2},
        {direction::up,8},
        {direction::forward,2},
        {direction::forward,2},
        {direction::down,4},
        {direction::down,9},
        {direction::forward,9},
        {direction::down,9},
        {direction::forward,5},
        {direction::down,6},
        {direction::down,8},
        {direction::forward,4},
        {direction::down,8},
        {direction::up,8},
        {direction::forward,5},
        {direction::forward,8},
        {direction::up,1},
        {direction::up,3},
        {direction::forward,3},
        {direction::down,7},
        {direction::down,8},
        {direction::up,3},
        {direction::forward,1},
        {direction::up,2},
        {direction::up,9},
        {direction::down,8},
        {direction::up,5},
        {direction::forward,7},
        {direction::forward,7},
        {direction::down,7},
        {direction::down,3},
        {direction::forward,1},
        {direction::forward,3},
        {direction::forward,7},
        {direction::down,8},
        {direction::forward,7},
        {direction::forward,6},
        {direction::down,5},
        {direction::down,8},
        {direction::down,1},
        {direction::forward,4},
        {direction::down,5},
        {direction::down,9},
        {direction::forward,1},
        {direction::forward,3},
        {direction::forward,3},
        {direction::up,2},
        {direction::forward,5},
        {direction::down,3},
        {direction::forward,2},
        {direction::down,7},
        {direction::up,7},
        {direction::up,7},
        {direction::forward,5},
        {direction::up,1},
        {direction::down,8},
        {direction::up,4},
        {direction::up,6},
        {direction::forward,4},
        {direction::forward,4},
        {direction::forward,4},
        {direction::down,7},
        {direction::down,9},
        {direction::down,7},
        {direction::forward,8},
        {direction::down,6},
        {direction::down,3},
        {direction::forward,5},
        {direction::down,6},
        {direction::forward,5},
        {direction::forward,3},
        {direction::forward,9},
        {direction::forward,9},
        {direction::up,6},
        {direction::down,9},
        {direction::up,4},
        {direction::up,1},
        {direction::down,5},
        {direction::down,2},
        {direction::up,9},
        {direction::forward,9},
        {direction::forward,8},
        {direction::up,5},
        {direction::down,6},
        {direction::up,6},
        {direction::down,4},
        {direction::down,6},
        {direction::up,3},
        {direction::forward,2},
        {direction::up,7},
        {direction::up,1},
        {direction::up,4},
        {direction::down,7},
        {direction::up,2},
        {direction::forward,7},
        {direction::up,9},
        {direction::up,3},
        {direction::forward,9},
        {direction::forward,6},
        {direction::forward,1},
        {direction::up,5},
        {direction::down,4},
        {direction::down,3},
        {direction::up,3},
        {direction::forward,5},
        {direction::down,3},
        {direction::down,4},
        {direction::up,4},
        {direction::up,9},
        {direction::up,6},
        {direction::forward,5},
        {direction::down,9},
        {direction::down,7},
        {direction::forward,4},
        {direction::forward,9},
        {direction::down,9},
        {direction::down,9},
        {direction::down,8},
        {direction::forward,1},
        {direction::up,6},
        {direction::down,7},
        {direction::down,1},
        {direction::down,3},
        {direction::down,3},
        {direction::forward,1},
        {direction::forward,8},
        {direction::up,1},
        {direction::forward,2},
        {direction::down,2},
        {direction::down,5},
        {direction::down,9},
        {direction::forward,1},
        {direction::forward,4},
        {direction::down,7},
        {direction::forward,1},
        {direction::down,1},
        {direction::down,8},
        {direction::down,3},
        {direction::forward,3},
        {direction::down,9},
        {direction::up,9},
        {direction::down,7},
        {direction::down,1},
        {direction::down,2},
        {direction::down,2},
        {direction::forward,1},
        {direction::up,3},
        {direction::up,1},
        {direction::down,5},
        {direction::forward,5},
        {direction::down,4},
        {direction::down,4},
        {direction::down,3},
        {direction::up,9},
        {direction::forward,9},
        {direction::down,3},
        {direction::forward,6},
        {direction::forward,1},
        {direction::forward,2},
        {direction::forward,8},
        {direction::forward,9},
        {direction::down,3},
        {direction::down,5},
        {direction::up,7},
        {direction::down,4},
        {direction::forward,8},
        {direction::up,9},
        {direction::forward,9},
        {direction::forward,2},
        {direction::down,2},
        {direction::forward,3},
        {direction::down,4},
        {direction::forward,2},
        {direction::forward,6},
        {direction::forward,9},
        {direction::up,8},
        {direction::down,1},
        {direction::down,4},
        {direction::up,9},
        {direction::forward,2},
        {direction::down,9},
        {direction::forward,4},
        {direction::down,7},
        {direction::up,5},
        {direction::down,2},
        {direction::forward,5},
        {direction::forward,7},
        {direction::forward,9},
        {direction::forward,1},
        {direction::down,1},
        {direction::forward,1},
        {direction::down,3},
        {direction::forward,5},
        {direction::up,8},
        {direction::down,8},
        {direction::forward,1},
        {direction::down,5},
        {direction::up,3},
        {direction::down,5},
        {direction::forward,3},
        {direction::forward,7},
        {direction::forward,2},
        {direction::down,2},
        {direction::forward,7},
        {direction::forward,4},
        {direction::forward,4},
        {direction::down,3},
        {direction::forward,5},
        {direction::down,5},
        {direction::down,9},
        {direction::up,4},
        {direction::down,6},
        {direction::down,5},
        {direction::forward,5},
        {direction::forward,9},
        {direction::down,9},
        {direction::forward,9},
        {direction::down,6},
        {direction::forward,4},
        {direction::down,5},
        {direction::down,8},
        {direction::up,9},
        {direction::down,7},
        {direction::up,7},
        {direction::forward,4},
        {direction::down,6},
        {direction::forward,5},
        {direction::forward,4},
        {direction::up,7},
        {direction::forward,9},
        {direction::forward,7},
        {direction::up,7},
        {direction::down,8},
        {direction::down,1},
        {direction::forward,3},
        {direction::down,3},
        {direction::down,6},
        {direction::up,6},
        {direction::up,5},
        {direction::up,8},
        {direction::down,7},
        {direction::forward,6},
        {direction::down,9},
        {direction::forward,9},
        {direction::forward,6},
        {direction::up,7},
        {direction::down,4},
        {direction::down,5},
        {direction::down,8},
        {direction::forward,9},
        {direction::forward,8},
        {direction::forward,2},
        {direction::forward,4},
        {direction::up,6},
        {direction::down,7},
        {direction::forward,8},
        {direction::down,9},
        {direction::forward,3},
        {direction::forward,1},
        {direction::forward,4},
        {direction::forward,8},
        {direction::down,4},
        {direction::down,1},
        {direction::forward,5},
        {direction::down,7},
        {direction::down,3},
        {direction::up,2},
        {direction::up,5},
        {direction::down,6},
        {direction::forward,5},
        {direction::down,9},
        {direction::down,3},
        {direction::forward,8},
        {direction::up,5},
        {direction::down,6},
        {direction::forward,3},
        {direction::down,5},
        {direction::forward,1},
        {direction::down,3},
        {direction::up,3},
        {direction::forward,9},
        {direction::forward,9},
        {direction::forward,8},
        {direction::down,4},
        {direction::down,1},
        {direction::forward,7},
        {direction::forward,7},
        {direction::down,9},
        {direction::up,2},
        {direction::forward,2},
        {direction::forward,2},
        {direction::forward,1},
        {direction::forward,2},
        {direction::down,2},
        {direction::down,7},
        {direction::forward,5},
        {direction::forward,3},
        {direction::forward,2},
        {direction::down,1},
        {direction::down,6},
        {direction::up,4},
        {direction::down,3},
        {direction::forward,2},
        {direction::down,2},
        {direction::down,2},
        {direction::forward,9},
        {direction::up,8},
        {direction::forward,9},
        {direction::down,8},
        {direction::up,8},
        {direction::down,8},
        {direction::down,1},
        {direction::forward,9},
        {direction::up,7},
        {direction::up,6},
        {direction::down,3},
        {direction::forward,5},
        {direction::up,9},
        {direction::forward,5},
        {direction::forward,8},
        {direction::up,3},
        {direction::forward,8},
        {direction::forward,9},
        {direction::forward,2},
        {direction::forward,4},
        {direction::down,7},
        {direction::forward,1},
        {direction::forward,1},
        {direction::down,7},
        {direction::forward,8},
        {direction::forward,4},
        {direction::forward,2},
        {direction::forward,7},
        {direction::forward,6},
        {direction::forward,5},
        {direction::down,8},
        {direction::down,9},
        {direction::up,9},
        {direction::forward,1},
        {direction::forward,4},
        {direction::down,1},
        {direction::forward,6},
        {direction::up,4},
        {direction::forward,8},
        {direction::forward,6},
        {direction::up,5},
        {direction::forward,9},
        {direction::down,8},
        {direction::down,4},
        {direction::down,9},
        {direction::forward,2},
        {direction::up,4},
        {direction::down,2},
        {direction::forward,4},
        {direction::down,9},
        {direction::forward,3},
        {direction::down,8},
        {direction::forward,7},
        {direction::forward,3},
        {direction::down,7},
        {direction::down,7},
        {direction::down,8},
        {direction::forward,8},
        {direction::down,2},
        {direction::forward,7},
        {direction::up,7},
        {direction::down,5},
        {direction::down,7},
        {direction::down,5},
        {direction::up,9},
        {direction::up,8},
        {direction::down,1},
        {direction::down,9},
        {direction::forward,7},
        {direction::up,2},
        {direction::forward,1},
        {direction::forward,3},
        {direction::forward,8},
        {direction::down,5},
        {direction::forward,7},
        {direction::up,6},
        {direction::forward,5},
        {direction::up,5},
        {direction::forward,4},
        {direction::down,6},
        {direction::down,4},
        {direction::forward,1},
        {direction::up,1},
        {direction::forward,2},
        {direction::forward,2},
        {direction::forward,8},
        {direction::forward,7},
        {direction::down,4},
        {direction::down,1},
        {direction::forward,5},
        {direction::forward,9},
        {direction::up,4},
        {direction::down,4},
        {direction::up,9},
        {direction::up,4},
        {direction::down,8},
        {direction::down,7},
        {direction::forward,1},
        {direction::down,8},
        {direction::forward,9},
        {direction::down,4},
        {direction::forward,5},
        {direction::forward,2},
        {direction::down,1},
        {direction::forward,7},
        {direction::forward,4},
        {direction::down,9},
        {direction::forward,8},
        {direction::down,1},
        {direction::forward,7},
        {direction::forward,6},
        {direction::up,9},
        {direction::forward,6},
        {direction::forward,6},
        {direction::forward,8},
        {direction::forward,3},
        {direction::up,1},
        {direction::forward,9},
        {direction::down,3},
        {direction::down,9},
        {direction::down,8},
        {direction::forward,5},
        {direction::down,7},
        {direction::forward,6},
        {direction::forward,1},
        {direction::up,1},
        {direction::up,3},
        {direction::up,7},
        {direction::forward,1},
        {direction::forward,8},
        {direction::forward,6},
        {direction::forward,9},
        {direction::down,6},
        {direction::forward,9},
        {direction::down,2},
        {direction::up,2},
        {direction::down,7},
        {direction::down,7},
        {direction::forward,8},
        {direction::down,2},
        {direction::down,3},
        {direction::forward,7},
        {direction::forward,5},
        {direction::down,3},
        {direction::down,1},
        {direction::up,8},
        {direction::up,6},
        {direction::down,3},
        {direction::forward,1},
        {direction::forward,6},
        {direction::forward,4},
        {direction::forward,7},
        {direction::down,3},
        {direction::down,9},
        {direction::up,6},
        {direction::down,7},
        {direction::forward,9},
        {direction::forward,2},
        {direction::forward,7},
        {direction::down,2},
        {direction::down,8},
        {direction::down,1},
        {direction::down,9},
        {direction::up,8},
        {direction::forward,3},
        {direction::down,9},
        {direction::forward,6},
        {direction::down,4},
        {direction::forward,1},
        {direction::up,8},
        {direction::up,4},
        {direction::down,5},
        {direction::forward,2},
        {direction::forward,9},
        {direction::forward,5},
        {direction::forward,6},
        {direction::down,4},
        {direction::up,4},
        {direction::down,6},
        {direction::down,8},
        {direction::down,2},
        {direction::down,7},
        {direction::down,2},
        {direction::up,8},
        {direction::forward,4},
        {direction::down,7},
        {direction::forward,2},
        {direction::down,5},
        {direction::forward,3},
        {direction::forward,1},
        {direction::down,2},
        {direction::up,3},
        {direction::down,2},
        {direction::forward,1},
        {direction::forward,2},
        {direction::down,6},
        {direction::down,2},
        {direction::down,9},
        {direction::forward,9},
        {direction::down,1},
        {direction::up,2},
        {direction::down,4},
        {direction::forward,1},
        {direction::forward,6},
        {direction::forward,8},
        {direction::forward,3},

    };
}

int main (void)
{

    std::cout << "First exercice result: " << measurements::calculatePosition(::meas) << std::endl;        
    std::cout << "Second exercice result: " << measurements::calculatePositionWithAim(::meas) << std::endl;  

    return 0;
}