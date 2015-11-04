#include <iostream>

#include "problem16.h"
#include "bignumber.h"

int main(int argc, const char* argv[]) {
    //std::cout << "Answer: " << problem16::getAnswer() << std::endl;
    BigNumber b("5");
    BigNumber c("5");
    std::cout << b.multiply(c) << std::endl;
}
