/* Problem 48: Self powers
 * By: Mark Guerra
 * 12/18/2015
 */

#include "problem48.h"

/*
 * Due to the fact that we only need to add
 * the last 10 digits of the numbers, we can
 * just add the last 10 (or however many digits are in
 * the number up to 10) digits together. We can get the last
 * 10- digits by using mod 10000000000. The final result
 * can fit in a long long, so it ruins quickly. When we get
 * the answer, return it and print it.
 */

long long problem48::getAnswer() {
    const long long MOD = 10000000000LL;
    long long result = 0;
    for (int i = 1; i <= 1000; ++i) {
        long long x = 1, exp = 1;
        while (exp <= i) {
            x = x * i % MOD;
            ++exp;
        }
        result = (result + x) % MOD;
    }
    return result;
}