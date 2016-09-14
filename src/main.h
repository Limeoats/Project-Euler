#ifndef PROJECT_EULER_MAIN_H
#define PROJECT_EULER_MAIN_H

#include <vector>
#include <map>

#include "bignumber.h"

class Problem001 {
public:
    int getAnswer();
};

class Problem002 {
public:
    bool isOdd(int i);
    std::vector<int> getFibNumbers(int max);
    int getAnswer();
};

class Problem003 {
public:
    long getGreatestPrimeFactor(long long num);
    long getAnswer();
};

class Problem004 {
public:
    bool isPalindrome(int num);
    int getLargestPalindrome();
    int getAnswer();
};

class Problem005 {
public:
    int getSmallestNumberDividedByRange(int begin, int end);
    int getAnswer();
};

class Problem006 {
public:
    int solveProblem(int numNaturalNumbers);
    int getAnswer();
};

class Problem007 {
public:
    int getNthPrimeNumber(int n);
    int getAnswer();
};

class Problem008 {
public:
    long getGreatestProduct(int howMany);
    long getAnswer();
};

class Problem009 {
public:
    double getProductOfPythagoreanTriplet(int sumOfABC);
    int getAnswer();
};

class Problem010 {
public:
    long getSumOfPrimesBelowNum(int num);
    long getAnswer();
};

class Problem011 {
public:
    long getGreatestProductOfXAdjacentNumbers(int x);
    long getAnswer();
};

class Problem012 {
public:
    int getNumberOfDivisors(int x);
    int getFirstTriangleNumberWithGreaterThanNDivisors(int n);
    int getAnswer();
};

class Problem013 {
public:
    std::string numberToString(int number);
    std::string getFirstNDigitsFromSumOfNumbers(int n, std::string nums);
    std::string getAnswer();
};

class Problem014 {
public:
    long getNextNumInSequence(long curNum);
    int getStartingNumberUnder(int max);
    long getAnswer();
};

class Problem015 {
public:
    long calculateNumRoutes(int gridSize);
    long getAnswer();
};

class Problem016 {
public:
    long sumOfDigits(BigNumber number, int power);
    long getAnswer();
};

class Problem017 {
public:
    long getNumLetters(int startNum, int endNum);
    long getAnswer();
};

class Problem018 {
public:
    int getMaxSum();
    int getAnswer();
};

class Problem019 {
public:
    int getDayOfWeek(int year, int month, int day);
    int getDaysInMonth(int month, int year);
    int getNumSundaysBetweenDates();
    int getAnswer();
};

class Problem020 {
public:
    BigNumber factorial(int n);
    long getAnswer();
};

class Problem021 {
public:
    long sumOfProperDivisors(int n);
    bool isAmicable(int a);
    long getAnswer();
};

class Problem022 {
public:
    inline int getAlphabetPos(char c) { return (c - 'a' + 1);}
    int getAnswer();
};

class Problem023 {
public:
    long sumOfProperDivisors(int n);
    bool isAbundant(long n);
    long long getAnswer();
};

class Problem024 {
public:
    std::vector<std::string> getPermutations(std::vector<int> numbers, int limit = 0);
    std::string getAnswer();
};

class Problem025 {
public:
    int getAnswer();
};

class Problem026 {
public:
    int getAnswer();
};

class Problem027 {
public:
    long getAnswer();
};

class Problem028 {
public:
    unsigned int getAnswer();
};

class Problem029 {
public:
    unsigned int getAnswer();
};

class Problem030 {
public:
    long getAnswer();
};

class Problem031 {
public:
    unsigned int denomFunc(int n, std::vector<int> &denoms);
    unsigned int getAnswer();
};

class Problem032 {
public:
    bool isPandigital(std::string n);
    long getAnswer();
};

class Problem033 {
public:
    int getAnswer();
};

class Problem034 {
public:
    int getAnswer();
};

class Problem035 {
public:
    bool isCircularPrime(int n);
    int getAnswer();
};

class Problem036 {
public:
    bool isPalindrome(std::string n);
    int getAnswer();
};

class Problem037 {
public:
    bool isTruncatable(int n);
    int getAnswer();
};

class Problem038 {
public:
    bool isPandigital(std::string n);
    int getAnswer();
};

class Problem039 {
public:
    int getAnswer();
};

class Problem040 {
public:
    int getDigitInChampernowneConstant(int n);
    int getAnswer();
};

class Problem041 {
public:
    bool isPandigital(long n);
    long getAnswer();
};

class Problem042 {
public:
    inline int getAlphabetPos(char c) { return (c - 'a' + 1);}
    int getAnswer();
};

class Problem043 {
public:
    BigNumber getAnswer();
};

class Problem044 {
public:
    bool isPentagonal(int x);
    int pentagonalNumber(int n);
    int getAnswer();
};

class Problem045 {
public:
    bool isPentagonal(int x);
    bool isTriangle(int x);
    long getAnswer();
};

class Problem046 {
public:
    int getAnswer();
};

class Problem047 {
public:
    int getDistinctPrimeFactors(int n, std::vector<long> primes);
    int getAnswer();
};

class Problem048 {
public:
    long long getAnswer();
};

class Problem049 {
public:
    std::string getAnswer();
};

class Problem050 {
public:
    int getAnswer();
};

class Problem051 {
public:
    struct NumberInfo {
    public:
        unsigned long Number;
        std::map<unsigned int, std::vector<unsigned int>> DigitPositions;
        NumberInfo(unsigned long number, std::map<unsigned int, std::vector<unsigned int>> digitPositions) {
            this->Number = number;
            this->DigitPositions = digitPositions;
        }
    };
    std::vector<long> calculate(std::vector<NumberInfo>& numbers, int familySize);
    long getAnswer();
};

class Problem052 {
public:
    int getAnswer();
};

class Problem053 {
public:
    unsigned int getAnswer();
};

class Problem054 {
public:
    int getAnswer();
};

class Problem055 {
public:
    int getAnswer();
};

class Problem056 {
public:
    long getAnswer();
};

class Problem057 {
public:
    int getAnswer();
};

#endif