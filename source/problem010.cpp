/* Problem 10: Summation of primes
 * By: Mark Guerra
 * 10/19/2015
 */

#include "problem010.h"
#include "utils.h"

long problem010::getSumOfPrimesBelowNum(int num) {
    long total = 2;
    for (int i = 3; i < num; i += 2) {
        if (utils::isPrime(i)) {
            total += i;
        }
    }
    return total;
}

long problem010::getAnswer() {
    return getSumOfPrimesBelowNum(2000000);
}