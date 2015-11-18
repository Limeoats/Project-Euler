/* Problem 3: Largest prime factor
 * By: Mark Guerra
 * 10/19/2015
 */

#include "problem3.h"

#include <cmath>

long problem3::getGreatestPrimeFactor(long num) {
    long i = 2;
    while (pow(i, 2) < num) {
        while (num % i == 0) {
            num /= i;
        }
        i++;
    }
    return num;
}

long problem3::getAnswer() {
    return getGreatestPrimeFactor(600851475143L);
}