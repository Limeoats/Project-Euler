/*
 * Problem 56: Powerful digit sum
 * By: Mark Guerra
 * 9/12/2016
 */

#include "problem056.h"
#include "bignumber.h"
#include "utils.h"

long problem056::getAnswer() { 
    int highest = 0;
    BigNumber bn("1");
    for (int a = 2; a < 100; ++a) {
        bn.setString("1");
        for (int b = 1; b < 100; ++b) {
            bn *= BigNumber(std::to_string(a));
            highest = std::max(utils::digitSum(bn.getString()), highest);
        }
    }
    return highest;
}


