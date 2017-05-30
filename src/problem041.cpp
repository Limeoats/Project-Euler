/* Problem 41: Pandigital prime
 * By: Mark Guerra
 * 12/11/2015
 */

#include "main.h"
#include "utils.h"

//There are two keys to making this program run fast:
//  -Digit sums
//  -The Sieve of Eratosthenes
//We start by generating all of the primes up to our upper limit.
//We can see that adding each number of digits together
//results in 1, 2, 3, 5, 6, 8, and 9 digits being divisible by 3.
//Therefore, we know that they cannot be prime. That leaves
//only the 4 digit combinations and the 7 digit combinations.
//Therefore, we know our upper limit is 7654321.
//We also know that the number must be either 4 digits or 7 digits.
//Once we get the highest number, we return it and print it out.

bool Problem041::isPandigital(long n) {
    std::string str = std::to_string(n);
    int len = str.size();
    for (int i = 1; i <= len; ++i) {
        if (str.find(i + '0') == std::string::npos)
            return false;
    }
    return true;
}

std::string Problem041::get_answer() {
    long highest = 0;
    auto primes = utils::generatePrimes(7654321);
    for (long t : primes) {
        if (isPandigital(t)) {
            highest = t;
        }
    }
    return std::to_string(highest);
}