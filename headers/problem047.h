/* Problem 47: Distinct primes factors
 * By: Mark Guerra
 * 12/17/2015
 */

#ifndef PROBLEM_47_H
#define PROBLEM_47_H

/*
 * The first two consecutive numbers to have two distinct prime factors are:
 *
 * 14 = 2 × 7
 * 15 = 3 × 5
 *
 * The first three consecutive numbers to have three distinct prime factors are:
 *
 * 644 = 2^2 × 7 × 23
 * 645 = 3 × 5 × 43
 * 646 = 2 × 17 × 19.
 *
 * Find the first four consecutive integers to have four distinct prime factors. What is the first of these numbers?
 */

namespace problem47 {
    int getDistinctPrimeFactors(int n);
    int getAnswer();
}


#endif