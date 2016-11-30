/*
 * Problem 5: Smallest multiple
 * By: Mark Guerra
 * 10/19/2015
 */

#include "main.h"

int Problem005::getSmallestNumberDividedByRange(int begin, int end) {
    long c = 1;
    int successes = 0;
    while (true) {
        for (long i = begin; i < end; i++) {
            if (c % i != 0)
                break;
            else
                successes++;
        }
        if (successes != end - begin) {
            successes = 0;
            c++;
        }
        else {
            return c;
        }
    }
}

std::string Problem005::getAnswer() {
    return std::to_string(getSmallestNumberDividedByRange(1, 20));
}