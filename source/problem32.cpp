/* Problem 32: Pandigital products
 * By: Mark Guerra
 * 12/3/2015
 */

#include "problem32.h"
#include "utils.h"

#include <unordered_set>
#include <numeric>

/*
 * The program loops through numbers up to 9876 to find
 * the ones where both numbers and the product combined
 * are a pandigital number 1-9. If it is, the product
 * is stored in [products]. At the end, we find the sum
 * of all numbers in [products] and print it.
 */

bool problem32::isPandigital(std::string n) {
    int len = n.size();
    for (int i = 1; i <= len; ++i) {
        if (n.find(i + '0') == std::string::npos)
            return false;
    }
    return true;
}

long problem32::getAnswer() {
    std::unordered_set<long> products;
    for (int i = 2; i < 9876; i++) {
        for (int j = 123; j < 9876 / i; j++) {
            if (i == j) continue;
            std::string str1 = utils::toString(i);
            std::string str2 = utils::toString(j);
            std::string product = utils::toString(i*j);
            std::string str = str1 + str2 + product;
            if (str.size() != 9) continue;
            if (isPandigital(str)) {
                products.insert(i * j);
            }
        }
    }
    return std::accumulate(products.begin(), products.end(), 0);
}