/*
 * Problem 53: Combinatoric selections 
 * By: Mark Guerra
 * 9/7/2016
*/

#include "main.h"
#include "utils.h"

/*
 * Create a counter variable [c] and initialize it to 0.
 * Start a loop for integer [n] from 23 to 100, and a second loop
 * for integer [r] from 0 to [n]. Increment [c] if [n] choose [r]
 * results in a value greater than 1,000,000. Finally, return [c]
 * and print it.
 */

unsigned int Problem053::getAnswer() {
    unsigned int c = 0;
    for (unsigned int n = 23; n <= 100; ++n) {
        for (unsigned int r = 0; r <= n; ++r) {
           c += utils::choose(n, r) > 1000000;
        }
    }
    return c;
}