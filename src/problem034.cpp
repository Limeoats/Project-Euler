/* Problem 34: Digit factorials
 * By: Mark Guerra
 * 12/7/2015
 */

#include "main.h"
#include "utils.h"

#include <vector>
#include <algorithm>
#include <numeric>

/*
 * Loop through every number from 3 to 41000 (upper bound
 * found through guess and check after solving the problem).
 * Add up the sums of the factorials each digit. If that sum
 * equals the original number, add it to a list. Return
 * the sum of each item in the list.
 */

std::string Problem034::getAnswer() {
    std::vector<int> nums;
    int sum = 0;
    for (int i = 3; i < 41000; i++) {
        sum = 0;
        int a = i;
        while (true) {
            sum += utils::factorial(a % 10);
            a /= 10;
            if (a == 0) {
                break;
            }
        }
        if (sum == i) {
            nums.push_back(i);
        }
    }
    return std::to_string(std::accumulate(nums.begin(), nums.end(), 0));
}

