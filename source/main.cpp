#include <iostream>
#include "utils.h"

#include "problem42.h"


int main(int argc, const char* argv[]) {
    auto t0 = std::chrono::high_resolution_clock::now();
    std::cout << "Answer: " << problem42::getAnswer() << std::endl;
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Elapsed time: " << static_cast<std::chrono::duration<float>>(t1 - t0).count() << " seconds" << std::endl;
}
