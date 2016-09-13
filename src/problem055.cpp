/*
 * Problem 55: Lychrel numbers
 * By: Mark Guerra
 * 9/8/2016
*/

#include "utils.h"
#include "problem055.h"

/*
 * Initialize a counter [c] to 0. Loop [i] from
 * 10 to 9999 and check if [i] is a Lychrel number.
 * If so, increment [c]. Finally, return [c] and
 * print it.
 */

int problem055::getAnswer() {
    int c = 0;
    for (unsigned int i = 10; i < 10000; ++i) {
        c += utils::isLychrel(i);
    }
    return c;
}