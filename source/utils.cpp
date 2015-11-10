#include <algorithm>
#include <cmath>

#include "utils.h"


template <class C, class T>
bool utils::contains(const C &v, const T &x) {
    return std::end(v) != std::find(std::begin(v), std::end(v), x);
}

bool utils::isPrime(int num) {
    if ((num & 1) == 0)
        return num == 2;
    int root = sqrt(num);
    for (int i = 3; i <= root; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

std::vector<std::string> utils::split(std::string str, char c) {
    std::vector<std::string> list;
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, c)) {
        list.push_back(item);
    }
    return list;
}

std::string utils::ltrim(std::string str, char c) {
    while (str[0] == c) {
        str.erase(std::remove(str.begin(), str.begin(), c));
    }
    return str;
}

int utils::numDigits(int num) {
    return num > 0 ? (int)log10 ((double)num) + 1 : 1;
}