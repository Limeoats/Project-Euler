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
    std::vector<int> nums;
    int pCount = 0;
    int Z = primes[pCount], X;
    int M = NUM_PRIMES;
    while (true) {
        X = Z;
        nums.push_back(X);
        std::vector<int> L = goodPairs[X];
        for (int it : L) {
            if (goodPairs[it].size() >= M - 1) { //MIGHT HAVE TO FIX THIS AND COMPARE THESE M - 1 NUMBERS TO L'S
                int Y = it;
                if (M - 1 == 1) {
                    int sum = 0;
                    for (int i = 0; i < nums.size(); ++i) {
                        sum += nums[i];
                    }
                    return sum;
                }
                else {
                    X = Y;
                    M = M - 1;
                    break;
                }
            }
        }
        Z  = primes[++pCount];
        nums.clear();
        continue;
    }
}