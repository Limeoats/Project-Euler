/*
 * Problem 14: Longest Collatz sequence
 * By: Mark Guerra
 * 10/28/2015
 */

#include "main.h"

long Problem014::getNextNumInSequence(long curNum) {
    if ((curNum & 1) == 1)
        return (3*curNum) + 1;  //odd
    else
        return curNum / 2;      //even
}

int Problem014::getStartingNumberUnder(int max) {
    long longestChain = 1;
    long longestChainStartingNumber = 2;
    long currentChain;
    for (int i = 2; i < max; i++) {
        currentChain = 1;
        long curNum = i;
        while (curNum > 1) {
            curNum = getNextNumInSequence(curNum);
            currentChain++;
        }
        if (curNum == 1) {
            if (currentChain >= longestChain) {
                longestChain = currentChain;
                longestChainStartingNumber = i;
            }

        }
    }
    return longestChainStartingNumber;
}

std::string Problem014::get_answer() {
    return std::to_string(getStartingNumberUnder(1000000));
}