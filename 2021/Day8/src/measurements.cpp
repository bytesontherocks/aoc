#include "measurements.hpp"
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <array>
#include <cstdlib>

namespace {

    void sortStrings(std::vector<std::string>& v) {

        struct compare {
            inline bool operator()(const std::string& first,
                    const std::string& second) const
            {
                return first.size() < second.size();
            }
        };
        compare c;

        // sort by length
        std::sort(v.begin(), v.end(), c);

        // sort each string alphabetically
        for (auto it = v.begin(); it != v.end(); ++it) {
            std::sort((*it).begin(), (*it).end());
        }
    }

    auto parseLine(std::string& line) {

        std::array<size_t, 6> a = {0};

        auto pos = 0;
        std::string delimiter = " ";
        std::string s;      
        
        pos = line.find("|", 0);
        line.erase(0, pos + delimiter.length()+1);

        for (auto i = 0; i < 3; i++) {
            pos = line.find(delimiter, 0);
            s = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            a[s.length()-2]++;     
        }    

        // last element  
        s = line.substr(0, std::string::npos);
        a[s.length()-2]++;

        return a;
    }

    auto parseSol(std::string& line) {

        std::array<size_t, 6> a = {0};

        auto pos = 0;
        std::string delimiter = " ";
        std::string s;      
         std::vector<std::string>vLine;
        pos = line.find("|", 0);
        line.erase(0, pos + delimiter.length()+1);

        for (auto i = 0; i < 3; i++) {
            pos = line.find(delimiter, 0);
            s = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
           vLine.push_back(s);    
        }    

        // last element  
        s = line.substr(0, std::string::npos);
        vLine.push_back(s);

        // sort each string alphabetically to compare
        for (auto it = vLine.begin(); it != vLine.end(); ++it) {
            std::sort((*it).begin(), (*it).end());
        }

        return vLine;
    }


    auto parseLineExerciseTwo(std::string& line) {

        std::array<std::string,10> segments = {""};

        auto pos = 0;
        std::string delimiter = " ";
        std::string s;      

        std::vector<std::string>vLine;

        for (auto i = 0; i < 10; i++) {
            pos = line.find(delimiter, 0);
            s = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());            
            vLine.push_back(s);
        }    

        // sorted by length and alphabetically
        sortStrings(vLine);


        std::vector<std::pair<std::string, size_t>>pNum = { {vLine[0], 1}, {vLine[1], 7},
                                                            {vLine[2], 4}, {vLine[3], 5},
                                                            {vLine[4], 5}, {vLine[5], 5}, 
                                                            {vLine[6], 6}, {vLine[7], 6},
                                                            {vLine[8], 6}, {vLine[9], 8} };

        

        auto s4 = vLine[2];
        auto pos1 = s4.find(vLine[0].at(0), 0);
        s4.erase(pos1, 1);
        pos1 = s4.find(vLine[0].at(1), 0);
        s4.erase(pos1, 1);

        std::vector<std::string>vS = {vLine[3], vLine[4], vLine[5]};
        // 5 characters: {vLine[3], 5}, {vLine[4], 5}, {vLine[5], 5}
        // number 2, 3, 5 have 5 characters
        // 5 has 4 - 1
        for (auto ix = 0; ix != vS.size(); ++ix) {
            auto s = vS[ix];
            if ((s.find(s4.at(0)) != std::string::npos) && (s.find(s4.at(1)) != std::string::npos)) {
                pNum[3].first = s;
                pNum[3].second = 5;
                vS.erase(vS.begin() + ix);
                break;
            }
        }

        // 4 contains 7 char
        for (auto ix = 0; ix != vS.size(); ++ix) {
             auto s = vS[ix];
            if ((s.find(vLine[1].at(0)) != std::string::npos) && (s.find(vLine[1].at(1)) != std::string::npos) && (s.find(vLine[1].at(2)) != std::string::npos)) {
                pNum[4].first = s;
                pNum[4].second = 3;

                auto ixx = 0;
                if (ix == 0) ixx = 1;
                pNum[5].first = vS[ixx];  
                pNum[5].second = 2;                    
                break;
            }
        }    

        // 6 characters: {vLine[6], 6}, {vLine[7], 6}, {vLine[8], 6}
        std::vector<std::string>vSS = {vLine[6], vLine[7], vLine[8]};
   
        for (auto ix = 0; ix != vSS.size(); ++ix) {
            auto s = vSS[ix];
            if ((s.find(vLine[0].at(0)) == std::string::npos) || (s.find(vLine[0].at(1)) == std::string::npos)) {
                pNum[6].first = s;
                pNum[6].second = 6;
                vSS.erase(vSS.begin() + ix);
                break;
            }
        }

        for (auto ix = 0; ix != vSS.size(); ++ix) {
            auto s = vSS[ix];
            if ((s.find(s4.at(0)) != std::string::npos) && (s.find(s4.at(1)) != std::string::npos)) {
                pNum[7].first = s;
                pNum[7].second = 9;

                pNum[8].second = 0;  

                auto ixx = 0;
                if (ix == 0) ixx = 1;
                pNum[8].first = vSS[ixx];  
                break;
            }
        }
       
        return pNum;
    }
} 

uint64_t measurements::calculateFirstExercice(std::ifstream& input)
{
    std::string line = {""};
    std::array<size_t, 6> a = {0};
    while(std::getline(input, line)) {
        auto b = parseLine(line);

        for(auto i = 0; i < a.size(); i++)
            a[i] += b[i];
    }

    return a[0] + a[1] + a[2] + a[5] ;
}

uint64_t measurements::calculateSecondExercice(std::ifstream& input)
{
    std::string line = {""};

    uint64_t res = 0;

    while(std::getline(input, line)) {
        auto lineTemp = line;
        auto pNum = parseLineExerciseTwo(lineTemp);
        auto lineTemp2 = line;
        auto vSol = parseSol(lineTemp2);

        std::array<uint32_t,4> a = {};
        size_t index = 0;

        for (auto vI = vSol.begin(); vI != vSol.end(); ++vI) {
            for (auto i = pNum.begin(); i != pNum.end(); ++i) {
                if ((*i).first == *vI) {
                    a[index++] = (*i).second;
                    break;
                }
            }
        }

        res += (a[0] * 1000) + (a[1] * 100) + (a[2] * 10) + (a[3]);
    }

    return res;
}



    