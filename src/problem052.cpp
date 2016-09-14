/*
 * problem052.cpp
 * By: Mark Guerra
 * 9/6/2016
*/

#include "main.h"

#include <algorithm>
#include <string>

/*
 * With [a] starting at 1, begin a loop. First, double [a] to get
 * the first number to check permutations with. Next, start another loop
 * where a number [i] goes up to 6, each time multiplying [a] by [i]. Then,
 * check if the product is a permutation of 2*[a]. If it is, keep going.
 * If the loop makes it up to 6*[a] and it is a permutation of the original 2*[a],
 * return [a] as the lowest number and print it.
 */

int Problem052::getAnswer() {
    unsigned int a = 1;
    while (true) {
        std::string original = std::to_string(2 * a);
        for (unsigned int i = 3; i < 7; ++i) {
            std::string next = std::to_string(i * a);
            if (!std::is_permutation(original.begin(), original.end(), next.begin())) {
                break;
            }
            if (i == 6) {
                return std::stoi(original) / 2;
            }
        }
        ++a;
    }
}
