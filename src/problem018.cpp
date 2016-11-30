/*
 * Problem 18: Maximum path sum 1
 * By: Mark Guerra
 * 11/10/2015
 */


#include "main.h"
#include "utils.h"

#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>


int Problem018::getMaxSum() {
    std::vector<std::string> lines;
    std::string line;
    std::ifstream in("data/problem18_data.txt");
    if (in.fail()) {
        std::cerr << "Unable to open file" << std::endl;
        return -1;
    }
    while (!in.eof()) {
        getline(in, line);
        lines.push_back(line);
    }
    in.close();
    const int N_ROWS = lines.size();
    std::vector<std::vector<int>> numbers;
    for (int i = 0; i < N_ROWS; i++) {
        std::vector<std::string> splitNums = utils::split(lines.at(i), ' ');
        while (splitNums.size() < N_ROWS) {
            splitNums.push_back("0");
        }
        std::vector<int> nums;
        for (int i = 0; i < splitNums.size(); i++) {
            nums.push_back(atoi(splitNums[i].c_str()));
        }
        numbers.push_back(nums);
    }
    //numbers is now a vector containing each row
    int largestNumbers[N_ROWS];
    //Initialize largestNumbers
    for (int i = 0; i < N_ROWS; i++) {
        largestNumbers[i] = numbers[N_ROWS - 1][i];
    }
    //We need to start at the second to last row
    //The idea is to add and figure out the max of each small triangle of 3
    //Then use that new value and work up the triangle to the top
    //By the time we get to the top, there is only one value and that is the sum
    for (int i = N_ROWS - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            largestNumbers[j] = numbers[i][j] + std::max(largestNumbers[j], largestNumbers[j + 1]);
        }
    }
    return largestNumbers[0];

}


std::string Problem018::getAnswer() {
    return std::to_string(getMaxSum());
}