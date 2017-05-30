/*
 * Problem 67: Maximum path sum II
 * By: Mark Guerra
 * 12/12/2016
*/

#include <fstream>
#include "main.h"
#include "utils.h"

/*
 * Exact same solution as Problem 18.
 * Start by reading in all of the data line by line. Loop through each row and
 * split the numbers by a space. Make all of the rows the same length by adding 0's
 * to the end of each of the shorter rows. Then, turn each number into an integer and add
 * it to [numbers]. We then create an array that will contain the highest number from
 * each row. Initialize the row's highest number to the first number. Then, starting at the bottom,
 * loop through each row and each column, determining the highest numbers. Return the highest and print.
*/

std::string Problem067::get_answer() {
    std::vector<std::string> lines;
    std::string line;
    std::ifstream in("data/problem67_data.txt");
    if (in.fail()) {
        std::cerr << "Unable to open file" << std::endl;
        return "";
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
    return std::to_string(largestNumbers[0]);
}