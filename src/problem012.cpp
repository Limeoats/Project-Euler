/*
 * Problem 12: Highly divisible triangular number
 * By: Mark Guerra
 * 10/20/2015
 */

#include "main.h"

#include <cmath>

int Problem012::getNumberOfDivisors(int x) {
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


int Problem012::getFirstTriangleNumberWithGreaterThanNDivisors(int n) {
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

std::string Problem012::getAnswer() {
    return std::to_string(getFirstTriangleNumberWithGreaterThanNDivisors(500));
}