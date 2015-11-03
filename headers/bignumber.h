//
// Created by Mark Guerra on 11/3/2015.
//

#ifndef BIGNUMBER_H
#define BIGNUMBER_H

#include <vector>
#include <string>


class BigNumber {
public:
    BigNumber();
    BigNumber(std::string number);
private:
    std::string _numberString;
    std::vector<int> _digits;
};



#endif
