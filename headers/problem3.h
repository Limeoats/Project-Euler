#ifndef PROBLEM_3_H
#define PROBLEM_3_H

#include <cmath>

//The prime factors of 13195 are 5, 7, 13 and 29.
//What is the largest prime factor of the number 600851475143 ?

namespace problem3 {

    long getGreatestPrimeFactor(long num) {
        int i = 2;
        while (pow(i, 2) < num) {
            while (num % i == 0) {
                num /= i;
            }
            i++;
        }
        return num;
    }

    long getAnswer() {
        return getGreatestPrimeFactor(600851475143L);        
    }

}



#endif
