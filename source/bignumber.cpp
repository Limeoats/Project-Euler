//
// Created by Mark Guerra on 11/3/15.
//

#include <sstream>
#include <stack>
#include <iostream>
#include <cstdlib>

#include "bignumber.h"
#include "utils.h"


//Initializes member variables to default values
BigNumber::BigNumber() :
    _numberString("")
{
}

//Initializes member variables with number values
BigNumber::BigNumber(std::string number) :
    _numberString(number)
{
}

//Adds another big number to the current instance
BigNumber BigNumber::add(BigNumber other) {
    if (this->_numberString[0] == '-' || other._numberString[0] == '-') {
        if (this->_numberString[0] == '-' && other._numberString[0] == '-') {
            BigNumber x1, x2;
            x1 = *this;
            x2 = other;
            x1.negate();
            x2.negate();
            BigNumber res = x1.add(x2);
            res.negate();
            return res;
        }
        else if (this->_numberString[0] == '-' && other._numberString[0] != '-') {
            BigNumber x1;
            x1 = *this;
            x1.negate();
            BigNumber res = x1.subtract(other);
            res.negate();
            return res;
        }
        else {
            BigNumber x2;
            x2 = other;
            x2.negate();
            BigNumber res = x2.subtract(*this);
            res.negate();
            return res;
        }
    }
    std::string results;
    int carry = 0;
    BigNumber num1 = other > *this ? other : *this;
    BigNumber num2 = other > *this ? *this : other;
    int diff = int(num1._numberString.size() - num2._numberString.size());
    for (int i = 0; i < diff; i++) {
        num2._numberString.insert(num2._numberString.begin(), '0');
    }
    for (int i = int(num1._numberString.size() - 1); i >= 0; i--) {
        int sum = (num1._numberString[i] - '0') + (num2._numberString[i] - '0') + carry;
        carry = 0;
        if (sum <= 9 || i == 0) {
            results.insert(0, utils::toString(sum));
        }
        else {
            results.insert(0, utils::toString(sum % 10));
            carry = 1;
        }
    }
    return BigNumber(results);
}

//Subracts another big number from the current instance
BigNumber BigNumber::subtract(BigNumber other) {
    if (this->_numberString[0] == '-' || other._numberString[0] == '-') {
        if (this->_numberString[0] == '-' && other._numberString[0] == '-') {
            BigNumber x1, x2;
            x1 = *this;
            x2 = other;
            x1._numberString.erase(0, 1);
            x2._numberString.erase(0, 1);
            BigNumber res = x1.add(x2);
            res.negate();
            return res;
        }
        else if (this->_numberString[0] == '-' && other._numberString[0] != '-') {
            BigNumber x1;
            x1 = *this;
            x1.negate();
            BigNumber res = x1.add(other);
            res.negate();
            return res;
        }
        else {
            BigNumber x2;
            x2 = other;
            x2.negate();
            BigNumber res = x2.add(*this);
            return res;
        }
    }
    std::string results;
    BigNumber num1 = *this;
    BigNumber num2 = other;
    int n = 0;
    int p = 0;
    bool takeOffOne = false;
    bool shouldBeTen = false;

    if (num1 < num2) {
        //Negative answer
        BigNumber xx = num2.subtract(num1);
        xx.negate();
        return xx;
    }

    int i = int(num1._numberString.size() - 1);
    for (int j = int(num2._numberString.size() - 1); j >= 0; j--) {
        if (((num1._numberString[i] - '0') < (num2._numberString[j] - '0')) && i > 0) {
            n = char((num1._numberString[i] - '0') + 10);
            takeOffOne = true;
            if (j > 0 || num1._numberString[i - 1] != '0') {
                p = char((num1._numberString[i - 1] - '0') - 1);
                if (p == -1) {
                    p = 9;
                    shouldBeTen = true;
                }
                takeOffOne = false;
            }
            if (shouldBeTen) {
                int index = i - 1;
                for (int a = i - 1; (num1._numberString[a] - '0') == 0; a--) {
                    num1._numberString[a] = (p + '0');
                    index--;
                }
                int t = (num1._numberString[index] - '0');
                t--;
                num1._numberString[index] = (t + '0');
            }
            num1._numberString[i - 1] = (p + '0');
            shouldBeTen = false;
        }
        std::stringstream ss;
        if (((num1._numberString[i] - '0') == (num2._numberString[j] - '0'))) {
            ss << "0";
        }
        else {
            if (n <= 0) {
                ss << ((num1._numberString[i] - '0') - (num2._numberString[j] - '0'));
            }
            else {
                ss << (n - (num2._numberString[j] - '0'));
            }
        }

        results.insert(0, ss.str());
        i--;
        n = 0;
    }
    if (takeOffOne) {
        std::string number = "";
        for (int i = num1._numberString.length() - num2._numberString.length() - 1; i >= 0; i--) {
            if (num1._numberString[i] == '0') {
                number += "0";
                continue;
            }
            else {
                number.insert(number.begin(), num1._numberString[i]);
                int n = atoi(number.c_str());
                n--;
                num1._numberString.replace(0, number.size(), utils::toString(n));
                takeOffOne = false;
                break;
            }
        }
    }
    while (i >= 0) {
        std::stringstream ss;
        if (i == 0) {
            if (num1._numberString[i] - '0' != 0) {
                ss << (num1._numberString[i] - '0');
                results.insert(0, ss.str());
            }
        }
        else {
            ss << (num1._numberString[i] - '0');
            results.insert(0, ss.str());
        }

        i--;
    }

    return BigNumber(results);
}

