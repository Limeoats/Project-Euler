/*
 * Problem 60: Prime pair sets
 * By: Mark Guerra
 * 11/4/2016
*/

#include "main.h"
#include "utils.h"

/*
 * Start by generating all primes up to 10000. With a nested loop, go through each combination
 * of primes in that list and concatenate them. If the result is prime going both ways, add it to a new list
 * [goodPairs]. This creates a list of all pairs of prime concatenations for any given prime under 10000.
 * Next, start looping through [primes] again. If a list [nums] doesn't contain the prime, add it. Create
 * another list [cPairs] that contains all of the pairs for [curr]. Now loop through [other] half of the pair
 * in [cPairs]. If [other] isn't the other half of a pair of each existing number in [nums], it is not
 * part of the answer so move on to the next [other]. Create a new list [matchList] and initialize it with
 * [other] since it could be part of the answer. Loop through all of the other halves of the pairs for [other]. If
 * it is a pair of each number in [nums], then it might be part of the answer so add it to [matchList].
 * Once matchList is filled up, check to see if its size is [need] - 1. If it is, add [other] to [nums] and make
 * sure [nums] is the same size as [NUM_PRIMES]. If it is, get the sum of the numbers in [nums] and return it.
 * If [need] - 1 is not 1, then we are one number closer to the answer but we have to keep going. Subtract 1 from
 * [need], set [curr] to [other], and continue. However, if [matchList]'s size was not at leaset [need] - 1, then
 * [other] is not part of our answer. If there is more than 1 number in [nums], we have to remove the last one
 * and try again from that spot so that all numbers are checked. If there are 0 or 1, however, just clear the list,
 * set [curr] to the next prime, and start the entire process over.
 */

std::string Problem060::getAnswer() {
    const int LIMIT = 10000;
    const int NUM_PRIMES = 5;
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
    int prime = primes[pCount], curr = prime;
    int need = NUM_PRIMES;
    int prev = -1;
    auto pairWithAllInNums = [&](int other) {
        bool yes = true;
        for (int i = 0; i < nums.size(); ++i) {
            if (!utils::contains(goodPairs[nums[i]], other)) {
                yes = false;
                break;
            }
        }
        return yes;
    };
    while (pCount < primes.size()) {
        bool clear = true;
        if (!utils::contains(nums, curr) && prev == -1) {
            nums.push_back(curr);
        }
        std::vector<int> cPairs = goodPairs[curr];
        if (prev > -1) {
            auto x = std::remove_if(cPairs.begin(), cPairs.end(), [&prev](int t) {
               return t <= prev;
            });
            cPairs.erase(x, cPairs.end());
            prev = -1;
        }
        for (int other : cPairs) {
            if (!pairWithAllInNums(other)) {
                continue;
            }
            std::vector<int> matchList {other};
            for (int v : goodPairs[other]) {
                bool add = true;
                for (int i = 0; i < nums.size(); ++i) {
                    if (!utils::contains(goodPairs[nums[i]], v)) {
                        add = false;
                        break;
                    }
                }
                if (add) {
                    matchList.push_back(v);
                }
            }
            if (matchList.size() >= need - 1) {
                if (need - 1 == 1) {
                    nums.push_back(other);
                    if (nums.size() == NUM_PRIMES) {
                        int sum = 0;
                        for (int i = 0; i < nums.size(); ++i) {
                            sum += nums[i];
                        }
                        return std::to_string(sum);
                    }
                }
                else {
                    curr = other;
                    need -= 1;
                    clear = false;
                    break;
                }
            }
            else {
                if (nums.size() > 1) {
                    prev = nums.back();
                    nums.pop_back();
                    ++need;
                    curr = nums.back();
                    clear = false;
                    break;
                }
                else {
                    clear = true;
                }
            }
        }
        if (clear) {
            prime = primes[++pCount];
            curr = prime;
            need = NUM_PRIMES;
            nums.clear();
        }
    }
    return "";
}