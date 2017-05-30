/*
 * Problem 29: Distinct powers
 * By: Mark Guerra
 * 12/3/2015
 */

#include "main.h"

#include <unordered_set>
#include <cmath>

/*
 * I first create an unordered_set of doubles [results]
 * I use an unordered set because it prevents duplicates.
 * Then a nested for loop goes around and gets all of the
 * powers. Those non-duplicate powers are inserted into [results].
 * Finally, the size of [results] is returned and printed out.
 */

std::string Problem029::get_answer() {
    std::unordered_set<double> results;
    for (double i = 2; i <= 100; i++) {
        for (double j = 2; j <= 100; j++) {
            results.insert(pow(i, j));
        }
    }
    return std::to_string(results.size());
}