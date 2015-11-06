//
// Created by Mark Guerra on 11/5/15.
//

#ifndef PROBLEM_17_H
#define PROBLEM_17_H

#include <sstream>
#include <iostream>

#include "utils.h"

//If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
//If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
//NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen)
// contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

namespace problem17 {

    std::string ones[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::string specials[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    std::string tens[8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    std::string hundreds[9] = {"onehundred", "twohundred", "threehundred", "fourhundred", "fivehundred", "sixhundred", "sevenhundred", "eighthundred", "ninehundred"};
    std::string thousands[1] = {"onethousand"};

    long getNumLetters(int startNum, int endNum) {
        if (endNum > 1000 || startNum < 1) {
            std::cerr << "The starting number must be greater than 0 and the ending number must be less than 1000" << std::endl;
            return -1;
        }
        int letterTotal = 0;
        for (int i = startNum; i <= endNum; i++) {
            int numDigits = utils::numDigits(i);
            if (numDigits == 1) {
                letterTotal += ones[i - 1].length();
                continue;
            }
            else if (numDigits == 2) {
                if (i < 20) {
                    letterTotal += specials[i % 10].length();
                }
                else {
                    int x = i;
                    if (x % 10 != 0)
                        letterTotal += ones[(x % 10) - 1].length();
                    x /= 10;
                    letterTotal += tens[(x % 10) - 2].length();
                }
                continue;
            }
            else if (numDigits == 3) {
                //Add three for the word "and"
                letterTotal += 3;
                //First figure out if we need any specials.
                int x = i;
                x /= 10;
                if (x % 10 == 1) {
                    letterTotal += specials[i % 10].length();
                }
                else {
                    x = i;
                    if (x % 10 != 0)
                        letterTotal += ones[(x % 10) - 1].length();
                    x /= 10;
                    if (x % 10 != 0)
                        letterTotal += tens[(x % 10) - 2].length();
                    else {
                        if (i % 10 == 0) {
                            letterTotal -= 3;
                        }
                    }
                }
                x /= 10;
                letterTotal += hundreds[(x % 10) - 1].length();
                continue;
            }
            else if (numDigits == 4) {
                int x = i;
                for (int i = 0; i < 3; i++) {
                    x /= 10;
                }
                letterTotal += thousands[1 - (x % 10)].length();
                continue;
            }

        }
        return letterTotal;
    }

    long getAnswer() {
        return getNumLetters(1, 1000);
    }
}

#endif
