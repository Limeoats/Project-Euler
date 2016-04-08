//
// Created by Mark Guerra on 11/3/2015.
//

#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#include <vector>
#include <string>
#include <iostream>

/* BigNumber class
 * Stores a very large number
 * Also contains functions and operators to perform mathematical operations on them
 */
class BigNumber {
public:
    /* Default constructor
     * Initializes member variables to default values
     *  Params: None
     *  Returns: None
     */
    BigNumber();

    /* Main constructor
     * Initializes member variables with number values
     *  Params:
     *    string number - the big number represented as a string
     *  Returns: None
     */
    BigNumber(std::string number);

    /* Add function
     * Adds another big number to the current instance
     *  Params:
     *    BigNumber other - the other big number to be added
     *  Returns:
     *    The sum of the two big numbers
     */
    BigNumber add(BigNumber other);

    /* Subtract function
     * Subracts another big number from the current instance
     *  Params:
     *    BigNumber other - the other big number to be subtracted
     *  Returns:
     *    The difference of the two big numbers
     */
    BigNumber subtract(BigNumber other);

    /* Multiply function
     * Multiplies the big number by another big number
     *  Params:
     *    BigNumber other - the other big number to multiply by
     *  Returns:
     *    The product of the two numbers
     */
    BigNumber multiply(BigNumber other);

    /* pow function
     * Raises the big number to the power of the exponent
     *  Params:
     *    BigNumber exponent - the exponent to raise the big number to
     *  Returns:
     *    The new big number after being raised to the provided exponent
     */
    BigNumber pow(int exponent);

    /* getString function
     * Turns the big number into an std::string and returns it
     *  Params: None
     *  Returns:
     *    The big number represented as an std::string
     */
    std::string getString();

    /* setString function
     * Sets the actual number string to a new string
     *  Params:
     *    std::string newStr - the new string
     *  Returns: None
     */
    void setString(std::string newStr);

    /* negate function
     * Makes the big number negative
     *  Params: None
     *  Returns: None
     */
    void negate();

    /* equals function
     * Checks if the other big number is equal to this one
     *  Params:
     *    BigNumber other - the other big number being compared
     *  Returns:
     *    True if equal, otherwise false
     */
    bool equals(BigNumber other);

    /* digits function
     * Returns the number of digits in the big number
     * Params: None
     * Returns:
     *    The number of digits in the big number
     */
    int digits();

    /*
     * Method: isNegative
     * Determines whether a big number is negative
     * Parameters: None
     * Returns:
     *   True if negative, otherwise false
     */
    bool isNegative();



    //Operator overloads

    //Output stream operator
    friend std::ostream &operator<<(std::ostream &os, const BigNumber &num);
    //Plus operator
    friend BigNumber operator+(BigNumber b1, const BigNumber &b2);
    //Minus operator
    friend BigNumber operator-(BigNumber b1, const BigNumber &b2);
    //Multiplication operator
    friend BigNumber operator*(BigNumber b1, const BigNumber &b2);

    //Exponent operator
    friend BigNumber operator^(BigNumber b1, const int &b2);
    //Equals operator
    friend bool operator==(BigNumber b1, const BigNumber &b2);
    //Greater than operator
    friend bool operator>(BigNumber b1, const BigNumber &b2);
    //Less than operator
    friend bool operator<(BigNumber b1, const BigNumber &b2);
    //Greater than or equal to operator
    friend bool operator>=(BigNumber b1, const BigNumber &b2);
    //Less than or equal to operator
    friend bool operator<=(BigNumber b1, const BigNumber &b2);

    //Assignment operator
    BigNumber& operator=(const BigNumber &other);
    BigNumber& operator+=(const BigNumber &other);
    BigNumber& operator-=(const BigNumber &other);
    BigNumber& operator*=(const BigNumber &other);


    //Index operator
    int operator[](int index);


private:
    std::string _numberString;      //The big number represented as a string
};



#endif
