/* Problem 44: Pentagon numbers
 * By: Mark Guerra
 * 12/16/2015
 */

#include "problem45.h"

#include <cmath>

bool problem45::isPentagonal(int x) {
    double t = (sqrt(1.0 + 24.0 * x) + 1.0) / 6.0;
    return  t == int(t);
}

bool problem45::isTriangle(int x) {
    double t = (sqrt(1.0 + 8.0 * x) - 1.0) / 2.0;
    return t == int(t);
}

long problem45::getAnswer() {
    int n = 286;
    while (true) {
        int hex = (2 * n - 1) * n;
        if (isPentagonal(hex) && isTriangle(hex)) {
            return hex;
        }
        ++n;
    }
}
