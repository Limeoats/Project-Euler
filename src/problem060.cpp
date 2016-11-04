/*
 * Problem 60: Prime pair sets
 * By: Mark Guerra
 * 11/4/2016
*/

#include "main.h"
#include "utils.h"

/*
 *
 */

std::vector<int> Problem060::getMatchingVals(std::map<int, std::vector<int>> &pairs, std::vector<int> vals) {
    for (int v : vals) {

    }
}

int Problem060::getAnswer() {
    const int LIMIT = 10000;
    const int NUM_PRIMES = 4;
    std::vector<long> primes = utils::generatePrimes(LIMIT);

    std::map<int, std::vector<int>> goodPairs;

    for (int x = 0; x < primes.size(); ++x) {
        std::vector<int> tmp;
        for (int y = x + 1; y < primes.size(); ++y) {
            if (utils::isPrime(utils::concat(primes[x], primes[y])) &&
                    utils::isPrime(utils::concat(primes[y], primes[x]))) {
                tmp.push_back(primes[y]);
            }
        }
        goodPairs.insert(std::pair<int, std::vector<int>>(primes[x], tmp));
    }
    std::vector<int> results;
    for (int p : primes) {
        for (int v : goodPairs[p]) {

        }
    }
    return 0;

}