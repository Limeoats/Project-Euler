/*
 * Problem 73: Counting fractions in a range
 * By: Mark Guerra
 * 12/15/2016
*/

#include "main.h"
#include "utils.h"

/*
 * Check all fractions [n] / [d] between 1/3 and 1/2
 * where the denominator [d] is less than or equal to [limit].
 * If [n] / [d] is a reduced proper fractions, determined by
 * making sure the GCD of each [n] and [d] both equal 1,
 * increase [count]. When done, return [count] and print.
*/

std::string Problem073::getAnswer() {
    const int LIMIT = 12000;
    int count = 0;
    for (int d = 2; d <= LIMIT; ++d) {
        for (int n = d / 3 + 1; n <= (d - 1) / 2; ++n) {
            if (n < d && !((n % 2 == 0) && (d % 2 == 0)) && utils::gcd(d, n) == 1) ++count;
        }
    }
    return std::to_string(count);
}