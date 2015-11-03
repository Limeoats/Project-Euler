#ifndef PROBLEM_10_H
#define PROBLEM_10_H

#include "utils.h"

//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//Find the sum of all the primes below two million.


namespace problem10 {

    long getSumOfPrimesBelowNum(int num) {
        long total = 2;
        for (int i = 3; i < num; i += 2) {
            if (utils::isPrime(i)) {
                total += i;
            }
        }
        return total;
    }

    long getAnswer() {
        return getSumOfPrimesBelowNum(2000000);
    }

}


#endif
