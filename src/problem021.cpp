/* Problem 21: Amicable number
 * By: Mark Guerra
 * 11/19/2015
 */

#include "main.h"

#include <vector>
#include <numeric>

long Problem021::sumOfProperDivisors(int n) {
    std::vector<int> pd;
    for (int i = 1; i <= (n / 2); i++) {
        if (n % i == 0) {
            pd.push_back(i);
        }
    }
    return std::accumulate(pd.begin(), pd.end(), 0);
}

bool Problem021::isAmicable(int a) {
    int ans = sumOfProperDivisors(a);
    return sumOfProperDivisors(ans) == a && ans != a;
}

long Problem021::getAnswer() {
    std::vector<int> amicableNumbers;
    for (int i = 1; i < 10000; i++) {
        if (isAmicable(i)) {
            amicableNumbers.push_back(i);
        }
    }
    return std::accumulate(amicableNumbers.begin(), amicableNumbers.end(), 0);
}