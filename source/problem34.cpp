/* Problem 34: Digit factorials
 * By: Mark Guerra
 * 12/7/2015
 */

#include "problem34.h"

#include <vector>
#include <algorithm>

/*
 * Loop through every number from 3 to 41000 (upper bound
 * found through guess and check after solving the problem).
 * Add up the sums of the factorials each digit. If that sum
 * equals the original number, add it to a list. Return
 * the sum of each item in the list.
 */

int problem34::factorial(int n) {
    int x = 1;
    for (int i = 1; i <= n; ++i) {
        x *= i;
    }
    return x;
}

int problem34::getAnswer() {
    std::vector<int> nums;
    int sum = 0;
    for (int i = 3; i < 41000; i++) {
        sum = 0;
        int a = i;
        while (true) {
            sum += factorial(a % 10);
            a /= 10;
            if (a == 0) {
                break;
            }
        }
        if (sum == i) {
            nums.push_back(i);
        }
    }
    return std::accumulate(nums.begin(), nums.end(), 0);
}

