/* Problem 29: Distinct powers
 * By: Mark Guerra
 * 12/3/2015
 */

#include "problem29.h"

#include <unordered_set>
#include <cmath>

/*
 * I first create an unordered_set of doubles [results]
 * I use an unordered set because it prevents duplicates.
 * Then a nested for loop goes around and gets all of the
 * powers. Those non-duplicate powers are inserted into [results].
 * Finally, the size of [results] is returned and printed out.
 */

unsigned int problem29::getAnswer() {
    std::unordered_set<double> results;
    for (double i = 2; i <= 100; i++) {
        for (double j = 2; j <= 100; j++) {
            results.insert(pow(i, j));
        }
    }
    return results.size();
}