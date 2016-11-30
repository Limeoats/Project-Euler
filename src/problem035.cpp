/* Problem 35: Circular primes
 * By: Mark Guerra
 * 12/7/2015
 */

#include "main.h"
#include "utils.h"

#include <algorithm>

/*
 * Loop around from [2] to [1000000] and determine if
 * the number is a circular prime. To do that,
 * check every rotation of the number and figure out
 * if it is a prime number. If all rotations are,
 * it is a prime number and hte count should increase.
 * Finally, return the count and print it.
 */

bool Problem035::isCircularPrime(int n) {
    if (!utils::isPrime(n)) {
        return false;
    }
    std::string str = utils::toString(n);
    std::string original = str;
    do {
        if (!utils::isPrime(atoi(str.c_str()))) {
            return false;
        }
        std::rotate(str.begin(), str.begin() + 1, str.end());
    } while(str != original);
    return true;
}

std::string Problem035::getAnswer() {
    int count = 0;
    for (int i = 2; i < 1000000; ++i) {
        if (isCircularPrime(i)) {
            count++;
        }
    }
    return std::to_string(count);
}
