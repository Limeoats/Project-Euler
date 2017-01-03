#include <algorithm>
#include <iostream>

#include "utils.h"

char utils::asciiToChar(int ascii) {
    return char(ascii);
}

int utils::charToAscii(char c) {
    return int(c);
}


unsigned long long utils::choose(long n, long k) {
    if (k == 0) return 1;
    return (n * choose(n - 1, k - 1)) / k;
}

int utils::digitSum(std::string number) {
    int sum = 0;
    for (std::size_t i = 0; i < number.size(); ++i) {
        sum += number[i] - '0';
    }
    return sum;
}

long long utils::factorial(int n) {
    long long x = 1;
    for (long long i = 1; i <= n; ++i) {
        x *= i;
    }
    return x;
}

std::vector<long> utils::generatePhi(long max) {
    long i, j;
    std::vector<long> phi(max);
    for (i = 1; i < max; ++i)
        phi[i] = i;
    for (i = 2; i < max; ++i) {
        if (phi[i] != i) continue;
        for (j = i; j < max; j += i)
            phi[j] = phi[j] / i * (i - 1);
    }
    return phi;
}

std::vector<long> utils::generatePrimes(long limit) {
    long bound = (long)sqrt(limit);
    std::vector<bool> primes(limit, true);
    std::vector<long> result;
    
    for (long i = 2; i < bound; ++i) {
        if (primes[i]) {
            for (long j = i * i; j < limit; j += i) {
                primes[j] = false;
            }
        }
    }
    result.push_back(2);
    for (long i = 3; i < primes.size(); ++i) {
        if (primes[i]) {
            result.push_back(i);
        }
    }
    return result;
}

bool utils::isLychrel(unsigned long long n, int iterations) {
    unsigned long long sum = n;
    for (int i = 0; i < iterations; ++i) {
        sum += utils::reverseNumber(sum);
        if (utils::isPalindrome(sum)) {
            return false;
        }
    }
    return true;
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

std::vector<std::string> utils::split(std::string str, char c) {
    std::vector<std::string> list;
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, c)) {
        list.push_back(item);
    }
    return list;
}



