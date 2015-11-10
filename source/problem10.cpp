#include "problem10.h"
#include "utils.h"

long problem10::getSumOfPrimesBelowNum(int num) {
    long total = 2;
    for (int i = 3; i < num; i += 2) {
        if (utils::isPrime(i)) {
            total += i;
        }
    }
    return total;
}

long problem10::getAnswer() {
    return getSumOfPrimesBelowNum(2000000);
}