/* Problem 39: Integer right triangles
 * By: Mark Guerra
 * 12/8/2015
 */

#include "main.h"

#include <cmath>
#include <iostream>

/*
 * We must loop through every perimeter from [2] to [1000].
 * Only the even perimeters need to be checked since any
 * combination of positive/negative a's and b's will result in
 * a positive perimeter.
 * We know that a < c and b < c. Therefore, for each of those perimeters,
 * we need to try all values of [a] up to perimeter / 3.
 *
 * We know:   a^2 + b^2 = c^2
 * Therefore: a + b + c = perimeter
 *                or
 *            c = perimeter - a - b
 * Replacing the c in the first equation with the equation right above, we get:
 *            a^2 + b^2 = (perimeter - a - b)^2
 *                or
 *            a^2 + b^2 = perimeter^2 + a^2 + b^2 - 2*perimeter*a - 2*perimeter*b + 2ab
 *                or
 *            b = (perimeter^2 - 2*perimeter*a) / (2*perimeter - 2a)
 *
 * We then use the derived equation from above to figure out if these values of a, b, and c
 * are a solution. If so, increase [x]. If [x] ends up being higher than any previous set of numbers,
 * replace [highest] with the new highest perimeter and [hns] with the new highest number of solutions.
 * Finally, return [highest] and print it.
 */

std::string Problem039::getAnswer() {
    int hns = 0;
    int highest = 0;
    for (int i = 2; i <= 1000; i += 2) {
        int x = 0;
        for (int a = 2; a < i/3; a++) {
            if (i * (i - (2 * a)) % (2 * (i - a)) == 0) {
                x++;
            }
        }
        if (x > hns) {
            hns = x;
            highest = i;
        }
    }
    return std::to_string(highest);
}