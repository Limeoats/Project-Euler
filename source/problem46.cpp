/* Problem 46: Goldbach's other conjecture
 * By: Mark Guerra
 * 12/17/2015
 */

#include "problem46.h"
#include "utils.h"

#include <vector>
#include <cmath>

/*
 * First, generate the first 5000 primes and store them in [primes].
 * Then, loop through all odd composite numbers. If any combination of
 * the primes up to [x] + 2 * any number up to the square root of [x] equals
 * [x], then move on to the next number. Once one is found where this does not happen,
 * return it and print it to the screen.
 */

int problem46::getAnswer() {
    int x = 3;
    bool found;
    std::vector<long> primes = utils::generatePrimes(5000);
    while (true) {
        found = false;
        x += 2;
        if (utils::isPrime(x)) continue;
        for (int i = 0; i < primes.size(); ++i) {
            if (primes[i] > x) break;
            for (int j = 1; j < sqrt(x); ++j) {
                if (primes[i] + (2 * (j * j)) == x) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (!found) {
            return x;
        }
    }
}