/*
 * Problem 82: Path sum: three ways
 * By: Mark Guerra
 * 5/3/2017
*/

#include <fstream>
#include "main.h"
#include "utils.h"

/*
 * The program starts by reading in and parsing the data file. The numbers
 * are stored in a 2D vector [_original]. Another 2D vector [_tmp] is initialized
 * with the same values as [_original]. [_tmp] will contain the cumulative values
 * of the min paths found. We fill up [_tmp] starting from the second to last column
 * and going left. Once all of the minPaths are found and stored in _tmp,
 * the minimum value is the answer. Return it and print.
 */

int Problem082::minPath(int y, int x) {
    std::vector<int> cumulative(this->_original.size());
    for (int i = y - 1, sum = this->_original[y][x]; i >= 0; --i) {
        cumulative[i] = (sum += this->_original[i][x]) + this->_tmp[i][x + 1];
    }
    cumulative[y] = this->_original[y][x] + this->_tmp[y][x + 1];
    for (int i = y + 1, sum = this->_original[y][x]; i < this->_original.size(); ++i) {
        cumulative[i] = (sum += this->_original[i][x]) + this->_tmp[i][x + 1];
    }
    return *std::min_element(std::begin(cumulative), std::end(cumulative));
}

std::string Problem082::getAnswer() {
    std::vector<std::string> lines;
    std::string line;
    std::ifstream in("data/problem82_data.txt");
    while (!in.eof()) {
        getline(in, line);
        lines.push_back(line);
    }
    in.close();
    this->_original = std::vector<std::vector<int>>(lines.size());
    for (auto i = 0; i < lines.size(); ++i) {
        auto t = utils::split(lines[i], ',');
        std::vector<int> c;
        for (auto x : t) {
            c.push_back(atoi(x.c_str()));
        }
        this->_original[i] = c;
    }
    this->_tmp.assign(this->_original.begin(), this->_original.end());
    for (int x = this->_original.size() - 2; x >= 0; --x) {
        for (int y = 0; y < this->_original.size(); ++y) {
            this->_tmp[y][x] = this->minPath(y, x);
        }
    }
    int result = this->_tmp[0][0];
    for (int i = 1; i < this->_original.size(); ++i) {
        result = std::min(result, this->_tmp[i][0]);
    }
    return std::to_string(result);
}
