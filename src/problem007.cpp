/*
 * Problem 7: 10001st prime
 * By: Mark Guerra
 * 10/19/2015
 */

#include "main.h"
#include "utils.h"

#include <cmath>

int Problem007::getNthPrimeNumber(int n) {
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

std::string Problem007::get_answer() {
    return std::to_string(getNthPrimeNumber(10001));
}