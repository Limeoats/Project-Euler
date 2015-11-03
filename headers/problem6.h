#ifndef PROBLEM_6_H
#define PROBLEM_6_H

#include <cmath>

//The sum of the squares of the first ten natural numbers is,
//1^2 + 2^2 + ... + 10^2 = 385
//The square of the sum of the first ten natural numbers is,
//(1 + 2 + ... + 10)^2 = 55^2 = 3025
//Hence the difference between the sum of the squares of the first ten natural
// numbers and the square of the sum is 3025 ? 385 = 2640.
//Find the difference between the sum of the squares of the first one hundred natural
// numbers and the square of the sum.

namespace problem6 {

    int solveProblem(int numNaturalNumbers) {
        int sumOfSquares = 0;
        int sumOfNumbers = 0;
        for (int i = 1; i <= numNaturalNumbers; i++) {
            sumOfSquares += (int)pow(i, 2);
            sumOfNumbers += i;
        }
        return ((int)pow(sumOfNumbers, 2) - sumOfSquares);
    }

    int getAnswer() {
        return solveProblem(100);
    }

}


#endif
