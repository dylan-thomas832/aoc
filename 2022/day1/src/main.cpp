#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

const std::string EMPTY_LINE = "";

int main(int narg, char const *argv[])
{
    if ( narg < 2 ) {
        std::cout<< "Must provide the input file as the first CLI argument" << std::endl;
        return -1;
    }

    const std::string filename = argv[1];
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Unable to open file: " + filename << std::endl;
        return -1;
    }

    int current_calorie_sum = 0;
    std::vector<int> calorie_counts;
    // Read input file stream line-by-line
    for (std::string line; getline(file, line);) {
        if (line == EMPTY_LINE) {
            // New line indicates new Elf's inventory. Add count and reset sum
            calorie_counts.push_back(current_calorie_sum);
            current_calorie_sum = 0;
        }
        else {
            // Increment the calorie count
            current_calorie_sum += std::stoi(line);
        }
    }
    
    // Find the maximum calories and the corresponding elf
    auto max_calories = std::max_element(calorie_counts.begin(), calorie_counts.end());
    auto elf = std::distance(calorie_counts.begin(), max_calories);
    std::cout << "The elf at " << elf << " has " << *max_calories << " calories" << std::endl;

    return 0;
}

