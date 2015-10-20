#ifndef PROBLEM_1_H
#define PROBLEM_1_H

#include <vector>
#include <numeric>

#include "utils.h"

//If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
//The sum of these multiples is 23.
//Find the sum of all the multiples of 3 or 5 below 1000.

namespace problem1 {

    std::vector<int> getMultiplesUnder(int numberUnder, std::vector<int> multiplesOf) {
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

    int getAnswer() {
        std::vector<int> multiples = getMultiplesUnder(1000, {3, 5});
        return std::accumulate(multiples.begin(), multiples.end(), 0);
    }

}

#endif
