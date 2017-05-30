/*
 * Problem 78: Coin partitions
 * By: Mark Guerra
 * 3/29/2017
*/

#include "main.h"
#include "utils.h"

/*
 * To solve this problem, I used Euler's generating function for partitions.
 * Part of the sequence is using Generalized Pentagonal numbers, which I
 * calculate and plug directly into the generating function. I continue
 * looping through the next generalized pentagonal number until it becomes
 * greater than [n]. At that point, I add the current value of [total] % 1000000 to
 * the list of partition counts and move on to the next value of [n]. It is faster to
 * add [total] % 1000000 because we only care about the last 7 digits of the number to
 * determine if it is divisible by 1000000. Once I find a [total] that is divisible by 1000000,
 * I return it and print.
*/

int Problem078::getGeneralizedPentagonal(int n) {
    return (3 * n * n - n) / 2;
}

std::string Problem078::get_answer() {
    int n = 2;
    std::vector<long> p = {1, 1};
    while (true) {
        bool neg = false, first = true, second = false;
        int c = 0;
        int pentN = 1;
        long total = 0;
        int pent = this->getGeneralizedPentagonal(pentN);
        while (pent <= n) {
            ++c;
            if (first) {
                total += p[n - pent];
                first = false;
                second = true;
            }
            else {
                total += neg ? p[n - pent] * -1 : p[n - pent];
                if (second) {
                    second = false;
                    neg = true;
                    c = 0;
                }
                else {
                    if (c % 2 == 0) neg = !neg;
                }
            }
            pentN = pentN < 0 ? (abs(pentN) + 1) : (pentN * -1);
            pent = this->getGeneralizedPentagonal(pentN);
        }
        if (total % 1000000 == 0 && total != 0)
            return std::to_string(n);
        p.push_back(total % 1000000);
        ++n;
    }
}
