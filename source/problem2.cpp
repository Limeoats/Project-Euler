#include "problem2.h"

#include <algorithm>
#include <numeric>

bool problem2::isOdd(int i) {
    return (i & 1) == 1;
}

std::vector<int> problem2::getFibNumbers(int max) {
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

int problem2::getAnswer() {
    std::vector<int> list = getFibNumbers(4000000);
    //Remove the odds
    list.erase(std::remove_if(list.begin(), list.end(), [](int i) { return (i & 1) == 1; }), list.end());
    return std::accumulate(list.begin(), list.end(), 0);
}