/*
 * Problem 16: Power digit sum
 * By: Mark Guerra
 * 11/5/2015
 */


#include "main.h"

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

long Problem016::sumOfDigits(BigNumber number, int power) {
    BigNumber value = number.pow(power);
    long total = 0;
    for (char c : value.getString()) {
        total += (c - '0');
    }
    return total;
}

std::string Problem016::getAnswer() {
    BigNumber b = 2;
    return std::to_string(sumOfDigits(b, 1000));
}