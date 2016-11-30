/* Problem 45: Triangular, pentagonal, and hexagonal
 * By: Mark Guerra
 * 12/17/2015
 */

#include "main.h"

#include <cmath>

/*
 * Start [n] at 286, which is the index after the previous
 * triangle number given in the problem. Loop around, incrementing
 * [n] by 1 each time. Calculate the hexagonal number at that
 * index. Check if that hexagonal number is also pentagonal and
 * a triangle number. If both are true, return it and print it.
 */

bool Problem045::isPentagonal(int x) {
    double t = (sqrt(1.0 + 24.0 * x) + 1.0) / 6.0;
    return  t == int(t);
}

bool Problem045::isTriangle(int x) {
    double t = (sqrt(1.0 + 8.0 * x) - 1.0) / 2.0;
    return t == int(t);
}

std::string Problem045::getAnswer() {
    int n = 286;
    while (true) {
        int hex = (2 * n - 1) * n;
        if (isPentagonal(hex) && isTriangle(hex)) {
            return std::to_string(hex);
        }
        ++n;
    }
}
