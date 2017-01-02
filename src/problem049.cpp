/* Problem 49: Prime permutations
 * By: Mark Guerra
 * 12/21/2015
 */

#include "main.h"
#include "utils.h"

#include <vector>
#include <algorithm>

/*
 * Start out by generating all prime numbers up to 9999
 * since we only want four digit numbers.
 * Then start a loop through each of the prime numbers.
 * We only care about those greater than 1000, so check to make
 * sure the number in the loop > 1000. Figure out all permutations
 * of that number and store it in [perms]. Sort [perms].
 * Loop through perms 3 times, each time checking if a later number
 * is prime. If 3 are found and they all have the same distance
 * apart, and it is not the one from the example problem, join them
 * all together, convert them to a string, and return.
 */

std::string Problem049::getAnswer() {
    std::vector<long> allPrimes = utils::generatePrimes(9999);
    bool exampleFound = false;
    for (long p : allPrimes) {
        if (p >= 1000) {
            std::vector<int> perms;
            std::string str = std::to_string(p);
            do {
                perms.push_back(atol(str.c_str()));
            } while (std::next_permutation(str.begin(), str.end()));
            std::sort(perms.begin(), perms.end());
            int count = 0;
            if (perms.size() < 3) continue;
            for (int i = 0; i < perms.size() - 2; ++i) {
                for (int j = 1; j < perms.size() - 1; ++j) {
                    for (int k = 2; k < perms.size(); ++k) {
                        if (perms[i] != perms[k] && perms[i] != perms[j] && perms[j] != perms[k]) {
                            if (utils::isPrime(perms[i]) && utils::isPrime(perms[j]) && utils::isPrime(perms[k])) {
                                int distance = perms[k] - perms[j];
                                if (distance == perms[j] - perms[i]) {
                                    if (!exampleFound) {
                                        exampleFound = true;
                                        continue;
                                    }
                                    std::stringstream ss;
                                    ss << perms[i] << perms[j] << perms[k];
                                    return ss.str();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}