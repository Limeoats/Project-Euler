/*
 * Problem 56: Powerful digit sum
 * By: Mark Guerra
 * 9/12/2016
 */

#include "main.h"
#include "utils.h"

/*
 * Start by creating a variable to keep track of the highest sum [highest].
 * Then, loop through every possible [a] value < 100 (given) and
 * loop through each power from 1-100 [b] (given). Do a^b for each
 * combination and calculate the digit sum of the result. If
 * the digit sum is greater than [highest], replace [highest] with
 * the new value. Finally, return [highest] and print it.
 */

std::string Problem056::get_answer() {
    int highest = 0;
    BigNumber bn = 1;
    for (int a = 2; a < 100; ++a) {
        bn.setString("1");
        for (int b = 1; b < 100; ++b) {
            bn *= BigNumber(std::to_string(a));
            highest = std::max(utils::digitSum(bn.getString()), highest);
        }
    }
    return std::to_string(highest);
}


