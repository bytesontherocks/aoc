#include "measurements.hpp"
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <array>

// parse line
namespace {

    struct coordinates{
        std::pair<size_t, size_t>coordinatesStart;
        std::pair<size_t, size_t>coordinatesEnd;
    };
    

    auto getCoordinate(std::string& line) {

        auto coord = coordinates();
        
        size_t pos = 0;
        std::string delimiter1 = ",";
        std::string delimiter2 = " ";
        std::string delimiter3 = " -> ";
        std::string s;

        pos = line.find(delimiter1, 0);
        s = line.substr(0, pos);
        coord.coordinatesStart.first = std::stoi(s);
        std::cout << "First coord x: "<< coord.coordinatesStart.first << std::endl;

        size_t pos2 = line.find(delimiter2, pos);
        s = line.substr(pos + 1, pos2);
        coord.coordinatesStart.second = std::stoi(s);

        std::cout << "First coord y: "<< coord.coordinatesStart.second << std::endl;

        size_t pos3 = line.find(delimiter2, pos2+ 1);
        size_t pos4 = line.find(delimiter1, pos3);
        s = line.substr(pos3 + 1, pos4);
        coord.coordinatesEnd.first = std::stoi(s);

        std::cout << "Second coord y: "<< coord.coordinatesEnd.first << std::endl;
        pos4 = line.find(delimiter1, pos4);
        s = line.substr(pos4 + 1);
        coord.coordinatesEnd.second = std::stoi(s);

        std::cout << "Second coord y: "<< coord.coordinatesEnd.second << std::endl;

        // last element  
        s = line.substr(0, pos);
          
        return coord;
    }   

}              

int64_t measurements::calculateFirstExercice(std::ifstream& input)
{
    std::string line = {""};

    std::vector<coordinates>v;

    while(std::getline(input, line)) {
        auto coord = getCoordinate(line);
        v.push_back(coord);
    }

    size_t maxX = 0;
    size_t maxY = 0;

    std::vector<coordinates>validCoord;
    for (auto it = v.begin(); it != v.end(); ++it) {
        auto coord = *it;
        if ((coord.coordinatesStart.first == coord.coordinatesEnd.first) ||
            (coord.coordinatesStart.second == coord.coordinatesEnd.second)) {

            if (coord.coordinatesStart.first > maxX)  
                maxX = coord.coordinatesStart.first;

            if (coord.coordinatesEnd.first > maxX)  
                maxX = coord.coordinatesStart.first;    

            if (coord.coordinatesStart.second > maxY)  
                maxY = coord.coordinatesStart.second;

            if (coord.coordinatesEnd.second > maxY)  
                maxY = coord.coordinatesStart.second;  

            validCoord.push_back(coord);
        }
    }


    uint32_t arrayResult [maxX + 1][maxY + 1];

    for (auto i = 0; i < maxX + 1; ++i) {
        for (auto j = 0; j < maxY + 1; ++j) {
            arrayResult[i][j] = 0;
        }
    }

    for (auto it = validCoord.begin(); it != validCoord.end(); ++it) {
        //std::cout << (*it).coordinatesStart.first << ", "<< (*it).coordinatesStart.second<< " || "  << (*it).coordinatesEnd.first << ", "<< (*it).coordinatesEnd.second  << std::endl;
        auto x1 = (*it).coordinatesStart.first;
        auto y1 = (*it).coordinatesStart.second;

        auto x2 = (*it).coordinatesEnd.first;
        auto y2 = (*it).coordinatesEnd.second;

        if (x1 == x2) {
            if (y1 > y2) {
                std::swap(y1,y2);
            }

            for (auto i = y1; i <= y2; ++i) {
                arrayResult[x1][i]++;
            }


        } else { // y1 == y2
            if (x1 > x2) {
                std::swap(x1,x2);
            }

            for (auto i = x1; i <= x2; ++i) {
                arrayResult[i][y1]++;
            }
        }    
    }

    size_t counter = 0;
    
    for (auto i = 0; i < maxX + 1; ++i) {
        for (auto j = 0; j < maxY + 1; ++j) {
            if (arrayResult[i][j] > 1) {
                counter++;
            }
        }
    }

    return counter;
}

int64_t measurements::calculateSecondExercice(std::ifstream& input)
{
    std::string line = {""};

    std::vector<coordinates>v;

    while(std::getline(input, line)) {
        auto coord = getCoordinate(line);
        v.push_back(coord);
    }

    size_t maxX = 0;
    size_t maxY = 0;

    std::vector<coordinates>validCoord;
    for (auto it = v.begin(); it != v.end(); ++it) {
        auto coord = *it;
        if ((coord.coordinatesStart.first == coord.coordinatesEnd.first) ||
            (coord.coordinatesStart.second == coord.coordinatesEnd.second) ||
            (std::abs((int)(coord.coordinatesStart.first - coord.coordinatesEnd.first)) == std::abs((int)(coord.coordinatesStart.second - coord.coordinatesEnd.second)))
            )
            {

            if (coord.coordinatesStart.first > maxX)  
                maxX = coord.coordinatesStart.first;

            if (coord.coordinatesEnd.first > maxX)  
                maxX = coord.coordinatesStart.first;    

            if (coord.coordinatesStart.second > maxY)  
                maxY = coord.coordinatesStart.second;

            if (coord.coordinatesEnd.second > maxY)  
                maxY = coord.coordinatesStart.second;  

            validCoord.push_back(coord);
        }
    }


    uint32_t arrayResult [maxX + 1][maxY + 1];

    for (auto i = 0; i < maxX + 1; ++i) {
        for (auto j = 0; j < maxY + 1; ++j) {
            arrayResult[i][j] = 0;
        }
    }

    for (auto it = validCoord.begin(); it != validCoord.end(); ++it) {
        std::cout << (*it).coordinatesStart.first << ", "<< (*it).coordinatesStart.second<< " || "  << (*it).coordinatesEnd.first << ", "<< (*it).coordinatesEnd.second  << std::endl;
        auto x1 = (*it).coordinatesStart.first;
        auto y1 = (*it).coordinatesStart.second;

        auto x2 = (*it).coordinatesEnd.first;
        auto y2 = (*it).coordinatesEnd.second;

        if (x1 == x2) {
            if (y1 > y2) {
                std::swap(y1,y2);
            }

            for (auto i = y1; i <= y2; ++i) {
                arrayResult[x1][i]++;
            }


        } else if (y1 == y2) { 
            if (x1 > x2) {
                std::swap(x1,x2);
            }

            for (auto i = x1; i <= x2; ++i) {
                arrayResult[i][y1]++;
            }

        } else  {
            size_t pointsDiagonal =0;

            if (x1 > x2) {
                std::swap(x1,x2);
                std::swap(y1,y2);
            }

            pointsDiagonal = (x2 - x1) ;

            auto tempX = x1;
            auto tempY = y1;


            for(size_t i = 0; i <= pointsDiagonal; ++i) {
                if (y1 > y2)
                    arrayResult[tempX++][tempY--]++;
                else 
                    arrayResult[tempX++][tempY++]++;
            }
        }   


    }

    size_t counter = 0;
    
    for (auto i = 0; i < maxX + 1; ++i) {
        for (auto j = 0; j < maxY + 1; ++j) {
            if (arrayResult[i][j] >= 2) {
                counter++;
            }
        }
    }

    return counter;
}


    
    