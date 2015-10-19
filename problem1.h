#ifndef PROBLEM_1_H
#define PROBLEM_1_H

#include <vector>

#include "utils.h"

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

#endif
