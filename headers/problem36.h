/* Problem 36: Double-base palindromes
 * By: Mark Guerra
 * 12/7/2015
 */

#ifndef PROBLEM_36_H
#define PROBLEM_36_H

#include <string>

/*
 * The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
 * Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
 * (Please note that the palindromic number, in either base, may not include leading zeros.)
 */

namespace problem36 {
    bool isPalindrome(std::string n);
    int getAnswer();
}


#endif