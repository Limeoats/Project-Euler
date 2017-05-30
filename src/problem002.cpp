/*
 * Problem 2: Even Fibonacci numbers
 * By: Mark Guerra
 * 10/19/2015
 */

#include "main.h"

#include <algorithm>
#include <numeric>

bool Problem002::isOdd(int i) {
    return (i & 1) == 1;
}

std::vector<int> Problem002::getFibNumbers(int max) {
    std::vector<int> list = {1, 2};
    int i = 1;

    while (true) {
        int val = list[i] + list[i - 1];
        if (val >= max)
            break;
        list.push_back(val);
        i++;
    }
    return list;
}

std::string Problem002::get_answer() {
    std::vector<int> list = getFibNumbers(4000000);
    //Remove the odds
    list.erase(std::remove_if(list.begin(), list.end(), [](int i) { return (i & 1) == 1; }), list.end());
    return std::to_string(std::accumulate(list.begin(), list.end(), 0));
}