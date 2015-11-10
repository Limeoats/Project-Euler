#include "problem16.h"

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

long problem16::sumOfDigits(BigNumber number, int power) {
    BigNumber value = number.pow(power);
    long total = 0;
    for (char c : value.getString()) {
        total += (c - '0');
    }
    return total;
}

long problem16::getAnswer() {
    BigNumber b("2");
    return sumOfDigits(b, 1000);
}