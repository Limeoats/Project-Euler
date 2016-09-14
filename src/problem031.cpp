/* Problem 31: Coin sums
 * By: Mark Guerra
 * 12/3/2015
 */

#include "main.h"

/*
 * [t] is a list of each denomination of English currency.
 * Pass 200 (200 pence in 2 pounds) and [t] into denomFunc.
 * denomFunc uses recursion to go through each combination
 * of denominations that add up to 200 and get the total
 * number of them. When denomFunc returns, it has the total
 * number of combinations and that total is printed.
 */

unsigned int Problem031::denomFunc(int n, std::vector<int> &denoms) {
    if (denoms.empty() || n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else {
        auto oldDenoms = denoms;
        denoms.erase(denoms.begin());
        return denomFunc(n - oldDenoms.front(), oldDenoms) + denomFunc(n, denoms);
    }
}

unsigned int Problem031::getAnswer() {
    std::vector<int> t = {1,2,5,10,20,50,100,200};
    return denomFunc(200, t);
}