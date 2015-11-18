/* Problem 4: Largest palindrome product
 * By: Mark Guerra
 * 10/19/2015
 */

#ifndef PROBLEM_4_H
#define PROBLEM_4_H

//A palindromic number reads the same both ways. The largest palindrome made from the product
//of two 2-digit numbers is 9009 = 91 × 99.
//Find the largest palindrome made from the product of two 3-digit numbers.

namespace problem4 {
    bool isPalindrome(int num);
    int getLargestPalindrome();
    int getAnswer();
}

#endif
