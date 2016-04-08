/* Problem 27: Quadratic primes
 * By: Mark Guerra
 * 11/23/2015
 */

#include "problem027.h"

#include <math.h>
#include "utils.h"

/*
 * We start by looping through every possible
 * [a] and [b] value we will put in the equation.
 * We then increment [n] until the equation yields
 * a non-prime. When it does, if the number of
 * consecutive primes is higher than the last,
 * we store the number of primes and the [a] and [b]
 * values. Finally, the product of the highest [a] and [b]
 * is returned and printed.
 */

long problem027::getAnswer() {
    long hA = 0, hB = 0, hPrimes = 0;
    for (int i = -999; i < 1000; i++) {
        for (int j = -999; j < 1000; j++) {
            for (int n = 0; ; n++) {
                int x = (pow(n, 2) + (i * n) + j);
                if (utils::isPrime(x)) {
                    continue;
                }
                else {
                    if (n > hPrimes) {
                        hPrimes = n;
                        hA = i;
                        hB = j;
                    }
                    break;
                }
            }
        }
    }
    return hA * hB;
}