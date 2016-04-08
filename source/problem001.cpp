/* Problem 1: Multiples of 3 and 5
 * By: Mark Guerra
 * 10/14/2015
 */

/*
 * We start by creating an empty vector of size [numberUnder - 1].
 * We then fill it with incrementing numbers starting at 1.
 * Then, any numbers that aren't divisible by 3 or 5 are removed from [multiples].
 * The remaining numbers are added together and printed to the screen.
 */

#include "problem001.h"
#include "utils.h"

std::vector<int> problem001::getMultiplesUnder(int numberUnder) {
    std::vector<int> multiples(numberUnder - 1);
    std::iota(std::begin(multiples), std::end(multiples), 1);
    multiples.erase(std::remove_if(multiples.begin(), multiples.end(), [&](int &i)->bool {return i % 3 != 0 && i % 5 != 0;}), multiples.end());
    return multiples;
}

int problem001::getAnswer() {
    std::vector<int> multiples = getMultiplesUnder(1000);
    return std::accumulate(multiples.begin(), multiples.end(), 0);
}