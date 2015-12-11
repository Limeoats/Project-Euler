#include <algorithm>
#include <iostream>
#include <cmath>

#include "utils.h"


bool utils::isPrime(int num) {
    if (num <= 1)
        return false;
    if ((num & 1) == 0)
        return num == 2;
    int root = sqrt(num);
    for (int i = 3; i <= root; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int utils::factorial(int n) {
    int x = 1;
    for (int i = 1; i <= n; ++i) {
        x *= i;
    }
    return x;
}

std::vector<std::string> utils::split(std::string str, char c) {
    std::vector<std::string> list;
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, c)) {
        list.push_back(item);
    }
    return list;
}

std::string utils::ltrim(std::string str, char c) {
    str.erase(0, str.find_first_not_of(c));
    return str;
}

int utils::numDigits(int num) {
    return num > 0 ? (int)log10((double)num) + 1 : 1;
}

void utils::replace(std::string &str, std::string seq, std::string newstr) {
    size_t index = 0;
    while (true) {
        index = str.find(seq);
        if (index == std::string::npos) {
            break;
        }
        str.replace(index, seq.length(), newstr);
        index += newstr.length();
    }
}

std::string utils::toString(long long num) {
    int count = 0;
    for (int t = num; t != 0; count++) { t /= 10;}
    char x[count];
    sprintf(x, "%d", num);
    return std::string(x);
}

std::vector<long> utils::generatePrimes(long limit) {
    long bound = (long)floor(sqrt(limit));
    std::vector<bool> primes(limit, true);
    std::vector<long> result;
    for (long i = 4; i < limit; i += 2) {
        primes[i] = false;
    }
    result.push_back(2);
    for (long i = 3; i <= bound; i += 2) {
        if (primes[i] == true) {
            result.push_back(i);
            for (long j = (long)pow(i, 2); j < limit; j += i*2) {
                primes[j] = false;
            }
        }
    }
    for (long i = bound + 1; i < limit; ++i) {
        if (primes[i] == true) {
            result.push_back(i);
        }
    }
    return result;

}