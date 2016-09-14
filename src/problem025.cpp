/* Problem 25: 1000-digit Fibonacci number
 * By: Mark Guerra
 * 11/23/2015
 */

#include "main.h"

int Problem025::getAnswer() {
    int index = 2;
    BigNumber b("1"), c("1"), tmp("1");
    while (c.digits() < 1000) {
        tmp = c;
        c = b + c;
        b = tmp;
        index++;
    }
    return index;
}