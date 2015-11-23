/* Problem 26: Reciprocal cycles
 * By: Mark Guerra
 * 11/23/2015
 */

#include "problem26.h"

/*
 *  The idea here is that the repeating sequence can't be
 *  longer than the denominator. Therefore, loop around
 *  [denominator] times for each number and get the remainders.
 *  Once the remainder gets to 1 again, that is the end of the
 *  repeating sequence.
 */

int problem26::getAnswer() {
    int highestCount;
    int highestDenom;
    for (int i = 2; i < 1000; i++) {
        int remainder = 1;
        for (int j = 0; j < i; j++) {
            remainder %= i;
            if (j > 0 && remainder == 1) {
                if (j > highestCount) {
                    highestCount = j;
                    highestDenom = i;
                }
                break;
            }
            remainder *= 10;
        }
    }
    return highestDenom;
}