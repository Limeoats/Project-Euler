/* Problem 31: Coin sums
 * By: Mark Guerra
 * 12/3/2015
 */

#ifndef PROBLEM_31_H
#define PROBLEM_31_H

#include <vector>

/*
 * In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
 *
 * 1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
 * It is possible to make £2 in the following way:
 *
 * 1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
 * How many different ways can £2 be made using any number of coins?
 */

namespace problem31 {
    unsigned int denomFunc(int n, std::vector<int> &denoms);
    unsigned int getAnswer();
}


#endif