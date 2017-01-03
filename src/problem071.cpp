/*
 * Problem 71: Ordered fractions
 * By: Mark Guerra
 * 12/13/2016
*/

#include "main.h"

/*
 * For this problem, I used the idea of a Farey Sequence to find the numerator.
 * Let a/b = 3/7, the number we are given. If a/b and c/d are neighbors,
 * c/d - a/b = (bc - ad) / bd, which can be simplified to bc - ad = 1.
 * Substituting in our values gets us 7c - 3d = 1, which can be re-arranged
 * to get c = (3d + 1) / 7. This is the formula we use to get the value.
 * Loop through all denominators in range [2, 1000000]. Plug the value of
 * [d] into the formula to get a numerator. Check if 3 * [c] + 1
 * divides evenly by 7, our given denominator. If it does, add [c] to a list.
 * Once we've gone through all of the denominators in the range, get the maximum
 * numerator we found from [list], return, and print it.
*/

std::string Problem071::getAnswer() {
    std::vector<int> list;
    for (int d = 2; d <= 1000000; ++d) {
        int c = (3 * d + 1) / 7;
        if ((3 * c + 1) % 7 == 0)
            list.push_back(c);
    }
    return std::to_string(*std::max_element(list.begin(), list.end()));
}