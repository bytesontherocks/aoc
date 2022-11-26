#include "measurements.hpp"
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <array>
#include <cstdlib>

namespace {

    auto calculateNewTarget(size_t& target, bool increase = false) {
        auto increment = 1;

        if (increase)
            target += increment;
        else
            target -= increment;
    }

    auto calculateFuelConsumption(std::vector<size_t> v, const size_t target) 
    {
        auto fuelConsumption = 0;
     
        for (auto &&i: v) {
            int32_t distance = i - target;// use std::abs
            if (distance < 0)
                distance *= -1;

            fuelConsumption += distance;
        }

        return fuelConsumption;
    }

     auto calculateFuelConsumptionSecondExercise(std::vector<size_t> v, const size_t target) 
    {
        auto fuelConsumption = 0;

        for (auto &&i: v) {
            int32_t distance = i - target;// use std::abs
            if (distance < 0)
                distance *= -1;

            fuelConsumption += (distance * (distance+1))/2;
        }

        return fuelConsumption;
    }


}

uint64_t measurements::calculateFirstExercice(std::vector<size_t> v)
{
    std::sort(v.begin(), v.end());
    
    auto target = v[v.size()/2];

    auto fuelConsumption = calculateFuelConsumption(v, target);
    auto fuelConsumptionInc = calculateFuelConsumption(v, target+1);
    auto fuelConsumptionDec = calculateFuelConsumption(v, target-1);    

    std::cout << fuelConsumptionDec << ", " << fuelConsumption << ", " << fuelConsumptionInc << std::endl;
    

    return fuelConsumption;
}

uint64_t measurements::calculateSecondExercice(std::vector<size_t> v)
{
    std::sort(v.begin(), v.end());
    
    auto target = v[v.size()/2];

    auto fuelConsumption = 0;
    auto fuelConsumptionInc = 0;
    auto fuelConsumptionDec = 0;    

    bool optimumFound = false;

    do {

        fuelConsumption = calculateFuelConsumptionSecondExercise(v, target);
        fuelConsumptionInc = calculateFuelConsumptionSecondExercise(v, target+1);
        fuelConsumptionDec = calculateFuelConsumptionSecondExercise(v, target-1);    

        if ((fuelConsumptionDec > fuelConsumption) && (fuelConsumption < fuelConsumptionInc)) {
            optimumFound = true;
        } else {

            bool targetInc = false;
            if (fuelConsumptionInc < fuelConsumption)
                targetInc = true;

            calculateNewTarget(target, targetInc);
        }

    } while (optimumFound == false);

    std::cout << fuelConsumptionDec << ", " << fuelConsumption << ", " << fuelConsumptionInc << std::endl;
    

    return fuelConsumption;
}



    