/* Problem 24: Lexicographic permutations
 * By: Mark Guerra
 * 11/23/2015
 */

#include "main.h"

#include <iostream>
#include <algorithm>
#include <sstream>

std::vector<std::string> Problem024::getPermutations(std::vector<int> numbers, int limit) {
    int count = 0;
    std::vector<std::string> p;
    std::stringstream ss;
    for (int i : numbers) {
        ss << i;
    }
    std::string str = ss.str();
    std::sort(str.begin(), str.end());
    do {
        if (limit > 0 && count > limit)
            break;
        p.push_back(str);
        count++;
    } while (std::next_permutation(str.begin(), str.end()));
    return p;
}

std::string Problem024::getAnswer() {
    std::vector<std::string> x = getPermutations({0,1,2,3,4,5,6,7,8,9}, 1000000);
    return x[999999];
}