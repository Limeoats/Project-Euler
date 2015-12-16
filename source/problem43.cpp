/* Problem 43: Sub-string divisibility
 * By: Mark Guerra
 * 12/16/2015
 */

#include "problem43.h"
#include "utils.h"

#include <sstream>
#include <vector>


long problem43::getAnswer() {
    std::vector<std::string> pandigitalNumbers;
    std::string str = "0123456789";
    do {
        pandigitalNumbers.push_back(str);
    } while (std::next_permutation(str.begin(), str.end()));

    long sum = 0;
    int divs[7] = {2, 3, 5, 7, 11, 13, 17};
    for (std::string s : pandigitalNumbers) {
        int counter = 0;
        int beg = 2, mid = 3, end = 4;
        for (int j = 0; j < 7; j++) {
            std::stringstream ss;
            ss << s[beg-1] << s[mid-1] << s[end-1];
            if (atol(ss.str().c_str()) % divs[j] != 0) {
                if (counter >= 6) {
                    sum += atol(s.c_str());
                    break;
                }
                else {
                    counter++;
                    beg++;
                    end++;
                    mid++;
                }
            }

        }
    }
    return sum;
}