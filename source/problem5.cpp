#include "problem5.h"

int problem5::getSmallestNumberDividedByRange(int begin, int end) {
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

int problem5::getAnswer() {
    return getSmallestNumberDividedByRange(1, 20);
}