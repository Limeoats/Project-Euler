/* Problem 43: Sub-string divisibility
 * By: Mark Guerra
 * 12/16/2015
 */

#include "main.h"
#include "utils.h"

#include <sstream>

/*
 * The very first permutation is 0123456789.
 * Then, for each permutation of that number [str],
 * start by checking if the last 3 digits are not divisible by 17.
 * If they are not, skip that permutation and move on to the next one.
 * If they are, check all of the digits to see if they are divisible
 * by their respective numbers. If they are not, move on to the next one.
 * If all of the sets of digits are divisible by their numbers in [divs],
 * add the entire permutation to the sum.
 * Finally, return the sum and print it.
 */


std::string Problem043::getAnswer() {
    BigNumber sum = BigNumber("0");
    int divs[6] = {2, 3, 5, 7, 11, 13};
    std::string str = "0123456789";
    do {
        if (atoi(str.substr(str.size() - 3, str.size() - 1).c_str()) % 17 != 0) continue;
        bool divisible = true;
        for (int j = 0; j < 6; ++j) {
            std::stringstream ss;
            ss << str[j + 1] << str[j + 2] << str[j + 3];
            if (atoi(ss.str().c_str()) % divs[j] != 0) {
                divisible = false;
                break;
            }
        }
        if (divisible) {
            sum += BigNumber(str);
        }
    } while (std::next_permutation(str.begin(), str.end()));

    return sum.getString();
}