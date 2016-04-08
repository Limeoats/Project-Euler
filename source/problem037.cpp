/* Problem 37: Truncatable primes
 * By: Mark Guerra
 * 12/7/2015
 */

#include "problem037.h"
#include "utils.h"

#include <string>
#include <algorithm>

/*
 * Keep looping starting at [11] until 11 truncatable primes are found.
 * To check if a prime is truncatable, loop around and remove the first
 * character from [str] and the last character from [str2] until only
 * one digit remains. Each time around that loop, if the resulting number
 * is prime, then [i] is a truncatable prime and gets added to the sum.
 * Finally, return the sum and print it.
 */

bool problem037::isTruncatable(int n) {
    std::string str = utils::toString(n);
    std::string str2 = str;
    int numDigits = utils::numDigits(n) - 1;
    for (int i = 0; i < numDigits; i++) {
        str.erase(0, 1);
        str2.erase(str2.size() - 1);
        if (!utils::isPrime(atoi(str.c_str())) || !utils::isPrime(atoi(str2.c_str()) )) {
            return false;
        }
    }
    return true;
}

int problem037::getAnswer() {
    int sum = 0;
    for (int i = 11, count = 0; count < 11; i++) {
        if (utils::isPrime(i) && isTruncatable(i)) {
            sum += i;
            count++;
        }
    }
    return sum;
}