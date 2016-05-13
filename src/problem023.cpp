/* Problem 23: Non-abundant sums
 * By: Mark Guerra
 * 11/20/2015
 */

#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

#include "utils.h"
#include "problem023.h"

long problem023::sumOfProperDivisors(int n) {
    int sum = 0;
    for (int i = 1; i <= (n / 2); i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

bool problem023::isAbundant(long n) {
    return sumOfProperDivisors(n) > n;
}

long long problem023::getAnswer() {
    std::vector<int> abundantNumbers;
    for (int i = 1; i < 20161; i++) {
        if (isAbundant(i)) {
            abundantNumbers.push_back(i);
        }
    }
    bool cb[20162];
    std::fill_n(cb, 20162, false);
    for (int i = 0; i < abundantNumbers.size(); i++) {
        for (int j = i; j < abundantNumbers.size(); j++) {
            int t = abundantNumbers[i] + abundantNumbers[j];
            if (t > 20161) break;
            cb[t] = true;
        }
    }
    long total = 0;
    for (int i = 1; i <= 20161; i++) {
        if (!cb[i]) {
            total += i;
        }
    }
    return total;
}
