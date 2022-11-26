#include "measurements.hpp"
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <array>

// decide best way to deal with the input
    // load selected numbers in a vector
    // load board in arrays
namespace {

    constexpr size_t bingoCardSize = 5;

    auto getBingoNumbers(std::ifstream& input) {

        std::string line { "" };

        std::vector<size_t>v;

        while (std::getline(input, line)) {

            if (line.empty()) {
                std::cout << "Empty line found" << std::endl;
                break;
            } else {
                size_t pos = 0;
                std::string delimiter = ",";
                std::string s;

                while ((pos = line.find(delimiter, 0)) != std::string::npos) {
                    s = line.substr(0, pos);
                    line.erase(0, pos + delimiter.length());
                    v.push_back(std::stoi(s));
                }  

                // last element  
                s = line.substr(0, pos);
                v.push_back(std::stoi(s));
            }
        }        

        return v;
    }

    struct BingoNumber
    {
        size_t number;
        bool called = false;
    };

    class BingoCard
    {
        public:
            std::vector<BingoNumber>v[bingoCardSize];

            size_t checkIfBingo(const size_t num) {
                size_t bingo = 0;

                for (auto i = 0; i < bingoCardSize; ++i) {
                    for (auto it = v[i].begin(); it != v[i].end(); ++it) {
                        if ((*it).number == num) {
                            (*it).called = true;  

                            //check row
                            bingo = checkRow(i);
                            if (bingo != 0 ) {
                                bingo *= num;
                                return bingo;
                            }

                            //check line   
                            bingo = checkCol(it - v[i].begin());
                            if (bingo != 0 ) {
                                bingo *= num;
                                return bingo;
                            }      
                        }
                    }
                }

                return bingo;
            }
        
        private:
            size_t checkRow(const size_t vectorRow) {
                
                size_t res = 1;

                for (auto r = v[vectorRow].begin(); r != v[vectorRow].end(); ++r) {
                    if ((*r). called == false) {
                        res = 0;
                        break;
                    } 
                }
                if (res)
                    res = sumOfUnmarkedNumbers();

                return res;
            }

            size_t checkCol(const size_t vectorColumn) {
                
                size_t res = 1;

                for (auto i = 0; i < bingoCardSize; ++i) {
                    if (v[i].at(vectorColumn).called == false) {
                        res = 0;
                        break;
                    } 
                }

                if (res)
                    res = sumOfUnmarkedNumbers();

                return res;
            }

            size_t sumOfUnmarkedNumbers()
            {
                size_t res = 0;
                for (auto i = 0; i < bingoCardSize; ++i) {
                    for (auto it = v[i].begin(); it != v[i].end(); ++it) {
                        if ((*it).called == false)
                            res +=  (*it).number;
                    }
                }

                return res;
            }
    };

    auto getBingoCard(std::ifstream& input) {
        std::string line { "" };

        auto bc = BingoCard();

        uint32_t arrayRow = 0;

        while (std::getline(input, line)) {

            if (line.empty()) {
                break;
            }

            size_t pos = 0;
            std::string delimiter = " ";
            std::string s;            

            while ((pos = line.find(delimiter, 0)) != std::string::npos) {

                s = line.substr(0, pos);
                line.erase(0, pos + delimiter.length());

                if (!s.empty())
                {
                    auto bn = BingoNumber();
                    bn.called = false;
                    bn.number = std::stoi(s);

                    bc.v[arrayRow].push_back(bn);
                }
            }  

            // last element  
            s = line.substr(0, pos);
            auto bn = BingoNumber();
            bn.called = false;
            bn.number = std::stoi(s);
            bc.v[arrayRow].push_back(bn);

            arrayRow++;

        }

        return bc;
    }

}              

int64_t measurements::calculateFirstExercice(std::ifstream& input)
{
    auto v = getBingoNumbers(input);

    std::vector<BingoCard> vBc;

    while (input.peek() != EOF) {
        auto bc = getBingoCard(input);
        vBc.push_back(bc);
    }

    for (auto number = v.begin(); number != v.end(); ++number) {
        for (auto it = vBc.begin(); it != vBc.end(); ++it) {
            auto res = (*it).checkIfBingo(*number);
            if (res != 0)
                return res;
        }
    }
       
    return 0;
}

int64_t measurements::calculateSecondExercice(std::ifstream& input)
{
    auto v = getBingoNumbers(input);

    // bool to discard bingo card in case wins. That could be optimise becase card still considered.
    std::vector<std::pair<BingoCard,bool>> vBc;

    while (input.peek() != EOF) {
        auto bc = getBingoCard(input);
        vBc.push_back(std::make_pair(bc, false));
    }

   std::vector<size_t>minRes;
    for (auto number = v.begin(); number != v.end(); ++number) {
        for (auto it = vBc.begin(); it != vBc.end(); ++it) {
            auto res = (*it).first.checkIfBingo(*number);
            if ((res != 0) && ((*it).second == false)) {
               minRes.push_back(res);
               (*it).second = true;
            }
        }
    }
       
    return minRes.back();
}


    
    