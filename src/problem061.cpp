/*
 * Problem 61: Cyclical figurate numbers
 * By: Mark Guerra
 * 12/5/2016
*/

#include <cmath>
#include "main.h"

bool Problem061::isNgonal(unsigned int n, unsigned int &x) const {
    auto t = (n - 4 + sqrt((pow(n, 2) + ((8*(n - 2)) * (x - 1))))) / (2 * (n - 2));
    return fmod(t, 1) == 0;
}

bool Problem061::isCyclic(int x, int y) const {
    return x % 100 == y / 100;
}

std::string Problem061::get_answer() {
    std::vector<unsigned int> triangleNumbers, squareNumbers, pentagonalNumbers,
            hexagonalNumbers, heptagonalNumbers, octagonalNumbers;
    for (unsigned int i = 1000; i <= 9999; ++i) {
        if (isNgonal(3, i)) triangleNumbers.push_back(i);
        if (isNgonal(4, i)) squareNumbers.push_back(i);
        if (isNgonal(5, i)) pentagonalNumbers.push_back(i);
        if (isNgonal(6, i)) hexagonalNumbers.push_back(i);
        if (isNgonal(7, i)) heptagonalNumbers.push_back(i);
        if (isNgonal(8, i)) octagonalNumbers.push_back(i);
    }
    std::vector<std::vector<unsigned int>> typeLists = {triangleNumbers, squareNumbers, pentagonalNumbers,
                                                hexagonalNumbers, heptagonalNumbers};
    for (auto &x1 : typeLists) {
        for (auto &val1 : octagonalNumbers) {
            for (auto &val2 : x1) {
                if (!this->isCyclic(val1, val2)) continue;
                for (auto &x2 : typeLists) {
                    if (x2 == x1) continue;
                    for (auto &val3 : x2) {
                        if (!isCyclic(val2, val3)) continue;
                        for (auto &x3 : typeLists) {
                            if (x3 == x2 || x2 == x1) continue;
                            for (auto &val4 : x3) {
                                if (!isCyclic(val3, val4)) continue;
                                for (auto &x4 : typeLists) {
                                    if (x4 == x3 || x4 == x2 || x4 == x1) continue;
                                    for (auto &val5 : x4) {
                                        if (!isCyclic(val4, val5)) continue;
                                        for (auto &x5 : typeLists) {
                                            if (x5 == x4 || x5 == x3 || x5 == x2 || x5 == x1) continue;
                                            for (auto &val6 : x5) {
                                                if (!isCyclic(val5, val6) || !isCyclic(val6, val1)) continue;
                                                int answer = val1 + val2 + val3 + val4 + val5 + val6;
                                                return std::to_string(answer);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return "";
}