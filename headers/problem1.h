/* Problem 1: Multiples of 3 and 5
 * By: Mark Guerra
 * 10/14/2015
 */

#ifndef PROBLEM_1_H
#define PROBLEM_1_H

#include <vector>

//If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
//The sum of these multiples is 23.
//Find the sum of all the multiples of 3 or 5 below 1000.

namespace problem1 {
    std::vector<int> getMultiplesUnder(int numberUnder);
    int getAnswer();
}

#endif
