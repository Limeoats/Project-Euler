/* Problem 6: Sum square difference
 * By: Mark Guerra
 * 10/19/2015
 */

#include "problem6.h"

#include <cmath>

int problem6::solveProblem(int numNaturalNumbers) {
    int sumOfSquares = 0;
    int sumOfNumbers = 0;
    for (int i = 1; i <= numNaturalNumbers; i++) {
        sumOfSquares += (int)pow(i, 2);
        sumOfNumbers += i;
    }
    return ((int)pow(sumOfNumbers, 2) - sumOfSquares);
}

int problem6::getAnswer() {
    return solveProblem(100);
}