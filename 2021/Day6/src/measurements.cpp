#include "measurements.hpp"
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <array>

constexpr uint64_t calc(const size_t days)
{
    const std::array<size_t, 300>v  = {1,2,1,3,2,1,1,5,1,4,1,2,1,4,3,3,5,1,1,3,5,3,4,5,5,4,3,1,1,4,3,1,5,2,5,2,4,1,1,1,1,1,1,1,4,1,4,4,4,1,4,4,1,4,2,1,1,1,1,3,5,4,3,3,
    5,4,1,3,1,1,2,1,1,1,4,1,2,5,2,3,1,1,1,2,1,5,1,1,1,4,4,4,1,5,1,2,3,2,2,2,1,1,4,3,1,4,4,2,1,1,5,1,1,1,3,1,2,1,1,1,1,4,5,5,2,3,4,2,1,1,1,2,1,1,5,5,3,5,4,3,
    1,3,1,1,5,1,1,4,2,1,3,1,1,4,3,1,5,1,1,3,4,2,2,1,1,2,1,1,2,1,3,2,3,1,4,5,1,1,4,3,3,1,1,2,2,1,5,2,1,3,4,5,4,5,5,4,3,1,5,1,1,1,4,4,3,2,5,2,1,4,3,5,1,3,5,1,
    3,3,1,1,1,2,5,3,1,1,3,1,1,1,2,1,5,1,5,1,3,1,1,5,4,3,3,2,2,1,1,3,4,1,1,1,1,4,1,3,1,5,1,1,3,1,1,1,1,2,2,4,4,4,1,2,5,5,2,2,4,1,1,4,2,1,1,5,1,5,3,5,4,5,3,1,1,1,2,3,1,2,1,1};

    std::array<uint64_t,9>aC = {0};   

    for (auto &&i: v) {
       aC[i]++;
    }

    auto daysCounter = 0;

    while (daysCounter < days)
    {
        daysCounter++;
        auto temp = aC[0];

        for (auto aCIndex = 0; aCIndex < 8; aCIndex++)
            aC[aCIndex] = aC[aCIndex+1]; 

        aC[8] = temp;
        aC[6] += temp;
    };
    
    uint64_t res = 0;
    for (auto it = aC.begin(); it != aC.end(); ++it) {
        res += (*it);
    }

    return res;   
}
      

uint64_t measurements::calculateFirstExercice(std::vector<size_t> v, const size_t days)
{
    static_assert(calc(80) == 366057);// test

    return calc(days);
}

uint64_t measurements::calculateSecondExercice(std::vector<size_t> v, const size_t days)
{
    static_assert(calc(256) == ((uint64_t)1653559299811));// test

    return calc(days);
}



    