/* Problem 38: Pandigital multiples
 * By: Mark Guerra
 * 12/8/2015
 */

#include "problem38.h"
#include "utils.h"

/*
 * To solve this problem, we need to loop from [1] to [10000].
 * The exact upper bound is unclear, but going much higher than
 * [10000] will result in products too large for 9 digits.
 * For every integer [i], we multiply another integer [j] and
 * concatenate that product to [result]. Once [result] reaches
 * 9 digits, we check if the number is pandigital. If it is and
 * it is greater than the highest we have stored, we store it.
 * Finally, print [highest].
 */

bool problem38::isPandigital(std::string n) {
    int len = n.size();
    for (int i = 1; i <= len; ++i) {
        if (n.find(i + '0') == std::string::npos)
            return false;
    }
    return true;
}

int problem38::getAnswer() {
    int highest = 0;
    for (int i = 1; i < 10000; ++i) {
        std::string result = "";
        for (int j = 1; ; ++j) {
            result += utils::toString(i*j);
            if (result.size() > 9) {
                break;
            }
            if (result.size() == 9) {
                if (isPandigital(result)) {
                    if (atoi(result.c_str()) > highest) {
                        highest = atoi(result.c_str());
                    }
                }
                break;
            }
        }
    }
    return highest;
}