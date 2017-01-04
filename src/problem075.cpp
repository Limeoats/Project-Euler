/*
 * Problem 75: Singular integer right triangles
 * By: Mark Guerra
 * 12/15/2016
*/

#include <cmath>
#include "main.h"
#include "utils.h"

/*
 * I used Euclid's formula to solve this problem. The formula states that
 *    a = k * (m^2 - n^2), b = k * (2mn), c = k * (m^2 + n^2)
 * where m, n, and k are positive integers, m > n, m and n are coprime, and m and n are not both odd.
 * I start the problem with a loop where [m] goes from [2 - sqrt(1500000 / 2)]. I then start another loop
 * where [n] goes from 1 to [m]. I then check to make sure [m] and [n] satisfy all of the conditions above.
 * If they do, I calculate [a], [b], and [c] using the formulas above. I then get the sum [t]. Then,
 * I need to apply the [k] multiplication to the sum to make sure all of the triplets are covered. If
 * the the same [t] value is ever found twice (or more), then that [t] value is not good. Therefore,
 * the second time it is found, decrement [result]. If it's found even more times than 2, nothing happens.
 * At the end, [result] has the answer so return it and print.
*/

std::string Problem075::getAnswer() {
    const int LIMIT = 1500000;
    int result = 0;
    std::map<long, long> items;
    for (int m = 2; m < sqrt(LIMIT / 2); ++m) {
        for (int n = 1; n < m; ++n) {
            if ((m % 2 == 1 && n % 2 == 1) || utils::gcd(m, n) != 1) continue;
            long a = m * m - n * n;
            long b = 2 * m * n;
            long c = m * m + n * n;
            long t = a + b + c;
            while (t <= LIMIT) {
                if (items.find(t) == items.end()) {
                    items[t] = 1;
                    ++result;
                }
                else {
                    ++items[t];
                    if (items[t] == 2) --result;
                }
                t += a + b + c;
            }
        }
    }
    return std::to_string(result);
}