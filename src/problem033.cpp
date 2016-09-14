/* Problem 33: Digit cancelling fractions
 * By: Mark Guerra
 * 12/4/2015
 */

#include "main.h"

#include <vector>
#include <utility>
#include <functional>
#include <iomanip>
#include <cmath>


/*
 * First, try every combination of two-digit numbers for the numerator
 * and the denominator of the fraction. Exclude certain combinations
 * depending on some of the rules given in the problem. Figure out the
 * quotient of [i] divided by [j]. Then figure out if the numerator
 * and the denominator share any common numbers. If so, cancel them out
 * and divide the other number in the numerator by the other number in the
 * denominator. If that quotient is equal to the original quotient, add the
 * fraction to [fractions]. Finally, multiply all of the fractions we found
 * together and simplify it. Return the simplified denominator.
 */

int Problem033::getAnswer() {
    auto firstDigit = [](int n)->int{n /= 10; return n;};
    auto secondDigit = [](int n)->int{return n%10;};
    std::function<int (int,int)> gcd = [&gcd](int a, int b)->int{return b == 0 ? a : gcd(b, a%b);};
    auto compareDoubles = [](double v1, double v2) { return std::fabs(v1 - v2) < 1E-3; };

    std::vector<std::pair<int,int>> fractions;
    for (int i = 10; i <= 99; ++i) {
        for (int j = 10; j <= 99; ++j) {
            if (i >= j) {
                continue;
            }
            if (secondDigit(i) == 0 && secondDigit(j) == 0) {
                continue;
            }
            double quotient = double(i) / double(j);
            if (firstDigit(i) == secondDigit(j) && firstDigit(j) != 0) {
                if (compareDoubles(double(secondDigit(i)) / double(firstDigit(j)), quotient)) {
                    fractions.push_back(std::make_pair(i, j));
                }
            }
            else if (secondDigit(i) == firstDigit(j) && secondDigit(j) != 0) {
                if (compareDoubles(double(firstDigit(i)) / double(secondDigit(j)), quotient)) {
                    fractions.push_back(std::make_pair(i, j));
                }
            }
        }
    }
    int num = 1, den = 1;
    for (auto f : fractions) {
        num *= std::get<0>(f);
        den *= std::get<1>(f);
    }
    return den / gcd(num, den);
}