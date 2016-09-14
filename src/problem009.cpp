/* Problem 9: Special Pythagorean triplet
 * By: Mark Guerra
 * 10/19/2015
 */

#include "main.h"

#include <cmath>

double Problem009::getProductOfPythagoreanTriplet(int sumOfABC) {
    for (int a = 1; a < 499; a++) {
        for (int b = 1; b < 499; b++) {
            double c = sqrt(pow(a, 2) + pow(b, 2));
            if (a + b + c == 1000 && (a < b) && (b < c)) {
                return a * b * c;
            }
        }
    }
    return -1;
}

int Problem009::getAnswer() {
    return getProductOfPythagoreanTriplet(1000);
}