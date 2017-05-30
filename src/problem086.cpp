/*
 * Problem 86: Cuboid route
 * By: Mark Guerra
 * 5/26/2017
*/

#include <cmath>
#include <algorithm>
#include "main.h"
#include "utils.h"

/*
 * The shortest path can be calculated by sqrt(length^2 + (width + height)^2). This is
 * clear if the cuboid is unfolded and laid flat. To solve the problem, I loop through
 * different lengths, widths, and heights of the cuboid and find the shortest path [s].
 * If [s] is an integer, I increase a counter [c]. When [c] is greater than 1,000,000
 * the current value of [l] is returned and printed since [l] is always the greatest.
 */

std::string Problem086::get_answer() {
    int c = 0;
    for (int l = 1;; ++l) {
        for (int w = 1; w <= l; ++w) {
            for (int h = 1; h <= w; ++h) {
                double s = sqrt((l * l) + ((w + h) * (w + h)));
                c += s == (int)s;
                if (c > 1000000) {
                    return std::to_string(l);
                }
            }
        }
    }
}