//Multiplies the big number by another big number
BigNumber BigNumber::multiply(BigNumber other) {
    if (this->_numberString[0] == '-' || other._numberString[0] == '-') {
        if (this->_numberString[0] == '-' && other._numberString[0] == '-') {
            BigNumber x1, x2;
            x1 = *this;
            x2 = other;
            x1.negate();
            x2.negate();
            BigNumber res = x1.multiply(x2);
            return res;
        }
        else if (this->_numberString[0] == '-' && other._numberString[0] != '-') {
            BigNumber x1;
            x1 = *this;
            x1.negate();
            BigNumber res = x1.multiply(other);
            res.negate();
            return res;
        }
        else {
            BigNumber x2;
            x2 = other;
            x2.negate();
            BigNumber res = x2.multiply(*this);
            res.negate();
            return res;
        }
    }
    int carry = 0;
    int zeroCounter = 0;
    std::vector<std::string> results;
    BigNumber num1 = other > *this ? other : *this;
    BigNumber num2 = other > *this ? *this : other;
    for (int i = 0; i < num1._numberString.size() - num2._numberString.size(); i++) {
        num2._numberString.insert(num2._numberString.begin(), '0');
    }
    for (int i = (num2._numberString.size() - 1); i >= 0; i--) {
        std::string rr;
        for (int j = int(num1._numberString.size() - 1); j >= 0; j--) {
            int val = ((num2._numberString[i] - '0') * (num1._numberString[j] - '0')) + carry;
            carry = 0;
            if (val > 9 && j != 0) {
                int dig = val % 10;
                carry = val / 10;
                rr.insert(0, utils::toString(dig));
            }
            else {
                rr.insert(0, utils::toString(val));
            }
        }
        if (zeroCounter > 0) {
            for (int x = 0; x < zeroCounter; x++) {
                rr.append("0");
            }
        }
        zeroCounter++;
        results.push_back(rr);
    }
    std::vector<BigNumber> bigNumbers;
    for (int i = 0; i < results.size(); i++) {
        bigNumbers.push_back(BigNumber(results[i]));
    }
    BigNumber b("0");
    for (int i = 0; i < bigNumbers.size(); i++) {
        b = b.add(bigNumbers[i]);
    }
    b = BigNumber(utils::ltrim(b._numberString, '0'));
    return b;

}

//Raises the big number to the power of the exponent
BigNumber BigNumber::pow(int exponent) {
    BigNumber result("1");
    while (exponent > 0) {
        if (exponent & 1) {
            result = result.multiply(*this);
        }
        *this = this->multiply(*this);
        exponent /= 2;
    }
    return result;
}

