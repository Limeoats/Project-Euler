/*
 * Problem 69: Totient maximum
 * By: Mark Guerra
 * 12/12/2016
*/

#include "main.h"
#include "utils.h"

/*
 * Create variables [max] and [maxN] to keep track of the maximum [n] value and
 * the maximum [n] / phi[n] values. Generate a list of all Phi values up to
 * 1000000 and then iterate through that list and calculate max. When done
 * iterating, return [maxN] and print.
*/

std::string Problem069::getAnswer() {
    double max = 0.0, maxN = 0.0;
    std::vector<long> list = utils::generatePhi(1000000);
    for (double i = 0.0; i < list.size(); ++i) {
        if (list[i] == 0) continue;
        if (i / list[i] > max) {
            maxN = i;
            max = i / list[i];
        }
    }
    return std::to_string(static_cast<int>(maxN));
}