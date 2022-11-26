#include "measurements.hpp"
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <array>
#include <cstdlib>
#include <bits/stdc++.h>
namespace {

    bool isLowPoint(const size_t val, const size_t up,const size_t down,const size_t left,const size_t right) {
        bool isLow = false;
        if((val < up) && (val < down) && (val < left ) && (val < right)) {
            isLow = true;
        }
        return isLow;
    }
    bool isLowPoint(const size_t val, const size_t up,const size_t down, const size_t side) {
        bool isLow = false;
        if((val < up) && (val < down) && (val < side)) {
            isLow = true;
        }
        return isLow;
    }

    std::vector<std::pair<size_t,size_t>> lowPointsCoord;    

    void checkAdjacent(std::vector<std::vector<std::pair<uint32_t, int32_t>>>& a, const uint32_t xMax, const uint32_t yMax, const uint32_t x, const uint32_t y, const uint32_t basinNum, uint32_t& elementsInBasin )
    {
        // Top, Down, Left, Right
        std::array<std::pair<int, int>, 4> direction {{ {0,-1}, {0,1}, {-1,0}, {1,0} }};

        for(auto ix = 0; ix < direction.size(); ix++) {
            int32_t xClamped = std::clamp((int32_t)(x + direction[ix].first), (int32_t)0, (int32_t)xMax);
            int32_t yClamped = std::clamp((int32_t)(y + direction[ix].second), (int32_t)0, (int32_t)yMax);

            if ((a[xClamped][yClamped].first != 9) && (a[xClamped][yClamped].second == -1)) 
            {
                a[xClamped][yClamped].second = basinNum;
                elementsInBasin++;
                checkAdjacent(a, xMax, yMax, xClamped, yClamped, basinNum, elementsInBasin);
            }           
        }
    }
  
}//anonymous namespace

uint64_t measurements::calculateFirstExercice(std::ifstream& input)
{
    std::string line = {""};

    auto yLength = 0;
    while (std::getline(input, line)) {
        yLength++;
    };

    input.clear();
    input.seekg(0, std::ios::beg);

    auto xMax = line.length() - 1;
    auto yMax = yLength -1;

    uint32_t a[xMax + 1][yMax + 1];
    
    auto numLines = 0;
    
    while (std::getline(input, line)){

        for (auto i =0; i< xMax + 1; ++i){
            a[i][numLines] = (line.at(i) - 0x30);
        }
        numLines++;
    };

    std::vector<size_t> lowPoints;

    // Point out of the edges
    for (auto x = 1; x < xMax; ++x) {
        for (auto y = 1; y < yMax ; ++y) {
            auto val = a[x][y], up = a[x][y+1], down = a[x][y-1], left = a[x-1][y], right = a[x+1][y];
    
            if (isLowPoint(val, up, down, left, right)) {
                lowPoints.push_back(val);
                lowPointsCoord.push_back(std::make_pair(x,y));
            }
        }
    }

    // left side
    auto x = 0;
    for (auto y = 1; y < yMax-1; ++y) {
        auto val = a[x][y], up = a[x][y+1], down = a[x][y-1], right = a[x+1][y];
        if (isLowPoint(val, up, down, right) ) {
            lowPoints.push_back(val);
            lowPointsCoord.push_back(std::make_pair(x,y));
        }
    }

    // right side
    x = xMax;
    for (auto y = 1; y < yMax-1; ++y) {
        auto val = a[x][y], up = a[x][y+1], down = a[x][y-1], left = a[x-1][y];
        if (isLowPoint(val, up, down, left)) {
            lowPoints.push_back(val);
            lowPointsCoord.push_back(std::make_pair(x,y));
        }
    }

    // top row
    auto y = 0;
    for (auto x = 1; x < xMax-1; ++x) {
        auto val = a[x][y], down = a[x][y+1], left = a[x-1][y], right = a[x+1][y];
        if (isLowPoint(val, down, left, right) ) {
            lowPoints.push_back(val);
            lowPointsCoord.push_back(std::make_pair(x,y));
        }
    }

    // bottom row
    y = yMax;
    for (auto x = 1; x < xMax-1; ++x) {
        auto val = a[x][y], top = a[x][y-1], left = a[x-1][y], right = a[x+1][y];
        if (isLowPoint(val, top, left, right) ) {
            lowPoints.push_back(val);
            lowPointsCoord.push_back(std::make_pair(x,y));
        }
    }

    //corners
    auto cornerTopLeft = a[0][0];
    if ((cornerTopLeft < a[0][1]) && (cornerTopLeft < a[1][0])) {
        lowPoints.push_back(cornerTopLeft);
        lowPointsCoord.push_back(std::make_pair(0,0));
    }
    
    auto cornerTopRight = a[xMax][0];
    if ((cornerTopRight < a[xMax][1]) && (cornerTopRight < a[xMax - 1][0])) {
        lowPoints.push_back(cornerTopRight);
        lowPointsCoord.push_back(std::make_pair(xMax,0));
    }

    auto cornerDownLeft = a[0][yMax];
    if ((cornerDownLeft < a[0][yMax-1]) && (cornerDownLeft < a[1][yMax])) {
        lowPoints.push_back(cornerDownLeft);
        lowPointsCoord.push_back(std::make_pair(0,yMax));
    }

    auto cornerDownRight = a[xMax][yMax];
    if ((cornerDownRight < a[xMax][yMax -1]) && (cornerDownRight < a[xMax -1][yMax])) {
        lowPoints.push_back(cornerDownRight);
        lowPointsCoord.push_back(std::make_pair(xMax,yMax));
    }

    for (auto it = lowPoints.begin(); it != lowPoints.end(); ++it) {
        (*it)++;
    }

    return std::accumulate(lowPoints.begin(), lowPoints.end(), (uint64_t)0);
}

uint64_t measurements::calculateSecondExercice(std::ifstream& input)
{
    std::string line = {""};

    auto yLength = 0;
    while (std::getline(input, line)) {
        yLength++;
    };

    input.clear();
    input.seekg(0, std::ios::beg);

    auto xMax = line.length() - 1;
    auto yMax = yLength - 1;

    std::vector<std::vector<std::pair<uint32_t, int32_t>>> a(xMax + 1, std::vector<std::pair<uint32_t, int32_t>>(yMax + 1));
    
    auto numLines = 0;
    
    while (std::getline(input, line)){
        for (auto i =0; i<= xMax; ++i){
            a[i][numLines].first = (line.at(i) - 0x30);
            a[i][numLines].second = -1; 
        }
        numLines++;
    };

    uint32_t basinNumberCounter = 0;
    std::vector<uint32_t> counters(lowPointsCoord.size(), 1);

    for(auto lowPointIndex = 0; lowPointIndex < lowPointsCoord.size(); lowPointIndex++)
    {
        auto x = lowPointsCoord[lowPointIndex].first;
        auto y = lowPointsCoord[lowPointIndex].second;        

        a[x][y].second = basinNumberCounter;
        checkAdjacent(a, xMax, yMax, x, y, basinNumberCounter, counters[lowPointIndex]);
        basinNumberCounter++;
    }
	
    // Element 0 will contain biggest counter
    std::sort(counters.begin(), counters.end(), std::greater<uint32_t>());

    return counters[0]*counters[1]*counters[2];
}