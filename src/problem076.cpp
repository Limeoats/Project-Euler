/*
 * Problem 76: Counting summations
 * By: Mark Guerra
 * 12/19/2016
*/

#include "main.h"

/*
 * For this problem, I noticed that I needed to create a partition function.
 * I used recursion for this. When the recursive function is finished,
 * the value in [_vals[100, 99]] is the total number of summations, so return and print it.
*/

Problem076::Problem076() {
    std::fill(&this->_vals[0][0], &this->_vals[0][0] + sizeof(this->_vals) / sizeof(this->_vals[0][0]), 0);
}

int Problem076::partition(int n, int nm) {
    if (n == 0) return 1;
    if (nm == 0 || n < 0) return 0;
    if (this->_vals[n][nm] != 0)
        return _vals[n][nm];
    this->_vals[n][nm] = this->partition(n, nm - 1) + this->partition(n - nm, nm);
    return this->_vals[n][nm];
}

std::string Problem076::getAnswer() {
    const int LIMIT = 100;
    return std::to_string(this->partition(LIMIT, LIMIT - 1));
}