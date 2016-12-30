/*
 * Problem 63: Powerful digit counts
 * By: Mark Guerra
 * 12/7/2016
*/

#include "main.h"

/*
 * Create a [counter] and initialize it to 0. Loop through the numbers 1 - 9, since
 * any two (or higher) digit base to any power will never have [e] number of digits.
 * 10 ^ 1 == 10, which is wrong, and 10 ^ 2 == 100, which is already wrong. This pattern
 * continues for two or more digit numbers. Start an exponent loop that increments the
 * exponent every time around. If the length of [i] ^ [e] is equal to [e], increment the
 * counter. Otherwise, break out of the loop so that the base can be incremented.
 * After the base's loop is done, counter has the answer. Return and print it.
*/

std::string Problem063::getAnswer() {
    int counter = 0;
    for (BigNumber i = 1; i < 10; ++i) {
        for (int e = 1;; ++e) {
            if (i.pow(e).digits() == e) ++counter;
            else break;
        }
    }
    return std::to_string(counter);
}