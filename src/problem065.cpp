/*
 * Problem 65: Convergents of e
 * By: Mark Guerra
 * 12/9/2016
*/

#include <numeric>
#include "main.h"
#include "utils.h"

/*
 * Start out by generating a list of all approximations for e. I noticed a pattern
 * where all of the approximations are 1 except for every third, which is 2 more than
 * the previous third. Therefore, I simply created a list [c] with these values. Then,
 * I looked for a pattern in the numerators (since that is all we care about in this problem)
 * to see if I could find an easy way to generate them. It turns out that there is a pattern:
 *    n = (n-1 * c[i]) + n-2
 * where n-1 is the previous numerator, n-2 is two numerators back, and c[i] is the approximation
 * associated with the current numerator we are looking for. With this formula, I was able to generate
 * the 100'th numerator, get the sum of its digits, and then return and print it.
*/

std::string Problem065::getAnswer() {
    std::vector<int> c { 2, 1 };
    int t = 2;
    for (int i = 0; i <= 100; ++i) {
        if (i % 3 == 0) {
            c.push_back(t);
            t += 2;
        }
        else
            c.push_back(1);
    }
    BigNumber n = 8, n1 = 3;
    for (int i = 3; i < 100; ++i) {
        BigNumber n2 = n1;
        n1 = n;
        n = (n1 * c[i]) + n2;
    }
    return std::to_string(utils::digitSum(n.getString()));
}