/*
 * problem051.cpp
 * By: Mark Guerra
 * 5/20/2016
*/

#include "main.h"
#include "utils.h"

#include <iostream>

/*
 * I started by creating a new data structure called NumberInfo. This data structure contains
 * two important elements: a number and a map of each digit and their location(s). This allows
 * us to determine if the number repeats - and if so, how many times / the locations.
 * The program starts by using the Sieve of Eratosthenes to quickly generate the prime numbers
 * up to 1,000,000. It then creates an iterator at the point in that list where the element is
 * closest to 100,000. I wanted to start at 6 digit numbers so I decided 100,000 was a good place
 * to start. The program then loops through every number after 100,000 in the list, locates each digit
 * in the number, and adds it to a map along with its location. All of that data is then passed into
 * the [calculate] function.
 * In the [calculate] function, the program loops through each NumberInfo [n] passed in. It checks
 * each digit 0-9 to see if [n] contains it. If so, it makes sure it contains it at least 3 times,
 * as per the problem. If it does, the program converts the whole number to a string and loops through
 * each digit. The program replaces each of the repeating digits with a number 0-9. Before trying the
 * next number, the new number is checked to make sure it is prime and that it does not start with
 * 0 (those numbers starting with 0 do not count). If so, the result is added to
 * the [results] vector. Once the size of the results vector reaches [familySize] (8), the results vector is returned.
 * Finally, the results vector is sorted and the first element is printed.
 */

std::vector<long> Problem051::calculate(std::vector<Problem051::NumberInfo>& numbers, int familySize) {
    std::vector<long> results;
    for (Problem051::NumberInfo &n : numbers) {
        for (int a = 0; a < 10; ++a) {
            if (n.DigitPositions[a].size() >= 3) {
                std::string str = std::to_string(n.Number);
                for (int i = 0; i < 10; ++i) {
                    for (int j = 0; j < n.DigitPositions[a].size(); ++j) {
                        str[n.DigitPositions[a][j]] = static_cast<char>(i + '0');
                    }
                    if (str[0] != '0' && utils::isPrime(std::stoi(str))) {
                        results.push_back(std::stol(str));
                    }
                }
            }
        }
        if (results.size() == familySize) {
            return results;
        }
        else {
            results.clear();
        }
    }
}

std::string Problem051::get_answer() {
    std::vector<long> primes = utils::generatePrimes(1000000);
    std::vector<long>::iterator it = std::find(primes.begin(), primes.end(), utils::closest(primes, 100000));
    std::vector<Problem051::NumberInfo> numbers;
    for (; it < primes.end(); ++it) {
        std::string str = std::to_string(*it);
        std::map<unsigned int, std::vector<unsigned int>> digitLocs;
        for (unsigned int i = 0; i < str.size(); ++i) {
            digitLocs[str[i] - '0'].push_back(i);
        }
        numbers.push_back(Problem051::NumberInfo(std::stoul(str), digitLocs));
    }
    auto results = calculate(numbers, 8);
    std::sort(results.begin(), results.end(), [](long a, long b) { return a < b; });
    return std::to_string(results.front());
}