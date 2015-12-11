/* Problem 41: Pandigital prime
 * By: Mark Guerra
 * 12/11/2015
 */

#ifndef PROBLEM_41_H
#define PROBLEM_41_H

/*
 * We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once.
 * For example, 2143 is a 4-digit pandigital and is also prime.
 *
 * What is the largest n-digit pandigital prime that exists?
 */

namespace problem41 {
    bool isPandigital(long n);
    long getAnswer();
}


#endif