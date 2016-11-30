/* Problem 50: Consecutive prime sum
 * By: Mark Guerra
 * 12/21/2015
 */

#include "main.h"
#include "utils.h"

#include <vector>
#include <iostream>

/*
 * Start by generating all primes up to 1000000.
 * Then, compute the sum of all consecutive prime numbers
 * until [sum] reaches the limit (1000000). Then, if [sum]
 * is not a prime number, remove the lowest primes one by one
 * and add the next largest prime until [sum] is prime.
 * Finally, return sum and print it to the screen.
 */

namespace {
    const int LIMIT = 1000000;
}

std::string Problem050::getAnswer() {
    std::vector<long> allPrimes = utils::generatePrimes(LIMIT);
    int sum = 0, i = 0;
    for (i; sum + allPrimes[i] < LIMIT; ++i) {
        sum += allPrimes[i];
    }
    int start = 0, end = i;
    for (; !utils::isPrime(sum); ++start) {
        sum -= allPrimes[start];
        while (sum + allPrimes[end] < LIMIT) {
            sum += allPrimes[end];
            ++end;
        }
        end = i;
    }
    return std::to_string(sum);
}