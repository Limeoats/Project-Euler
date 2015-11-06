#ifndef PROBLEM_16_H
#define PROBLEM_16_H

//2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
//What is the sum of the digits of the number 2^1000?

#include <cmath>
#include <string>
#include <cstdlib>

#include "bignumber.h"


namespace problem16 {

    long sumOfDigits(BigNumber number, int power) {
        BigNumber value = number^power;
        long total = 0;
        for (char c : value.getString()) {
            total += (c - '0');
        }
        return total;
    }

    long getAnswer() {
        BigNumber b("2");
        return sumOfDigits(b, 1000);
    }
}

#endif