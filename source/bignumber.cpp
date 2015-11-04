//
// Created by Mark Guerra on 11/3/15.
//

#include <sstream>
#include <stack>
#include <iostream>

#include "bignumber.h"


//Initializes member variables to default values
BigNumber::BigNumber() :
    _numberString("")
{
}

//Initializes member variables with number values
BigNumber::BigNumber(std::string number) :
    _numberString(number)
{
    bool nextNegative = false;
    for (char c : number) {
        if (c == '-')
            nextNegative = true;
        else {
            this->_digits.push_back(nextNegative == true ? (c - '0') * -1 : (c - '0'));
            nextNegative = false;
        }
    }
}

//Adds another big number to the current instance
BigNumber BigNumber::add(BigNumber other) {
    int result = 0;
    char chars[1], val;
    std::stack<char> s1, s2, sr;

    for (char c : this->getString()) {
        s1.push(c);
    }
    for (char c : other.getString()) {
        s2.push(c);
    }
    int unitNum, carry = 0;

    while (!s1.empty() || !s2.empty()) {
        if (!s1.empty()) {
            chars[0] = s1.top();
            s1.pop();
            result += atoi(chars);
        }
        if (!s2.empty()) {
            chars[0] = s2.top();
            s2.pop();
            result += atoi(chars);
        }
        if (result > 9) {
            //There is a carry
            unitNum = result - 10;
            std::stringstream ss;
            ss << unitNum;
            val = ss.str()[0];
            sr.push(val);
            carry = int(result * .1); //Change unitNum to a decimal, and cast it to an int to get the carry
            result = carry;
            if (!s1.empty() || !s2.empty()) {
                carry = 0;
            }
        }
        else {
            //There is no carry in this pass
            std::stringstream ss;
            ss << result;
            val = ss.str()[0];
            sr.push(val);
            result = 0;
        }
    }
    if (carry != 0) {
        //After the while loop ended, the carry variable has a number
        std::stringstream ss;
        ss << carry;
        val = ss.str()[0];
        sr.push(val);
    }
    std::stringstream ss;
    while (!sr.empty()) {
        ss << sr.top();
        sr.pop();
    }
    BigNumber b(ss.str());
    return b;
}

//Subracts another big number from the current instance
BigNumber BigNumber::subtract(BigNumber other) {
    int result = 0;
    char chars[1], val;
    std::stack<char> s1, s2, sr;
    int amountToTake = 0;

    for (char c : this->getString()) {
        s1.push(c);
    }
    for (char c : other.getString()) {
        s2.push(c);
    }
    if (this->getString().size() < other.getString().size()) {
        std::cerr << "Negative big numbers are not currently supported." << std::endl;
    }
    else {
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) {
                chars[0] = s1.top();
                s1.pop();
                result = atoi(chars);
                if (amountToTake > 0) {
                    if (result == 0) {
                        result = 9;
                    }
                    else {
                        result -= 1;
                        amountToTake--;
                    }
                }
            }
            if (!s2.empty()) {
                chars[0] = s2.top();
                s2.pop();
                if (result - atoi(chars) < 0 && s1.size() > 0) {
                    result += 10;
                    result -= atoi(chars);
                    amountToTake++;
                }
                else {
                    result -= atoi(chars);
                }

            }
            std::stringstream ss;
            ss << result;
            if (ss.str()[0] == '-') {
                sr.push(ss.str()[1]);
            }
            val = ss.str()[0];
            sr.push(val);
            result = 0;
        }
        std::stringstream ss;
        while (!sr.empty()) {
            ss << sr.top();
            sr.pop();
        }
        BigNumber b(ss.str());
        return b;
    }
}

BigNumber BigNumber::multiply(BigNumber other) {
    int carry = 0;
    std::vector<std::vector<int>> results;
    BigNumber num1 = other._digits.size() > this->_digits.size() ? other : *this;
    BigNumber num2 = other._digits.size() > this->_digits.size() ? *this : other;
    for (int i = 0; i < num1._digits.size() - other._digits.size(); i++) {
        num2._digits.insert(num2._digits.begin(), 0);
    }
    for (int i = num2._digits.size() - 1; i >= 0; i--) {
        std::vector<int> rr;
        for (int j = num1._digits.size() - 1; j >= 0; j--) {
            int val = num2._digits[i] * (num1._digits[j] + carry);
            carry = 0;
            if (val > 9) {
                int dig = val % 10;
                carry = val / 10;
                rr.push_back(dig);
            }
            else {
                rr.push_back(val);
            }
        }
        if (i < num2._digits.size()) {
            for (int x = 0; x < num2._digits.size() - i; i++) {
                rr.push_back(0);
            }
        }
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
        b = b + bigNumbers[i];
    }
    return b;

}

//Raises the big number to the power of the exponent
BigNumber BigNumber::pow(long exponent) {

}

std::string BigNumber::getString() {
    std::stringstream ss;
    for (int x : this->_digits) {
        ss << x;
    }
    return ss.str();
}

//Makes the big number negative
void BigNumber::negate() {
    this->_digits[0] *= -1;
}

//Overload the output stream operator to print the number
std::ostream &operator<<(std::ostream &os, const BigNumber &num) {
    for (int x : num._digits) {
        os << x;
    }
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


