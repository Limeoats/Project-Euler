/*
 * Problem 58: Spiral primes
 * By: Mark Guerra
 * 9/13/2016
*/

#include "main.h"
#include "utils.h"

/*
 * Let [i] be the side length of the [i]*[i] square.
 * According to the problem, we only need to focus on
 * squares where side length [i] is odd (1, 3, 5, etc).
 * Therefore, the outer infinite loop is increasing the
 * side length by 2 each time around.
 * The formulas for the four corners of the square with
 * side length [i] are:
 * Bottom right: [i]^2
 * Bottom left: [i]^2 - ([i] - 1)
 * Top left: [i]^2 - 2([i] - 1)
 * Top right: [i]^2 - 3([i] - 1)
 * Therefore, a simple inner for-loop allows us to get each
 * of the corners and determine if they are prime. If so,
 * increase the prime counter.
 * The formula for total diagonal numbers is side length [i] * 2 - 1.
 * Finally, check the ratio of primes / total diagonal numbers and see if it
 * is less than 10%. If so, return side length [i]. Otherwise, increase
 * side length [i] by 2 and repeat the process.
 */

int Problem058::getAnswer() {
    int primes = 0, i = 1;
    while (true) {
        for (int j = 0; j < 4; ++j) {
            primes += utils::isPrime(static_cast<int>(powl(i, 2)) - j * (i - 1));
        }
        if (i > 1 && (static_cast<double>(primes) / (i * 2 - 1)) * 100 < 10) {
            return i;
        }
        i += 2;
    }
}