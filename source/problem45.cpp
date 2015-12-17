/* Problem 44: Pentagon numbers
 * By: Mark Guerra
 * 12/16/2015
 */

#include <math.h>
#include "problem45.h"

bool problem45::isPentagonal(int x) {
    double t = (sqrt(1.0 + 24.0 * x) + 1.0) / 6.0;
    return  t == int(t);
}

bool problem45::isHexagonal(int x) {
    double t = (sqrt(1.0 + 8.0 * x) + 1.0) / 4.0;
    return t == int(t);
}

bool problem45::isTriangle(int x) {
    double t = (sqrt(1.0 + 8.0 * x) - 1.0) / 2.0;
    return t == int(t);
}

long problem45::getAnswer() {
    int n = 40755;
    while (true) {
        if (isTriangle(n) && isPentagonal(n) && isHexagonal(n)) {
            return long((n / 2) * (n + 1));
        }
        n++;
    }
}
