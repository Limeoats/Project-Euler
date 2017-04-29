/*
 * Problem 81: Path sum: two ways
 * By: Mark Guerra
 * 4/3/2017
*/

#include "main.h"
#include "utils.h"
#include <fstream>

/*
 * I used dynamic programming very similar to problems 18 and 67 to solve this
 * problem. The idea is to start at the end (bottom-right) and figure out
 * the sums of all of the numbers along the edges. Then, starting from
 * the second to last number and working back towards the beginning,
 * we add the minimum of the up and left directions. When the top
 * left is reached and added to, it contains the result. Return it and print.
*/

std::string Problem081::getAnswer() {
    std::vector<std::string> lines;
    std::string line;
    std::ifstream in("data/problem81_data.txt");
    if (in.fail()) {
        std::cerr << "Unable to open file" << std::endl;
        return "";
    }
    while (!in.eof()) {
        getline(in, line);
        lines.push_back(line);
    }
    in.close();
    std::vector<std::vector<int>> numbers(lines.size());
    for (auto i = 0; i < lines.size(); ++i) {
        auto t = utils::split(lines[i], ',');
        std::vector<int> c;
        for (auto x : t) {
            c.push_back(atoi(x.c_str()));
        }
        numbers[i] = c;
    }
    long a = numbers.size() - 1, b = numbers[a].size() - 1;
    for (a = numbers.size() - 1; b >= 1; --b) {
        numbers[a][b - 1] += numbers[a][b];
    }
    for (b = numbers[a].size() - 1; a >= 1; --a) {
        numbers[a - 1][b] += numbers[a][b];
    }
    for (a = numbers.size() - 2; a >= 0; --a) {
        for (b = numbers[a].size() - 2; b >= 0; --b) {
            numbers[a][b] += std::min(numbers[a + 1][b], numbers[a][b + 1]);
        }
    }
    return std::to_string(numbers[0][0]);
    
}