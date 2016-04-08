/* Problem 24: Lexicographic permutations
 * By: Mark Guerra
 * 11/23/2015
 */

#ifndef PROBLEM_24_H
#define PROBLEM_24_H

#include <vector>
#include <sstream>


/*
 * A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation
 * of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically,
 * we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 * 012   021   102   120   201   210
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */


namespace problem24 {
    std::vector<std::string> getPermutations(std::vector<int> numbers, int limit = 0);
    std::string getAnswer();
}

#endif