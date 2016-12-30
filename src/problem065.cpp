/*
 * Problem 65: Convergents of e
 * By: Mark Guerra
 * 12/9/2016
*/

#include <numeric>
#include "main.h"
#include "utils.h"

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