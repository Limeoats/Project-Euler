/*
 * Problem 28: Number spiral diagonals
 * By: Mark Guerra
 * 11/23/2015
 */

#include "main.h"

#include <cmath>

/*
 * Start [total] at 1.
 * There are four separate patterns for the diagonals:
 * Down left: n^2 + 1
 * Down right: n^2 - (n-1)
 * Up left: n^2 + (n+1)
 * Up right: odd n^2
 * I combined each of the first 3 polynomials into:
 * 3n^2 + 1, or 3(n^2 + 1)
 * I then loop through each number from 2 to 1001.
 * If it's an odd number, use formula n^2
 * If it's an even number, use the combined formula 3(n^2 + 1)
 * Add each result to [total] and return it;
 */

std::string Problem028::getAnswer() {
    return std::to_string(([](unsigned int total)->unsigned int {
        for (int i = 2; i < 1002; ++i)
            total += (i & 1 == 1) ? pow(i, 2) : 3 * (pow(i, 2) + 1);
        return total;
    }(1)));
}