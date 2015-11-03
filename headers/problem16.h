#ifndef PROBLEM_16_H
#define PROBLEM_16_H

//2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
//What is the sum of the digits of the number 2^1000?

#include <cmath>


namespace problem16 {

    long long sumOfDigits(long long number) {
        long long n = number;
        long long sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    long long getAnswer() {
        return sumOfDigits(pow(2, 1000));
    }
}

#endif