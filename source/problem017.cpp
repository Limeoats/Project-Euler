/* Problem 17: Number letter counts
 * By: Mark Guerra
 * 11/5/2015
 */

#include "problem17.h"
#include "utils.h"

#include <sstream>
#include <iostream>

std::string ones[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
std::string specials[10] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
std::string tens[8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
std::string hundreds[9] = {"onehundred", "twohundred", "threehundred", "fourhundred", "fivehundred", "sixhundred", "sevenhundred", "eighthundred", "ninehundred"};
std::string thousands[1] = {"onethousand"};

long problem17::getNumLetters(int startNum, int endNum) {
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

long problem17::getAnswer() {
    return getNumLetters(1, 1000);
}