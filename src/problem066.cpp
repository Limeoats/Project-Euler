/*
 * Problem 66: Diophantine equation
 * By: Mark Guerra
 * 12/12/2016
*/

#include <cmath>
#include "main.h"

/*
 * The solution to this problem ended up being a combination of the previous two problems.
 * Looking through the Wikipedia page on Diophantine equations led me to Pell's equation,
 * which looks exactly like the equation we're given in this problem (x^2 - ny^2 = +/- 1).
 * A loop is started for the range [2, 1000] to represent D. I then create another loop
 * that goes around until Pell's equation is solved. The solution is found by
 * finding the convergents of the continued fraction for the square root of [i].
 * Once the equation is solved, check if the current value of [x] is greater than the currently
 * greatest value. If so, store it and keep track of D ([i]). Once the outer loop is finished,
 * [xD] has the answer so return it and print.
 */

bool Problem066::pellsEquation(BigNumber x, BigNumber y, int d) {
    return x * x - d * y * y == 1;
}

std::string Problem066::get_answer() {
    BigNumber xD = 0, xX = 0;
    for (int i = 2; i <= 1000; ++i) {
        double t = sqrt(i);
        if (t == (int)t) continue;
        BigNumber a = (int)t, d = 1, m = 0, m1 = 1, n1 = 0, x = a, y = 1;
        while (!this->pellsEquation(x, y, i)) {
            m = d * a - m;
            d = (i - m * m) / d;
            a = ((int)t + m) / d;
            BigNumber m2 = m1;
            m1 = x;
            BigNumber n2 = n1;
            n1 = y;
            x = a * m1 + m2;
            y = a * n1 + n2;
        }
        if (x <= xX) continue;
        xX = x;
        xD = i;
    }
    return xD.getString();
}