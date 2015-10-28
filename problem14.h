#ifndef PROBLEM_14_H
#define PROBLEM_14_H

#include <stdio.h>

//The following iterative sequence is defined for the set of positive integers:

//n → n/2 (n is even)
//n → 3n + 1 (n is odd)

//Using the rule above and starting with 13, we generate the following sequence:
//13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

//It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
//Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

//Which starting number, under one million, produces the longest chain?

//Note: Once the chain starts the terms are allowed to go above one million.


namespace problem14 {

    int getNextNumInSequence(int curNum) {
        if ((curNum & 1) == 1)
            return (3*curNum) + 1;  //odd
        else
            return curNum / 2;      //even
    }

    int getStartingNumberUnder(int max) {
        int longestChain = 1;
        int longestChainStartingNumber = 2;
        int currentChain = 1;
        for (int i = 2; i < max; i++) {
            currentChain = 1;
            int curNum = i;
            while (curNum > 1) {
                curNum = getNextNumInSequence(curNum);
                currentChain++;
            }
            if (curNum == 1) {
                currentChain++; //For 1
                if (currentChain > longestChain) {
                    longestChain = currentChain;
                    longestChainStartingNumber = i;
                }

            }
        }
        return longestChainStartingNumber;
    }

    int getAnswer() {
        return getStartingNumberUnder(1000000);
    }

}

#endif
