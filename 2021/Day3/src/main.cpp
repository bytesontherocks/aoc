
#include "measurements.hpp"
#include <filesystem>

int main (void)
{
    
    std::ifstream input_file;
    // auto path = std::filesystem::current_path().string();
    // path.append("input.txt");
    //  std::cout << "Path " << path << std::endl;    

    input_file.open("/home/aos_dev/source/repos/aoc/Day3/src/input.txt", std::ios::out);

    if (!input_file.is_open()) {
        std::cerr << "Error opening" << std::endl;
        return 1;
    }    

    std::cout << "First exercice result: " << measurements::calculateFirstExercice(input_file) << std::endl;  

    // reading state back to the start
    input_file.clear();
    input_file.seekg(0, std::ios::beg);

    std::cout << "Second exercice result: " << measurements::calculateSecondExercice(input_file) << std::endl;  

    return 0;
}