/* Problem 20: Factorial digit sum
 * By: Mark Guerra
 * 11/19/2015
 */

#ifndef PROBLEM_020_H
#define PROBLEM_020_H

#include "bignumber.h"

/*
 * n! means n × (n − 1) × ... × 3 × 2 × 1
 * For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
 * and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 * Find the sum of the digits in the number 100!
 */

namespace problem020 {
    BigNumber factorial(int n);
    long getAnswer();
}

#endif