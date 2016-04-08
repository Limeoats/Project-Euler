/* Problem 20: Factorial digit sum
 * By: Mark Guerra
 * 11/19/2015
 */

#include "problem020.h"

#include "utils.h"

BigNumber problem020::factorial(int n) {
    BigNumber b("1");
    for (int i = 1; i <= n; i++) {
        b  *= BigNumber(utils::toString(i));
    }
    return b;
}

long problem020::getAnswer() {
    BigNumber b = factorial(100);
    long sum = 0;
    for (int i = 0; i < b.getString().size(); i++) {
        sum += (b.getString()[i] - '0');
    }
    return sum;
}