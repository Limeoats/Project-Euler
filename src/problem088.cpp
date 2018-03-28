/*
 * Problem 88 - Product-sum numbers
 * By: Mark Guerra
 * 6/1/2017
*/

#include <sstream>
#include <set>
#include <numeric>

#include "main.h"

// What we know:
// 1. k <= mps(k) <= 2k
// 2. We can always add as many 1's as we need to get product-sum since n x 1 x 1 x 1... == n

// k=2: 4 = 2 × 2 = 2 + 2
// k=3: 6 = 1 × 2 × 3 = 1 + 2 + 3
// k=4: 8 = 1 × 1 × 2 × 4 = 1 + 1 + 2 + 4
// k=5: 8 = 1 × 1 × 2 × 2 × 2 = 1 + 1 + 2 + 2 + 2
// k=6: 12 = 1 × 1 × 1 × 1 × 2 × 6 = 1 + 1 + 1 + 1 + 2 + 6

const int maxK = 12000;

std::vector<int> n;

void mps(int number, int sum, int product, int start) {
    int k = number - sum + product;
    if (k < maxK) {
        if (number < n[k]) {
            n[k] = number;
        }
        for (int i = start; i < maxK / number * 2; ++i) {
            mps(number * i, sum + i, product + 1, i);
        }
    }
}

std::string Problem088::get_answer() {
    for (int i = 0; i < maxK; ++i) {
        n.push_back(maxK * 2);
    }
    mps(1, 1, 1, 2);
    std::set<int> ns(n.begin() + 2, n.end());
    return std::to_string(std::accumulate(ns.begin(), ns.end(), 0));
}