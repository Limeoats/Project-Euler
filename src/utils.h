//Utils.h
//Contains helpful functions
//By: Mark Guerra

#ifndef UTILS_H
#define UTILS_H

#include <sstream>
#include <vector>
#include <algorithm>
#include <chrono>

namespace utils {

    //bool contains(const C &v, const T &x)
    //Parameters:
    //  v: a container of some sort
    //  x: the value being checked
    //Returns:
    //  true if the container v contains x, otherwise false
    template <class C, class T>
    inline bool contains(const C &v, const T &x) {
        return std::end(v) != std::find(std::begin(v), std::end(v), x);
    }

    //void removeDuplicates(const C &v)
    //Parameters:
    //  v: a container of some sort
    //Returns: None
    template<class C>
    inline void removeDuplicates(const C &v) {
        std::sort(v.begin(), v.end());
        v.erase(std::unique(v.begin(), v.end()), v.end());
    };

    template<class V, class T>
    inline T closest(const V &v, const T &t) {
        T closest = v[0];
        for (const T &m : v) {
            closest = abs(m - t) < abs(closest - t) ? m : closest;
        }
        return closest;
    };

    template <class T>
    inline T convertBinary(T n) {
        if (n / 2 != 0) {
            convertBinary(n/2);
        }
        return n;
    }

    template <class T>
    inline T reverseNumber(T n) {
        T reverse = 0;
        while (n != 0) {
            reverse = reverse * 10 + (n % 10);
            n /= 10;
        }
        return reverse;
    }

    template <class T>
    inline bool isPalindrome(T n) {
        return n == reverseNumber(n);
    }

    //bool isPrime(int num)
    //Parameters:
    //  num: the number being checked
    //Returns:
    //  true if num is prime, otherwise false
    bool isPrime(int num);

    //int factorial(int n)
    //Parameters:
    //  n: the number the factorial is being applied to
    //Returns:
    //  The result of the factorial
    long long factorial(int n);

    //vector<string> split(string str, char c)
    //Parameters:
    //  str: the string being split
    //  c: the delimiting character
    //Returns:
    //  a vector containing each of the split strings
    std::vector<std::string> split(std::string str, char c);

    //std::string ltrim(std::string str, char c)
    //  Params:
    //    str: the string being trimmed
    //    c: the character being trimmed
    //  Returns:
    //    The trimmed string
    std::string ltrim(std::string str, char c);

    //int numDigits(int num)
    //  Params:
    //    num: the number we are finding the length of
    //  Returns:
    //    The number of digits
    int numDigits(int num);

    //void replace(std::string &str, std::string seq, std::string newstr)
    //  Params:
    //    str: a reference to the string being changed
    //    seq: the sequence being replaced
    //    newstr: the string to replace seq with
    //  Returns:
    //    None
    void replace(std::string &str, std::string seq, std::string newstr);

    //std::string toString(long long num)
    //  Params:
    //    num: the number being converted into a string
    //  Returns:
    //    The number as a string
    std::string toString(long long num);

    //std::vector generatePrimes(int limit)
    //  Uses the Sieve of Eratosthenes
    //  Params:
    //    start: the starting point (optional)
    //    limit: the number to go up to
    //  Returns:
    //    A list of all primes up to the limit
    std::vector<long> generatePrimes(long limit);

    //unsigned long long choose(long n, long k)
    //  Choose algorithm for combinations
    //  Params:
    //      n: The number of digits, starting at 1
    //      k: The number of elements being chosen
    //  Returns:
    //      The number of results
    unsigned long long choose(long n, long k);

    //bool isLychrel(unsigned long long n, int iterations = 50)
    //  Determine if [n] is a Lychrel number
    //  A Lychrel number is one that never forms a palindrome
    //  through the reverse and add process.
    //  Params:
    //      n: The number being checked
    //      iterations: The number of times to try the reverse and add process.
    //                  Defaults to 50.
    //  Returns:
    //      Whether or not the [n] is a Lychrel number
    bool isLychrel(unsigned long long n, int iterations = 50);

    //int digitSum(std::string number)
    //  Calculate the sum of all digits in the number
    //  Params:
    //      number: a string of digits
    //  Returns:
    //      The sum of the digits
    int digitSum(std::string number);
}

#endif
