/* Problem 22: Name scores
 * By: Mark Guerra
 * 11/19/2015
 */

#include "problem022.h"
#include "utils.h"

#include <fstream>

int problem022::getAnswer() {
    std::ifstream in("data/problem22_data.txt");
    std::stringstream ss;
    ss << in.rdbuf();
    std::string str = ss.str();
    str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());

    std::vector<std::string> names = utils::split(str, ',');
    std::sort(names.begin(), names.end(), [](std::string a, std::string b) { return a < b; });

    int total = 0;
    for (int i = 0; i < int(names.size()); i++) {
        int lTotal = 0;
        for (char c : names[i]) {
            lTotal += getAlphabetPos(char(tolower(c)));
        }
        total += lTotal * (i + 1);
    }
    return total;
}