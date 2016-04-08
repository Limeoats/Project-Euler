/* Problem 4: Largest palindrome product
 * By: Mark Guerra
 * 10/19/2015
 */

#include "problem004.h"

#include <sstream>
#include <algorithm>
#include <vector>
#include <iostream>

bool problem004::isPalindrome(int num) {
    int tmp = num;
    int sum = 0;
    int r;
    while (tmp) {
        r = tmp % 10;
        tmp = tmp / 10;
        sum = sum * 10 + r;
    }
    return num == sum;
}

int problem004::getLargestPalindrome() {

    std::vector<int> list;
    const int x1 = 999;
    const int x2 = 999;
    for (int i = x1; i > 99; i--) {
        for (int j = x2; j > 99; j--) {
            if (isPalindrome(i * j)) {
                list.push_back(i * j);
            }
        }
    }

    return list[std::distance(list.begin(), max_element(std::begin(list), std::end(list)))];
}

int problem004::getAnswer() {
    return getLargestPalindrome();
}