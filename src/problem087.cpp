/*
 * Problem 87: Prime power triples
 * By: Mark Guerra
 * 5/30/2017
*/

#include <set>
#include <unordered_set>
#include "main.h"
#include "utils.h"

/*
 * I begin the problem by generating the prime numbers up to the square root of [LIMIT].
 * There are then three for-loops that go through the primes and create every
 * combination. I then do the 2nd power, 3rd power, and 4th power of each combination.
 * If the [sum] is less than [LIMIT], add it to an unordered set (to prevent duplicates).
 * Finally, return the size of the set [sums] and print it.
 */

#define ROOT(n, r) std::pow(n, 1.0 / r)

std::string Problem087::get_answer() {
    const double LIMIT = 50000000;
    std::unordered_set<double> sums;
    auto t = utils::generatePrimes((long)ROOT(LIMIT, 2));
    for (int i = 0; i < t.size(); ++i) {
        for (int j = 0; j < t.size(); ++j) {
            for (int k = 0; k < t.size(); ++k) {
                double sum = std::pow(t[i], 2) + std::pow(t[j], 3) + std::pow(t[k], 4);
                if (sum >= LIMIT) break;
                sums.insert(sum);
                
            }
        }
    }
    return std::to_string(sums.size());
}