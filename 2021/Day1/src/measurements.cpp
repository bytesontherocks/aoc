#include "measurements.hpp"
#include <functional>
#include <numeric>

uint32_t measurements::getNumberOfIncreases(const std::vector<uint32_t>& v)
{
    uint32_t largerThanPrevious = 0;

    for(std::size_t i = 1; i < v.size(); ++i) {        
        if (v[i] >  v[i-1]) {
            largerThanPrevious++;
        }       
    }

    return largerThanPrevious;
}

uint32_t measurements::getNumberOfIncreasesWindow(const std::vector<uint32_t>& v)
{
    constexpr uint32_t windowSize = 3;
    uint32_t numOfWindowIncreases = 0;

    if (v.size() - windowSize) {

        auto it = v.begin();

        auto oldWindow = std::accumulate(it, it + windowSize, 0);

        while (it++ != v.end() - windowSize) {

            auto newWindow = std::accumulate(it, it + windowSize, 0);

            if (newWindow > oldWindow) {
                numOfWindowIncreases++;
            }  

            oldWindow = newWindow;            
        }
    }

    return numOfWindowIncreases;
}

