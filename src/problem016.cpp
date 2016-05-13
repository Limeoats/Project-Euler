/* Problem 16: Power digit sum
 * By: Mark Guerra
 * 11/5/2015
 */


#include "problem016.h"

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>

long problem016::sumOfDigits(BigNumber number, int power) {
    BigNumber value = number.pow(power);
    long total = 0;
    for (char c : value.getString()) {
        total += (c - '0');
    }
    return total;
}

long problem016::getAnswer() {
    BigNumber b("2");
    return sumOfDigits(b, 1000);
}