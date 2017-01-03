//Utils.h
//Contains helpful functions
//By: Mark Guerra

#ifndef UTILS_H
#define UTILS_H

#include <sstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cmath>

namespace utils {
    
    /*
     * Convert an ASCII number to its character
     * Parameters:
     *   ascii: The ASCII value
     * Returns:
     *   The character value
     *
     */
    char asciiToChar(int ascii);
    
    /*
     * Convert a character to its ASCII int
     * Parameters:
     *   c: the character being converted
     * Returns:
     *   The integer ASCII value
     */
    int charToAscii(char c);
    
    /*
     * Choose algorithm for combinations
     * Parameters:
     *   n: The number of digits, starting at 1
     *   k: The number of elements being chosen
     * Returns:
     *   The number of results
     */
    unsigned long long choose(long n, long k);
    
    /*
     * Gets the closest value to [t] in container [v]
     * Parameters:
     *   v: a container
     *   t: the value being checked
     * Returns:
     *   The closest value to [t]
     */
    template<class V, class T>
    inline T closest(const V &v, const T &t) {
        T closest = v[0];
        for (const T &m : v) {
            closest = abs(m - t) < abs(closest - t) ? m : closest;
        }
        return closest;
    };
    
    /*
     * Concatenate two numbers together
     * Parameters:
     *   x: The first number
     *   y: The second number
     * Returns:
     *   The new value after concatenation
     */
    template <typename T>
    inline unsigned long long concat(const T &x, const T &y) {
        return std::stoull(std::string(std::to_string(x) + std::to_string(y)));
    }

    /*
     * Checks if a container [v] contains value [x]
     * Parameters:
     *   v: a container of some sort
     *   x: the value being checked
     * Returns:
     *   True if the container v contains x, otherwise false
     */
    template <class C, class T>
    inline bool contains(const C &v, const T &x) {
        return std::end(v) != std::find(std::begin(v), std::end(v), x);
    }
    
    /*
     * Convert a number [n] to binary
     * Parameters:
     *   n: the number being converted to binary
     * Returns:
     *   The binary value
     */
    template <class T>
    inline T convertBinary(T n) {
        if (n / 2 != 0) {
            convertBinary(n/2);
        }
        return n;
    }
    
    /*
     * Calculate the sum of all digits in a string number
     * Parameters:
     *   number: a string of digits
     * Returns:
     *   The sum of the digits
     */
    int digitSum(std::string number);
    
    /*
     * Get the factorial of a number
     * Parameters:
     *   n: the number the factorial is being applied to
     * Returns:
     *   The result of the factorial
     */
    long long factorial(int n);
    
    /*
     * Get the Greatest Common Divisor of two numbers
     * Parameters:
     *   a: the first number
     *   b: the second number
     * Returns:
     *   The greatest common divisor of [a] and [b]
     */
    long gcd(long a, long b);
    
    /*
     * Generate phi values using a variation of the Sieve of Eratosthenes
     * Parameters:
     *   max: the limit
     * Returns:
     *   A list of phi values
     */
    std::vector<long> generatePhi(long max);
    
    /*
     * Generate primes using the Sieve of Eratosthenes
     * Parameters:
     *   start: the starting point (optional)
     *   limit: the number to go up to
     * Returns:
     *   A list of all primes up to the limit
     */
    std::vector<long> generatePrimes(long limit);
    
    /*
     * Determine if [n] is a Lychrel number
     * A Lychrel number is one that never forms a palindrome
     * through the reverse and add process.
     * Parameters:
     *   n: The number being checked
     *   iterations: The number of times to try the reverse and add process.
     *     Defaults to 50.
     * Returns:
     *   Whether or not [n] is a Lychrel number
     */
    bool isLychrel(unsigned long long n, int iterations = 50);
    
    /*
     * Check if a number is a palindrome
     * Parameters:
     *   n: the number being checked
     * Returns:
     *   True if palindrome, otherwise false
     */
    template <class T>
    inline bool isPalindrome(T n) {
        T reverse = 0;
        while (n != 0) {
            reverse = reverse * 10 + (n % 10);
            n /= 10;
        }
        return n == reverse;
    }
    
    /*
     * Check if a number is prime
     * Parameters:
     *   num: the number being checked
     * Returns:
     *   True if num is prime, otherwise false
     */
    template<class T>
    inline bool isPrime(T num) {
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
    
    /*
     * Trim the left side of a string
     * Parameters:
     *   str: the string being trimmed
     *   c: the character being trimmed
     * Returns:
     *   The trimmed string
     */
    std::string ltrim(std::string str, char c);
    
    /*
     * Get the number of digits in a number
     * Parameters:
     *   num: the number we are finding the length of
     * Returns:
     *   The number of digits
     */
    int numDigits(int num);

    /*
     * Remove duplicates from a container [v]
     * Parameters:
     *   v: a container of some sort
     * Returns: None
     */
    template<class C>
    inline void removeDuplicates(const C &v) {
        std::sort(v.begin(), v.end());
        v.erase(std::unique(v.begin(), v.end()), v.end());
    }
    
    /*
     * Replace part of a string with a new string
     * Parameters:
     *   str: a reference to the string being changed
     *   seq: the sequence being replaced
     *   newstr: the string to replace seq with
     * Returns: None
     */
    void replace(std::string &str, std::string seq, std::string newstr);
    
    /*
     * Reverse a number
     * Parameters:
     *   n: the number to be reversed
     * Returns:
     *   The reversed number
     */
    template <class T>
    inline T reverseNumber(T n) {
        T reverse = 0;
        while (n != 0) {
            reverse = reverse * 10 + (n % 10);
            n /= 10;
        }
        return reverse;
    }
    
    /*
     * Split a string
     * Parameters:
     *   str: the string being split
     *   c: the delimiting character
     * Returns:
     *   a vector containing each of the split strings
     */
    std::vector<std::string> split(std::string str, char c);
    
}

#endif
