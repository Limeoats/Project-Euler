/*
 * Problem 62: Cubic permutations
 * By: Mark Guerra
 * 12/5/2016
*/

#include <cmath>
#include <algorithm>
#include "main.h"

/*
 * Start looping with [n] at 345 since that was given to be the number for 3
 * permutations, so it can't possibly be lower than that. Each time around
 * the loop, cube the value of [n] and store the result in [c] (and then increment [n]
 * as well for next time). Sort the digits of [c] in ascending order. If the
 * dictionary [cubes] doesn't have that sorted number as a key already, add it and
 * make the first entry the unsorted number [c]. If it does exist, however, then that means
 * that at least one permutation for this cube has already been found, so add the new
 * value of [c] to the Dictionary entry for [sorted]. If the number of entries for that
 * sorted key is equal to 5, then the answer to the problem is the first entry under that
 * sorted key. Return and print it.
*/

std::string Problem062::get_answer() {
    const int NUM_PERMUTATIONS = 5;
    int n = 345;
    std::map<std::string, std::vector<unsigned long>> cubes;
    while (true) {
        unsigned long c = static_cast<unsigned long>(pow(n++, 3));
        std::string str = std::to_string(c);
        std::sort(str.begin(), str.end());
        cubes[str].push_back(c);
        if (cubes[str].size() == NUM_PERMUTATIONS) {
            return std::to_string(cubes[str].front());
        }
    }
}