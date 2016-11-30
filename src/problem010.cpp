/*
 * Problem 10: Summation of primes
 * By: Mark Guerra
 * 10/19/2015
 */

#include "main.h"
#include "utils.h"

long Problem010::getSumOfPrimesBelowNum(int num) {
    long total = 2;
    for (int i = 3; i < num; i += 2) {
        if (utils::isPrime(i)) {
            total += i;
        }
    }
    return total;
}

std::string Problem010::getAnswer() {
    return std::to_string(getSumOfPrimesBelowNum(2000000));
}