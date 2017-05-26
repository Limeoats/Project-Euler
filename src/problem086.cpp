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
 * clear if the cuboid is unfolded and laid flat.
 */

double Problem086::shortest_path(int l, int w, int h) {
    return sqrt((l * l) + ((w + h) * (w + h)));
}

std::string Problem086::getAnswer() {
    int count = 0;
    for (int l = 1; l < 100; ++l) {
        for (int w = 1; w < 100; ++w) {
            for (int h = 1; h < 100; ++h) {
                double i;
                double s = shortest_path(l, w, h);
                if (std::modf(s, &i) == 0.0) {
                    ++count;
                }
            }
        }
    }
    return std::to_string(count);
}
