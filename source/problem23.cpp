/* Problem 23: Non-abundant sums
 * By: Mark Guerra
 * 11/20/2015
 */

#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <utils.h>

#include "problem23.h"

long problem23::sumOfProperDivisors(int n) {
    std::vector<int> pd;
    for (int i = 1; i <= (n / 2); i++) {
        if (n % i == 0) {
            pd.push_back(i);
        }
    }
    return std::accumulate(pd.begin(), pd.end(), 0);
}

bool problem23::isAbundant(long n) {
    return sumOfProperDivisors(n) > n;
}

long long problem23::getAnswer() {
    std::vector<int> abundantNumbers;
    for (int i = 1; i < 28123; i++) {
        if (isAbundant(i)) {
            abundantNumbers.push_back(i);
        }
    }
    bool cb[28124];
    std::fill_n(cb, 28124, false);
    for (int i = 0; i < abundantNumbers.size(); i++) {
        for (int j = i; j < abundantNumbers.size(); j++) {
            int t = abundantNumbers[i] + abundantNumbers[j];
            if (t > 28123) break;
            cb[t] = true;
        }
    }
    long total = 0;
    for (int i = 1; i <= 28123; i++) {
        if (!cb[i]) {
            total += i;
        }
    }
    return total;
}