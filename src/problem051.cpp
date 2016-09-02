/*
 * problem051.cpp
 * By: Mark Guerra
 * 5/20/2016
*/

#include "problem051.h"
#include "utils.h"

#include <iostream>
#include <vector>

long problem051::getAnswer() {
    std::vector<long> primes = utils::generatePrimes(1000000);
    return utils::closest(primes, 60000);
}