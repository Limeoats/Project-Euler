/* Problem 40: Champernowne's constant
 * By: Mark Guerra
 * 12/9/2015
 */

#include "main.h"
#include "utils.h"

#include <sstream>

/*
 * The indices of the digits we want from Champernowne's constant
 * are 7 multiples of 10. Therefore, we start [total] at 1 (the first digit)
 * and loop around 6 times, each time multiplying the index by 10. The first time
 * we get a digit from Champernowne's constant, we first need to generate the number.
 * 1000000 of the numbers are generated, so there are plenty of digits. We then simply
 * get the index we want from the number and return it.
 * Finally, the product of those digits is returned and displayed.
 */

std::string c = "";

int Problem040::getDigitInChampernowneConstant(int n) {
    if (c.empty()) {
        std::stringstream ss;
        for (int i = 1; i < 1000000; i++) {
            ss << i;
        }
        c = ss.str();
    }
    return c[n-1] - '0';
}

std::string Problem040::getAnswer() {
    int n = 1, total = 1;
    for (int i = 0; i < 6; i++) {
        total *= getDigitInChampernowneConstant((n *= 10));
    }
    return std::to_string(total);
}
