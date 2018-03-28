#ifndef PROJECT_EULER_MAIN_H
#define PROJECT_EULER_MAIN_H

#include <vector>
#include <map>

#include "bignumber.h"

class IAnswer {
public:
    virtual std::string get_answer() = 0;
};

class Problem001 : public IAnswer {
public:
    std::string get_answer();
};

class Problem002 : public IAnswer {
public:
    bool isOdd(int i);
    std::vector<int> getFibNumbers(int max);
    std::string get_answer();
};

class Problem003 : public IAnswer {
public:
    long getGreatestPrimeFactor(long long num);
    std::string get_answer();
};

class Problem004 : public IAnswer {
public:
    bool isPalindrome(int num);
    int getLargestPalindrome();
    std::string get_answer();
};

class Problem005 : public IAnswer {
public:
    int getSmallestNumberDividedByRange(int begin, int end);
    std::string get_answer();
};

class Problem006 : public IAnswer {
public:
    int solveProblem(int numNaturalNumbers);
    std::string get_answer();
};

class Problem007 : public IAnswer {
public:
    int getNthPrimeNumber(int n);
    std::string get_answer();
};

class Problem008 : public IAnswer {
public:
    long getGreatestProduct(int howMany);
    std::string get_answer();
};

class Problem009 : public IAnswer {
public:
    double getProductOfPythagoreanTriplet(int sumOfABC);
    std::string get_answer();
};

class Problem010 : public IAnswer {
public:
    long getSumOfPrimesBelowNum(int num);
    std::string get_answer();
};

class Problem011 : public IAnswer {
public:
    long getGreatestProductOfXAdjacentNumbers(int x);
    std::string get_answer();
};

class Problem012 : public IAnswer {
public:
    int getNumberOfDivisors(int x);
    int getFirstTriangleNumberWithGreaterThanNDivisors(int n);
    std::string get_answer();
};

class Problem013 : public IAnswer {
public:
    std::string numberToString(int number);
    std::string getFirstNDigitsFromSumOfNumbers(int n, std::string nums);
    std::string get_answer();
};

class Problem014 : public IAnswer {
public:
    long getNextNumInSequence(long curNum);
    int getStartingNumberUnder(int max);
    std::string get_answer();
};

class Problem015 : public IAnswer {
public:
    long calculateNumRoutes(int gridSize);
    std::string get_answer();
};

class Problem016 : public IAnswer {
public:
    long sumOfDigits(BigNumber number, int power);
    std::string get_answer();
};

class Problem017 : public IAnswer {
public:
    long getNumLetters(int startNum, int endNum);
    std::string get_answer();
};

class Problem018 : public IAnswer {
public:
    int getMaxSum();
    std::string get_answer();
};

class Problem019 : public IAnswer {
public:
    int getDayOfWeek(int year, int month, int day);
    int getDaysInMonth(int month, int year);
    int getNumSundaysBetweenDates();
    std::string get_answer();
};

class Problem020 : public IAnswer {
public:
    BigNumber factorial(int n);
    std::string get_answer();
};

class Problem021 : public IAnswer {
public:
    long sumOfProperDivisors(int n);
    bool isAmicable(int a);
    std::string get_answer();
};

class Problem022 : public IAnswer {
public:
    inline int getAlphabetPos(char c) { return (c - 'a' + 1);}
    std::string get_answer();
};

class Problem023 : public IAnswer {
public:
    long sumOfProperDivisors(int n);
    bool isAbundant(long n);
    std::string get_answer();
};

class Problem024 : public IAnswer {
public:
    std::vector<std::string> getPermutations(std::vector<int> numbers, int limit = 0);
    std::string get_answer();
};

class Problem025 : public IAnswer {
public:
    std::string get_answer();
};

class Problem026 : public IAnswer {
public:
    std::string get_answer();
};

class Problem027 : public IAnswer {
public:
    std::string get_answer();
};

class Problem028 : public IAnswer {
public:
    std::string get_answer();
};

class Problem029 : public IAnswer {
public:
    std::string get_answer();
};

class Problem030 : public IAnswer {
public:
    std::string get_answer();
};

class Problem031 : public IAnswer {
public:
    unsigned int denomFunc(int n, std::vector<int> &denoms);
    std::string get_answer();
};

class Problem032 : public IAnswer {
public:
    bool isPandigital(std::string n);
    std::string get_answer();
};

class Problem033 : public IAnswer {
public:
    std::string get_answer();
};

class Problem034 : public IAnswer {
public:
    std::string get_answer();
};

class Problem035 : public IAnswer {
public:
    bool isCircularPrime(int n);
    std::string get_answer();
};

class Problem036 : public IAnswer {
public:
    bool isPalindrome(std::string n);
    std::string get_answer();
};

class Problem037 : public IAnswer {
public:
    bool isTruncatable(int n);
    std::string get_answer();
};

class Problem038 : public IAnswer {
public:
    bool isPandigital(std::string n);
    std::string get_answer();
};

