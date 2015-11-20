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

bool problem23::isPerfectNumber(long n) {
    return sumOfProperDivisors(n) == n;
}

bool problem23::isDeficient(long n) {
    return sumOfProperDivisors(n) < n;
}

bool problem23::isAbundant(long n) {
    return sumOfProperDivisors(n) > n;
}

long long problem23::getAnswer() {
    std::vector<int> abundantNumbers;
    for (int i = 1; i < 28123; i++) {
        if ((i & 1) == 1) continue;
        if (isAbundant(i)) {
            abundantNumbers.push_back(i);
        }
    }
    //std::sort(abundantNumbers.begin(), abundantNumbers.end(), [](int a, int b) {return a < b;});
    std::vector<int> sums;
    for (int c : abundantNumbers) {
        for (int d : abundantNumbers) {
            sums.push_back(c + d);
        }
    }
    long long total = 0;
    for (int i = 1; i < 28123; i++) {
        if ((i & 1) == 1) {
            total += i;
            continue;
        }
        if (!utils::contains(sums, i)) {
            total += i;
        }
    }
    return total;

}