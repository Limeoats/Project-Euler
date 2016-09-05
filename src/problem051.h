/*
 * Problem 51: Prime digit replacements
 * By: Mark Guerra
 * 5/20/2016
*/

#ifndef PROJECT_EULER_PROBLEM051_H
#define PROJECT_EULER_PROBLEM051_H

/*
 * By replacing the 1st digit of the 2-digit number *3, it turns out that six of the
 * nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.
 *
 * By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number
 * is the first example having seven primes among the ten generated numbers, yielding the
 * family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the
 * first member of this family, is the smallest prime with this property.
 *
 * Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits)
 * with the same digit, is part of an eight prime value family.
 */

#include <vector>
#include <map>

namespace problem051 {
    struct NumberInfo {
    public:
        unsigned long Number;
        std::map<unsigned int, std::vector<unsigned int>> DigitPositions;
        NumberInfo(unsigned long number, std::map<unsigned int, std::vector<unsigned int>> digitPositions) {
            this->Number = number;
            this->DigitPositions = digitPositions;
        }
    };
    std::vector<long> calculate(std::vector<problem051::NumberInfo>& numbers, int familySize);
    long getAnswer();
};


#endif
