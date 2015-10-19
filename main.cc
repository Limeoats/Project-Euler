#include <iostream>
#include <vector>

#include "problem1.h"

int main(int argc, const char* argv[]) {
    std::vector<int> x = {3, 5};
    std::cout << "Answer: " << getMultiplesUnder(1000, x) << std::endl;
}
