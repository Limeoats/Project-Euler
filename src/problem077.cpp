/*
 * Problem 77: Prime summations
 * By: Mark Guerra
 * 12/19/2016
*/

#include "main.h"
#include "utils.h"

/*
 * I took a very similar approach to that of Problem 31 with the coin sums.
 * I first fill up an array [primes] with primes up to 1,000. I then start
 * a loop at 11 since that is the number after the example gave us. I then
 * go through each prime in the list and start a new loop at that prime that goes
 * up to [a]. I then fill up an array [c] with the numbers of combinations of primes
 * that add up to [a]. Once that's done, if that number is greater than the [Limit] of 5000,
 * return it and print it.
*/

std::string Problem077::getAnswer() {
    const int LIMIT = 5000;
    std::vector<long> primes = utils::generatePrimes(1000);
    for (int a = 11;; ++a) {
        std::vector<int> c(a + 1);
        std::fill(c.begin(), c.end(), 0);
        c[0] = 1;
        for (long p : primes) {
            for (long i = p; i <= a; ++i) {
                c[i] += c[i - p];
            }
        }
        if (c[a] > LIMIT)
            return std::to_string(a);
    }
}
