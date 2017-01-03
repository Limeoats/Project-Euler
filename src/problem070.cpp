/*
 * Problem 70: Totient permutation
 * By: Mark Guerra
 * 12/13/2016
*/

#include "main.h"
#include "utils.h"
#include <limits>

/*
 * Create variables [min] and [minN] to keep track of the minimum [n] value and the ratio of [n] / [phi] for that
 * minimum [n]. Immediately generate a list of phi values up to [limit], which is 10000000, using a variation
 * of the Sieve of Eratosthenes. Then, loop in the range [2, 10000000] and check if the value [n] is a permutation
 * of its [phi] value. If it is and it is lower than the [minN] found so far, replace [minN] with that value.
 * Once the loop is finished, [minN] has the answer so return it and print.
*/

std::string Problem070::getAnswer() {
    const long LIMIT = 10000000;
    double min = std::numeric_limits<double>::max(), minN = std::numeric_limits<double>::max();
    std::vector<long> list = utils::generatePhi(LIMIT);
    for (double n = 2.0; n < LIMIT; ++n) {
        long phi = list[n];
        std::string str = std::to_string(phi);
        if (phi <= 0 || n / phi >= min || !std::is_permutation(str.begin(), str.end(), std::to_string(static_cast<long>(n)).begin())) continue;
        minN = n;
        min = n / phi;
    }
    return std::to_string(static_cast<long>(minN));
}