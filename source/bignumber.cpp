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

BigNumber::BigNumber(std::vector<int> &numbers) {
    std::stringstream ss;
    this->_numberString = "";
    for (int n : numbers) {
        ss << n;
    }
    this->_numberString = ss.str();
}

//Adds another big number to the current instance
BigNumber BigNumber::add(BigNumber other) {
    std::vector<int> results;
    int carry = 0;
    BigNumber num1 = other._numberString.size() > this->_numberString.size() ? other : *this;
    BigNumber num2 = other._numberString.size() > this->_numberString.size() ? *this : other;
    int diff = num1._numberString.size() - num2._numberString.size();
    for (int i = 0; i < diff; i++) {
        num2._numberString.insert(num2._numberString.begin(), '0');
    }
    for (int i = num1._numberString.size() - 1; i >= 0; i--) {
        int sum = (num1._numberString[i] - '0') + (num2._numberString[i] - '0') + carry;
        carry = 0;
        if (sum <= 9 || i == 0) {
            results.insert(results.begin(), sum);
        }
        else {
            results.insert(results.begin(), sum % 10);
            carry = 1;
        }
    }

    return BigNumber(results);
}

//Subracts another big number from the current instance
BigNumber BigNumber::subtract(BigNumber other) {
    std::vector<int> results;
    BigNumber num1 = other._numberString.size() > this->_numberString.size() ? other : *this;
    BigNumber num2 = other._numberString.size() > this->_numberString.size() ? *this : other;
    int diff = num1._numberString.size() - num2._numberString.size();
    for (int i = 0; i < diff; i++) {
        num2._numberString.insert(num2._numberString.begin(), '0');
    }
    int i = num1._numberString.size() - 1;
    for (int j = num2._numberString.size() - 1; j >= 0; j--) {
        if ((num1._numberString[i] - '0') < (num2._numberString[j] - '0')) {
            num1._numberString[i] = ((num1._numberString[i] - '0') + 10);
            num1._numberString[i - 1] = ((num1._numberString[i - 1] - '0') - 1);
        }
        results.insert(results.begin(), (num1._numberString[i] - '0') - (num2._numberString[j] - '0'));
        i--;
    }
    while (i >= 0 && (num1._numberString[i] - '0') != 0) {
        results.insert(results.begin(), (num1._numberString[i] - '0'));
    }
    return BigNumber(results);
}

BigNumber BigNumber::multiply(BigNumber other) {
    int carry = 0;
    int zeroCounter = 0;
    std::vector<std::vector<int>> results;
    BigNumber num1 = other._numberString.size() > this->_numberString.size() ? other : *this;
    BigNumber num2 = other._numberString.size() > this->_numberString.size() ? *this : other;
    for (int i = 0; i < num1._numberString.size() - num2._numberString.size(); i++) {
        num2._numberString.insert(num2._numberString.begin(), '0');
    }
    for (int i = num2._numberString.size() - 1; i >= 0; i--) {
        std::vector<int> rr;
        for (int j = num1._numberString.size() - 1; j >= 0; j--) {
            int val = ((num2._numberString[i] - '0') * (num1._numberString[j] - '0')) + carry;
            carry = 0;
            if (val > 9 && j != 0) {
                int dig = val % 10;
                carry = val / 10;
                rr.insert(rr.begin(), dig);
            }
            else {
                rr.insert(rr.begin(), val);
            }
        }
        if (zeroCounter > 0) {
            for (int x = 0; x < zeroCounter; x++) {
                rr.push_back(0);
            }
        }
        zeroCounter++;
        results.push_back(rr);
    }
    std::vector<BigNumber> bigNumbers;
    for (int i = 0; i < results.size(); i++) {
        std::stringstream ss;
        for (int j = 0; j < results[i].size(); j++) {
            ss << results[i][j];
        }
        bigNumbers.push_back(BigNumber(ss.str()));
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
    if (this->_numberString == other._numberString) {
        return true;
    }
    return false;
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
    if (b1._numberString.size() > b2._numberString.size()) {
        return true;
    }
    else if (b2._numberString.size() > b1._numberString.size()) {
        return false;
    }
    else {
        //TODO: finish this after implementing negative big numbers
    }
    return false;
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

