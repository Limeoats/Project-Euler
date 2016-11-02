/*
 * Problem 59: XOR Decryption
 * By: Mark Guerra
 * 11/2/2016
*/

#include <fstream>
#include <sstream>

#include "main.h"
#include "utils.h"

/*
 *
 */

int Problem059::getAnswer() {
    std::ifstream in("data/problem59_data.txt");
    std::stringstream ss;
    ss << in.rdbuf();
    std::vector<std::string> chars = utils::split(ss.str(), ',');

    bool success = true;
    for (int a = 97; a <= 122; ++a) {
        for (int b = 97; b <= 122; ++b) {
            for (int c = 97; c <= 122; ++c) {
                int d = 1;
                for (std::string ch : chars) {
                    if (d == 1) {
                        if ((std::stoi(ch) ^ a) < 32 || (std::stoi(ch) ^ a) > 122) {
                            success = false;
                            break;
                        }
                    }
                    else if (d == 2) {
                        if ((std::stoi(ch) ^ b) < 32 || (std::stoi(ch) ^ b) > 122) {
                            success = false;
                            break;
                        }
                    }
                    else if (d == 3) {
                        if ((std::stoi(ch) ^ c) < 32 || (std::stoi(ch) ^ c) > 122)  {
                            success = false;
                            break;
                        }
                        else {
                            d = 1;
                            continue;
                        }
                    }
                    ++d;
                }
                if (success) {
                    std::cout << utils::asciiToChar(a) << utils::asciiToChar(b) << utils::asciiToChar(c) << std::endl;
                }
                else {
                    success = true;
                }
            }
        }
    }

    return 0;
}