#ifndef PROBLEM_7_H
#define PROBLEM_7_H

#include <cmath>

#include "utils.h"

//By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
//What is the 10 001st prime number?

namespace problem7 {

    int getNthPrimeNumber(int n) {
        int numPrimes = 0;
        int i = 1;
        while (numPrimes < n) {
            if (utils::isPrime(i)) {
                numPrimes++;
                if (numPrimes == n) {
                    return i;
                }
            }
            i++;
        }
        return i;
    }

    int getAnswer() {
        return getNthPrimeNumber(10001);
    }

}


#endif
