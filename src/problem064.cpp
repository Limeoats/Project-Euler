/*
 * Problem 64: Odd period square roots
 * By: Mark Guerra
 * 12/8/2016
*/

#include <cmath>
#include "main.h"

/*
 * Start by creating a total [counter] and initializing it to 0. Loop through the numbers
 * in the range [2, 10000]. I then simply follow the iterative algorithm found on
 * Wikipedia for getting the continued fraction expansion. The algorithm is finished when
 * [a0]*2 is equal to [a]. I then check the number of elements in [list] to see if the number
 * is odd. If it is, increment total. At the end, return the total and print it.
*/


std::string Problem064::getAnswer() {
    int total = 0;
    for (int i = 2; i <= 10000; ++i) {
        int x = static_cast<int>(sqrt(i));
        if (x * x == i) continue;
        std::vector<int> list;
        int m = 0, d = 1, a0 = x, a = a0;
        while (true) {
            m = (d * a) - m;
            d = (i - (m * m)) / d;
            a = (x + m) / d;
            list.push_back(a);
            if (a == 2 * a0) break;
        }
        if (list.size() % 2 != 0) ++total;
    }
    return std::to_string(total);
}