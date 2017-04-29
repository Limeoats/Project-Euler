/*
 * Problem 80: Square root digital expansion
 * By: Mark Guerra
 * 3/30/2017
*/

#include "main.h"
#include "utils.h"

/*
 * To solve this problem, I used an algorithm called "Square roots by subtraction",
 * documented in this paper: http://www.afjarvis.staff.shef.ac.uk/maths/jarvisspec02.pdf
 * Basically, it is possible to store the decimal numbers in a BigNumber and calculate
 * the square root without any floating point numbers at all (or even storing the decimal point).
 * Once I get the digits, I add them to the total sum. Finally, I return the sum and print it.
 */

BigNumber Problem080::sqrtDigits(int n, int precision) {
    BigNumber a = 5 * n;
    BigNumber b = 5;
    BigNumber digits = BigNumber(10).pow(precision);
    while (b < digits) {
        if (a >= b) {
            a -= b;
            b += 10;
        }
        else {
            a *= 100;
            b.setString(b.getString().insert(b.getString().size() - 1, "0"));
        }
    }
    return BigNumber(b.getString().substr(0, b.getString().size() - 3));
}

std::string Problem080::getAnswer() {
    int sum = 0;
    for (int n = 1; n <= 100; ++n) {
        if (utils::isPerfectSquare(n)) continue;
        auto x = this->sqrtDigits(n, 102);
        sum += utils::digitSum(x.getString());
    }
    return std::to_string(sum);
}
