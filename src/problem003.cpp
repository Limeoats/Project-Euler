/* Problem 3: Largest prime factor
 * By: Mark Guerra
 * 10/19/2015
 */

#include "main.h"

#include <cmath>

long Problem003::getGreatestPrimeFactor(long long num) {
    long i = 2;
    while (pow(i, 2) < num) {
        while (num % i == 0) {
            num /= i;
        }
        i++;
    }
    return num;
}

long Problem003::getAnswer() {
    return getGreatestPrimeFactor(600851475143);
}