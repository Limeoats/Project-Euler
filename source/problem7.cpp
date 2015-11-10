#include "problem7.h"
#include "utils.h"

#include <cmath>

int problem7::getNthPrimeNumber(int n) {
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

int problem7::getAnswer() {
    return getNthPrimeNumber(10001);
}