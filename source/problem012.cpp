/* Problem 12: Highly divisible triangular number
 * By: Mark Guerra
 * 10/20/2015
 */

#include "problem12.h"

#include <cmath>

int problem12::getNumberOfDivisors(int x) {
    int root = sqrt(x);
    int divisors = 0;
    for (int i = 1; i <= root; i++) {
        if (x % i == 0) {
            divisors += 2;
        }
    }
    //If perfect square, we only want one divisor added
    if (pow(root, 2) == x)
        divisors--;

    return divisors;
}


int problem12::getFirstTriangleNumberWithGreaterThanNDivisors(int n) {
    int triangleNumber = 0;
    int counter = 1;
    while (true) {
        triangleNumber += counter;
        if (getNumberOfDivisors(triangleNumber) > n) {
            return triangleNumber;
        }
        counter++;
    }
    return -1;
}

int problem12::getAnswer() {
    return getFirstTriangleNumberWithGreaterThanNDivisors(500);
}