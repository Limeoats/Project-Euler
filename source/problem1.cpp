/* Problem 1: Multiples of 3 and 5
 * By: Mark Guerra
 * 10/19/2015
 */

#include "problem1.h"
#include "utils.h"

#include <numeric>

std::vector<int> problem1::getMultiplesUnder(int numberUnder, std::vector<int> multiplesOf) {
    std::vector<int> multiples;
    for (int aMultiplesOf : multiplesOf) {
        for (int i = aMultiplesOf; i < numberUnder; i++) {
            if (i % aMultiplesOf == 0) {
                if (!utils::contains(multiples, i)) {
                    multiples.push_back(i);
                }
            }
        }
    }
    return multiples;
}

int problem1::getAnswer() {
    std::vector<int> multiples = getMultiplesUnder(1000, {3, 5});
    return std::accumulate(multiples.begin(), multiples.end(), 0);
}