class Problem039 : public IAnswer {
public:
    std::string get_answer();
};

class Problem040 : public IAnswer {
public:
    int getDigitInChampernowneConstant(int n);
    std::string get_answer();
};

class Problem041 : public IAnswer {
public:
    bool isPandigital(long n);
    std::string get_answer();
};

class Problem042 : public IAnswer {
public:
    inline int getAlphabetPos(char c) { return (c - 'a' + 1);}
    std::string get_answer();
};

class Problem043 : public IAnswer {
public:
    std::string get_answer();
};

class Problem044 : public IAnswer {
public:
    bool isPentagonal(int x);
    int pentagonalNumber(int n);
    std::string get_answer();
};

class Problem045 : public IAnswer {
public:
    bool isPentagonal(int x);
    bool isTriangle(int x);
    std::string get_answer();
};

class Problem046 : public IAnswer {
public:
    std::string get_answer();
};

class Problem047 : public IAnswer {
public:
    int getDistinctPrimeFactors(int n, std::vector<long> primes);
    std::string get_answer();
};

class Problem048 : public IAnswer {
public:
    std::string get_answer();
};

class Problem049 : public IAnswer {
public:
    std::string get_answer();
};

class Problem050 : public IAnswer {
public:
    std::string get_answer();
};

class Problem051 : public IAnswer {
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
    std::string get_answer();
};

class Problem052 : public IAnswer {
public:
    std::string get_answer();
};

class Problem053 : public IAnswer {
public:
    std::string get_answer();
};

class Problem054 : public IAnswer {
public:
    std::string get_answer();
};

class Problem055 : public IAnswer {
public:
    std::string get_answer();
};

class Problem056 : public IAnswer {
public:
    std::string get_answer();
};

class Problem057 : public IAnswer {
public:
    std::string get_answer();
};

class Problem058 : public IAnswer {
public:
    std::string get_answer();
};

class Problem059 : public IAnswer {
public:
    std::string get_answer();
};

class Problem060 : public IAnswer {
public:
    std::string get_answer();
};

class Problem061 : public IAnswer {
public:
    std::string get_answer();
private:
    bool isNgonal(unsigned int n, unsigned int &x) const;
    bool isCyclic(int x, int y) const;
};

class Problem062 : public IAnswer {
public:
    std::string get_answer();
};

class Problem063 : public IAnswer {
public:
    std::string get_answer();
};

class Problem064 : public IAnswer {
public:
    std::string get_answer();
};

class Problem065 : public IAnswer {
public:
    std::string get_answer();
};

class Problem066 : public IAnswer {
public:
    std::string get_answer();
private:
    bool pellsEquation(BigNumber x, BigNumber y, int d);
};

class Problem067 : public IAnswer {
public:
    std::string get_answer();
};

class Problem068 : public IAnswer {
public:
    std::string get_answer();
};

class Problem069 : public IAnswer {
public:
    std::string get_answer();
};

class Problem070 : public IAnswer {
public:
    std::string get_answer();
};

class Problem071 : public IAnswer {
public:
    std::string get_answer();
};

class Problem072 : public IAnswer {
public:
    std::string get_answer();
};

class Problem073 : public IAnswer {
public:
    std::string get_answer();
};

class Problem074 : public IAnswer {
public:
    Problem074();
    std::string get_answer();
private:
    int digitFactorialSum(int num);
    int _digitFactorials[10];
};

class Problem075 : public IAnswer {
public:
    std::string get_answer();
};

class Problem076 : public IAnswer {
public:
    Problem076();
    std::string get_answer();
private:
    int partition(int n, int nm);
    int _vals[101][101];
};

class Problem077 : public IAnswer {
public:
    std::string get_answer();
};

class Problem078 : public IAnswer {
public:
    std::string get_answer();
private:
    int getGeneralizedPentagonal(int n);
};

class Problem079 : public IAnswer {
public:
    std::string get_answer();
};

class Problem080 : public IAnswer {
public:
    std::string get_answer();
private:
    BigNumber sqrtDigits(int n, int precision);
};

class Problem081 : public IAnswer {
public:
    std::string get_answer();
};

class Problem082 : public IAnswer {
public:
    std::string get_answer();
private:
    std::vector<std::vector<int>> _original;
    std::vector<std::vector<int>> _tmp;
    int minPath(int y, int x);
};

class Problem083 : public IAnswer {
public:
    std::string get_answer();
private:
    std::vector<std::vector<int>> _original;
    
    int dijkstra();
};

class Problem084 : public IAnswer {
public:
    std::string get_answer();
private:
    void chance(std::vector<int> &cards, int &location);
    void community_chest(std::vector<int> &cards, int &location);
};

class Problem085 : public IAnswer {
public:
    std::string get_answer();
};

class Problem086 : public IAnswer {
public:
    std::string get_answer();
};

class Problem087 : public IAnswer {
public:
    std::string get_answer();
};

class Problem088 : public IAnswer {
public:
    std::string get_answer();
private:

};


#endif
