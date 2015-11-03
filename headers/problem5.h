#ifndef PROBLEM_5_H
#define PROBLEM_5_H

//2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

namespace problem5 {

    int getSmallestNumberDividedByRange(int begin, int end) {
        long c = 1;
        int successes = 0;
        while (true) {
            for (long i = begin; i < end; i++) {
                if (c % i != 0)
                    break;
                else
                    successes++;
            }
            if (successes != end - begin) {
                successes = 0;
                c++;
            }
            else {
                return c;
            }
        }
    }

    int getAnswer() {
        return getSmallestNumberDividedByRange(1, 20);
    }

}


#endif
