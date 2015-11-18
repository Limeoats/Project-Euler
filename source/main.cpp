#include <iostream>
#include "utils.h"

#include "problem16.h"

#include "bignumber.h"



int main(int argc, const char* argv[]) {
    auto t0 = std::chrono::high_resolution_clock::now();
    std::cout << "Answer: " << problem16::getAnswer() << std::endl;
//    BigNumber c("5020");
//    BigNumber d("5020");
//    if (c == d)
//        std::cout << "yes" << std::endl;
//    else
//        std::cout << "no" <<  std::endl;
//    BigNumber a("20305");
//    BigNumber b("200");
//    std::cout << a.subtract(b) << std::endl;
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Elapsed time: " << static_cast<std::chrono::duration<float>>(t1 - t0).count() << " seconds" << std::endl;
}
