/* Problem 24: Lexicographic permutations
 * By: Mark Guerra
 * 11/23/2015
 */

#ifndef PROBLEM_24_H
#define PROBLEM_24_H

#include <vector>
#include <sstream>

namespace problem24 {
    std::vector<std::string> getPermutations(std::vector<int> numbers, int limit = 0);
    std::string getAnswer();
}

#endif