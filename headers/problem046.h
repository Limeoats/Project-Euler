/* Problem 46: Goldbach's other conjecture
 * By: Mark Guerra
 * 12/17/2015
 */

#ifndef PROBLEM_046_H
#define PROBLEM_046_H

/*
 * It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime
 * and twice a square.
 *
 * 9 = 7 + 2×1^2
 * 15 = 7 + 2×2^2
 * 21 = 3 + 2×3^2
 * 25 = 7 + 2×3^2
 * 27 = 19 + 2×2^2
 * 33 = 31 + 2×1^2
 *
 * It turns out that the conjecture was false.
 *
 * What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/

namespace problem046 {
    int getAnswer();
}


#endif