/*
 * Problem 85: Counting rectangles
 * By: Mark Guerra
 * 5/26/2017
*/

#include <limits>
#include <cstdlib>
#include "main.h"

/*
 * The solution to this problem involves a formula I found for calculating the number of rectanges
 * in a rectangular grid based on the width and height. Once that number was calculated,
 * I checked to see if it was closer to the [TARGET], 2000000, than any other solution found so far.
 * If it is, I keep track of it in [closest_area]. Once done searching through all combinations up to
 * 100x100, which is an upper bound that I chose, I return and print the [closest_area].
 */

std::string Problem085::getAnswer() {
    const int TARGET = 2000000;
    int closest_distance = TARGET;
    int closest_area = 0;
    for (int a = 3; a < 100; ++a) {
        for (int b = a; b < 100; ++b) {
            int rectangles = a * (a + 1) * b * (b + 1) / 4;
            int distance = abs(rectangles - TARGET);
            if (distance < closest_distance) {
                closest_area = a * b;
                closest_distance = distance;
            }
        }
    }
    return std::to_string(closest_area);
}