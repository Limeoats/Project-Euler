#ifndef PROBLEM_9_H
#define PROBLEM_9_H

#include <cmath>

//A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
//a2 + b2 = c2
//	For example, 32 + 42 = 9 + 16 = 25 = 52.
//	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
//		Find the product abc.


namespace problem9 {

    double getProductOfPythagoreanTriplet(int sumOfABC) {
        for (int a = 1; a < 499; a++) {
            for (int b = 1; b < 499; b++) {
                double c = sqrt(pow(a, 2) + pow(b, 2));
                if (a + b + c == 1000 && (a < b) && (b < c)) {
                    return a * b * c;
                }
            }
        }
        return -1;
    }

    int getAnswer() {
        return getProductOfPythagoreanTriplet(1000);
    }
}


#endif
