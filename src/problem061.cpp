/*
 * Problem 61: Cyclical figurate numbers
 * By: Mark Guerra
 * 12/5/2016
*/

#include <cmath>
#include "main.h"

bool Problem061::isNgonal(unsigned int n, unsigned int &x) const {
    auto t = (sqrt(x * (8 * n - 16) + pow(n - 4, 2)) + n - 4) / (2 * n - 4);
    return fmod(t, 1) == 0;
}

std::string Problem061::getAnswer() {
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
    std::cout << triangleNumbers.size() << std::endl;
    return "";
}