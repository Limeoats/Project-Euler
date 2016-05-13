/* Problem 7: 10001st prime
 * By: Mark Guerra
 * 10/19/2015
 */

#include "problem007.h"
#include "utils.h"

#include <cmath>

int problem007::getNthPrimeNumber(int n) {
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

int problem007::getAnswer() {
    return getNthPrimeNumber(10001);
}