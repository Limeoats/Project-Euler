/*
 * Problem 74: Digit factorial chains
 * By: Mark Guerra
 * 12/15/2016
*/

#include "main.h"
#include "utils.h"

/*
 * I start by creating an array of integers that hold the factorial values for each of the digits [0-9]. This is
 * so that I am not calculating the factorial each time for every number. I can simply access the array quickly
 * and get the value. I created a DigitFactorialSum method that loops through each digit in an integer,
 * gets the factorial of that digit, and then adds it to a [sum]. It then returns the sum.
 * For the main method, I create a counter [count] and initialize it to 0. I then start a loop for the range
 * [2, 1000000]. I then start a loop that gets the DigitFactorialSum of [current]. If that number has already
 * been seen, break out of the loop and check if the list [terms] has 60 items. If it does, increase [count].
 * After [i] reaches 1000000 in the loop, return count and print it.
*/

Problem074::Problem074() {
    for (int i = 0; i < 10; ++i) {
        this->_digitFactorials[i] = utils::factorial(i);
    }
}

int Problem074::digitFactorialSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += this->_digitFactorials[num % 10];
        num /= 10;
    }
    return sum;
}

std::string Problem074::getAnswer() {
    int count = 0;
    std::vector<int> terms;
    for (int i = 2; i < 1000000; ++i) {
        terms.clear();
        terms = {i};
        int current = i;
        while (true) {
            current = this->digitFactorialSum(current);
            if (utils::contains(terms, current)) break;
            terms.push_back(current);
        }
        if (terms.size() == 60) ++count;
    }
    return std::to_string(count);
}