/* Problem 42: Coded triangle number
 * By: Mark Guerra
 * 12/11/2015
 */

#include "problem42.h"
#include "utils.h"

#include <fstream>
#include <sstream>
#include <vector>
#include <array>

/*
 * First, load the text file with all of the words into the program.
 * Remove all quotation marks from the string and then split on the commas.
 * Then generate the first 100 triangle numbers. Since there are no
 * extremely long words, 100 is plenty of numbers. We then loop through
 * each word in the [words] vector and calculate its word value. If that number
 * is in the list of triangle numbers we generated, increase [count].
 * Finally, return count and print it to the screen.
 */

int problem42::getAnswer() {
    std::ifstream in("data/problem42_data.txt");
    std::stringstream ss;
    ss << in.rdbuf();
    std::string str = ss.str();
    str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());
    std::vector<std::string> words = utils::split(str, ',');

    std::array<int, 100> triangleNumbers;
    triangleNumbers[0] = 0;
    for (double i = 1; i < 100; i++) {
        triangleNumbers[i] = int((i / 2) * (i + 1));
    }

    int count = 0;
    for (std::string str : words) {
        int lTotal = 0;
        for (char c : str) {
            lTotal += getAlphabetPos(char(tolower(c)));
        }
        if (lTotal != 0 && std::find(triangleNumbers.begin(), triangleNumbers.end(), lTotal) != triangleNumbers.end()) {
            count++;
        }
    }
    return count;

}