/* Problem 22: Name scores
 * By: Mark Guerra
 * 11/19/2015
 */

#include "problem22.h"
#include "utils.h"

#include <fstream>

BigNumber problem22::getAnswer() {
    std::vector<std::string> lines;
    std::string line;
    std::ifstream in("data/problem22_data.txt");
    if (in.fail()) {
        std::cerr << "Unable to open file" << std::endl;
        exit(1);
    }
    while (!in.eof()) {
        getline(in, line);
        lines.push_back(line);
    }
    in.close();
    std::stringstream ss;
    for (int i = 0; i < int(lines.size()); i++) {
        ss << lines[i];
    }
    std::string str = ss.str();
    utils::replace(str, "\",\"", "|");
    str.erase(std::remove(str.begin(), str.end(), '\"'), str.end());

    std::vector<std::string> names = utils::split(str, '|');
    std::sort(names.begin(), names.end(), [](std::string a, std::string b) { return a < b; });

    BigNumber total("0");
    for (int i = 0; i < int(names.size()); i++) {
        int lTotal = 0;
        for (char c : names[i]) {
            lTotal += getAlphabetPos(char(tolower(c)));
        }
        total += BigNumber(utils::toString(lTotal * (i+1)));
    }
    return total;
}