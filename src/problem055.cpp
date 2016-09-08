/*
 * Problem 55: Lychrel numbers
 * By: Mark Guerra
 * 9/8/2016
*/

#include "utils.h"
#include "problem055.h"


int problem055::getAnswer() {
    int c = 0;
    for (unsigned int i = 10; i < 10000; ++i) {
        c += utils::isLychrel(i);
    }
    return c;
}