//Turns the big number into an std::string and returns it
std::string BigNumber::getString() {
    return this->_numberString;
}

//Sets the actual number string equal to a new string
void BigNumber::setString(std::string newStr) {
    this->_numberString = newStr;
}

//Makes the big number negative
void BigNumber::negate() {
    if (this->_numberString[0] == '-') {
        this->_numberString.erase(0, 1);
    }
    else {
        this->_numberString.insert(this->_numberString.begin(), '-');
    }
}

//Checks if the other big number is equal to this one
bool BigNumber::equals(BigNumber other) {
    return this->_numberString == other._numberString;
}

//Returns the number of digits in the big number
int BigNumber::digits() {
    return this->_numberString.size() - this->isNegative() ? 1 : 0;
}

//Determines whether a big number is negative
bool BigNumber::isNegative() {
    return this->_numberString[0] == '-';
}

//Overload the output stream operator to print the number
std::ostream &operator<<(std::ostream &os, const BigNumber &num) {
    os << num._numberString;
    return os;
}

//Overload the plus operator to add two big numbers together
BigNumber operator+(BigNumber b1, const BigNumber &b2) {
    return b1.add(b2);
}

//Overload the minus operator to subtract two big numbers
BigNumber operator-(BigNumber b1, const BigNumber &b2) {
    return b1.subtract(b2);
}

//Overload the multiplication operator to multiply two big numbers
BigNumber operator*(BigNumber b1, const BigNumber &b2) {
    return b1.multiply(b2);
}

//Overload the exponent operator to raise a big number to an exponent
BigNumber operator^(BigNumber b1, const int &b2) {
    return b1.pow(b2);
}

//Overload the equals operator to compare two big numbers
bool operator==(BigNumber b1, const BigNumber &b2) {
    return b1.equals(b2);
}

//Overload the greater than operator to compare two big numbers
bool operator>(BigNumber b1, const BigNumber &b2) {
    if (b1._numberString[0] == '-' || b2._numberString[0] == '-') {
        if (b1._numberString[0] == '-' && b2._numberString[0] == '-') {
            BigNumber x1, x2;
            x1 = b1;
            x2 = b2;
            x1._numberString.erase(0, 1);
            x2._numberString.erase(0, 1);
            return x1 < x2;
        }
        else {
            return !(b1._numberString[0] == '-' && b2._numberString[0] != '-');
        }
    }
    if (b1 == b2) {
        return false;
    }
    if (b1._numberString.size() > b2._numberString.size()) {
        return true;
    }
    else if (b2._numberString.size() > b1._numberString.size()) {
        return false;
    }
    else {
        for (int i = 0; i < b1._numberString.size(); i++) {
            if (b1[i] == (b2._numberString[i] - '0')) {
                continue;
            }
            return b1[i] > (b2._numberString[i] - '0');
        }
    }
    return false;
}

//Overload the less than operator to compare two big numbers
bool operator<(BigNumber b1, const BigNumber &b2) {
    return !(b1 == b2) && !(b1 > b2);
}

//Overload the greater than or equal to operator to compare two big numbers
bool operator>=(BigNumber b1, const BigNumber &b2) {
    return b1 > b2 || b1 == b2;
}

//Overload the less than or equal to operator to compare two big numbers
bool operator<=(BigNumber b1, const BigNumber &b2) {
    return b1 < b2 || b1 == b2;
}

//Overload the bracket operator for indexing
int BigNumber::operator[](int index) {
    return this->_numberString[index] - '0';
}

//Assignment operator
BigNumber& BigNumber::operator=(const BigNumber &other) {
    this->_numberString = other._numberString;
    return *this;
}

BigNumber& BigNumber::operator+=(const BigNumber &other) {
    *this = *this + other;
    return *this;
}

BigNumber& BigNumber::operator-=(const BigNumber &other) {
    *this = *this - other;
    return *this;
}

BigNumber& BigNumber::operator*=(const BigNumber &other) {
    *this = *this * other;
    return *this;
}

