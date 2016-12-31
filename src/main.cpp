#include <iostream>
#include "utils.h"
#include "main.h"

Problem066 p;

int main(int argc, const char* argv[]) {
    auto t0 = std::chrono::high_resolution_clock::now();
    std::cout << p.getAnswer() << std::endl;
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Elapsed time: " << static_cast<std::chrono::duration<float>>(t1 - t0).count() << " seconds" << std::endl;
}
