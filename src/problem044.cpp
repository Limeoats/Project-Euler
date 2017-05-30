/* Problem 44: Pentagon numbers
 * By: Mark Guerra
 * 12/16/2015
 */

#include "main.h"

#include <algorithm>
#include <array>
#include <vector>
#include <stdlib.h>
#include <math.h>


/*
 * To solve this problem, there are two loops:
 *      -The "infinite" while outer loop that generates
 *       pentagonal numbers.
 *      -The inner for loop which loops through all of the
 *       pentagonal numbers less than the outer loop's
 *       generated pentagonal number.
 * With each of those numbers generated from the loops,
 * we simply add/subtract them and check if they are pentagonal
 * using the function:
 *      n = (sqrt(1.0 + 24.0 * x) + 1.0) / 6.0
 *      If n is a natural number, then the number is pentagonal.
 * Once we find the first one to match this criteria, we return it
 * and print it to the screen.
 *
 */

bool Problem044::isPentagonal(int x) {
    double t = (sqrt(1.0 + 24.0 * x) + 1.0) / 6.0;
    return  t == int(t);
}

int Problem044::pentagonalNumber(int n) {
    return n * (3 * n - 1) / 2;
}

std::string Problem044::get_answer() {
    int x = 1;
    while (true) {
        int pnx = pentagonalNumber(x);
        for (int y = x - 1; y > 0; --y) {
            int pny = pentagonalNumber(y);
            if (isPentagonal(pnx + pny) && isPentagonal(pnx - pny)) {
                return std::to_string(pnx - pny);
            }
        }
        ++x;
    }
}