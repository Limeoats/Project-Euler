/* Problem 30: Digit fifth powers
 * By: Mark Guerra
 * 12/3/2015
 */

#include "main.h"

#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

/*
 * Create a list to hold the numbers that satisfy the requirement, [nums].
 * Loop through every number from 2 to (9^5) * 5, which is the highest
 * possible number that can satisfy the requirement.
 * Loop through each digit of the number and add it to a list. Add each of those
 * numbers together and compare that sum to [i]. If they're equal, at it to [nums].
 * Finally, return the sum of everything in [nums] and print it to the screen.
 */

std::string Problem030::getAnswer() {
    std::vector<int> nums;
    for (int i = 2; i < (pow(9, 5) * 5); i++) {
        if ([](int x)->int {
            std::vector<int> digits;
            while (true) {
                digits.push_back(pow(x % 10, 5));
                x /= 10;
                if (x == 0) {
                    return std::accumulate(digits.begin(), digits.end(), 0);
                }
            }
        }(i) == i) {
            nums.push_back(i);
        }
    }
    return std::to_string(std::accumulate(nums.begin(), nums.end(), 0));
}