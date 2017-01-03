/*
 * Problem 72: Counting fractions
 * By: Mark Guerra
 * 12/14/2016
*/

#include "main.h"
#include "utils.h"

/*
 * I used an algorithm for getting the length of the Farey Sequence where n = 1,000,000.
 * The summation of 1 + (phi([m]) from 1 to n) gives the length of the sequence.
 * Once the sum is found, return it and print.
*/

std::string Problem072::getAnswer() {
    const int LIMIT = 1000000;
    std::vector<long> phiList = utils::generatePhi(LIMIT + 2);
    long sum = 0;
    for (int i = 2; i < LIMIT; ++i) {
        sum += phiList[i];
    }
    return std::to_string(sum);
}