#include "measurements.hpp"
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>

namespace {

    void removeElements(std::vector<std::string>& v, const size_t numOfElement, const size_t val)
    {
        if (v.size() == 1) return;

        bool allDone = true;

        do  
        {  
            allDone = true;

            for (auto it = v.begin(); it != v.end(); ++it) {
                if (((*it).at(numOfElement) - 0x30) == val) {
                    v.erase(it);
                    allDone = false;
                    break;
                }
            }
                   
        } while (allDone == false);  

    }
}


int64_t measurements::calculateFirstExercice(std::ifstream& input)
{
    std::string line { "" };

    uint32_t lineCounter= 0;

    std::getline(input, line);

    auto width = line.length();
    uint32_t counters[width]  = {0};

    do
    {
        lineCounter++;
        for (unsigned i=0; i < line.length(); ++i) {         
            counters[i] += (line.at(i) - 0x30);           
        }
    } while (std::getline(input, line));

    uint32_t gamma_rate, epsilon_rate = 0;
    for(auto j = 0; j < width; ++j) {
        if (counters[j] >= lineCounter/2) {
            gamma_rate += 1 << (width -1 - j);          
        } else {
            epsilon_rate += 1 << (width -1 - j);
        }

    }    

    return gamma_rate * epsilon_rate;
}

int64_t measurements::calculateSecondExercice(std::ifstream& input)
{
    std::string line { "" };

    uint32_t lineCounter= 0;

    std::getline(input, line);

    auto width = line.length();
    uint32_t counters[width]  = {0};
    uint32_t majority[width]  = {0};


    std::vector<std::string> v_minority;//co2
    std::vector<std::string> v_majority;//oxygen

    // generate counters
    do
    {
        lineCounter++;
        for (unsigned i=0; i < line.length(); ++i) {       
            auto c = line.at(i) - 0x30;
            counters[i] += c;   
        }

        v_majority.push_back(line);
        v_minority.push_back(line);

    } while (std::getline(input, line));  

    for(auto j = 0; j < width; ++j) {

        uint32_t count = 0;
        uint32_t majority = 0;
        for (auto it = v_majority.begin(); it != v_majority.end(); ++it) {
              count += (*it).at(j) - 0x30;
        }
        

        if (count >= v_majority.size() - count) {
            majority = 1;
        }

        if (v_majority.size() > 1) {
            removeElements(v_majority, j, !majority);
        }

        count = 0;
        majority = 0;
        for (auto it = v_minority.begin(); it != v_minority.end(); ++it) {
              count += (*it).at(j) - 0x30;
        }

        if (count >= v_minority.size() - count) {
            majority = 1;
        }

        if (v_minority.size() > 1)
            removeElements(v_minority, j, majority);     
        
    }

    uint32_t oxygen = 0, co2 = 0;

    for(auto j = 0; j < width; ++j) {
        
        if (v_majority.at(0).at(j) > 0x30)
            oxygen += 1 << (width -1 - j);

        if (v_minority.at(0).at(j) > 0x30)
            co2 += 1 << (width -1 - j);
    }
    return oxygen * co2;
}

