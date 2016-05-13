/* Problem 16: Power digit sum
 * By: Mark Guerra
 * 11/5/2015
 */


#ifndef PROBLEM_016_H
#define PROBLEM_016_H

//2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
//What is the sum of the digits of the number 2^1000?

#include "bignumber.h"


namespace problem016 {
    long sumOfDigits(BigNumber number, int power);
    long getAnswer();
}

#endif