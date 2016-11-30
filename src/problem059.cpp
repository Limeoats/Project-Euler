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
 * We know that the "password" is made up of three lowercase letters,
 * meaning that the ASCII codes for them must be between 97 and
 * 122 inclusive. Three loops are created with those ranges so that each
 * combination can be tested for the password. With each combination [a], [b], [c],
 * loop through each ASCII code in [chars] and XOR it with [a], [b], or [c], depending
 * on which a step [d]. If any of those XOR operations results in an ASCII code outside of the
 * range 32 => 122 inclusive, then the resulting character would not be a part of the English
 * language, which goes against the requirements. If this is the case, break out of the for loop and
 * continue around the [a] [b] [c] loops. If all of the characters in [chars] pass the English
 * language test, then we found a potential password candidate. Loop through each character in [chars]
 * again and XOR it by the [a], [b], and [c] that might make up the correct password. Push these values into
 * a new vector [result]. Next, we need to determine if the generated string of characters creates
 * English sentences. The most common English word is "the" according to Wikipedia, so we loop through
 * [result] and look for an occurance of the characters 't', 'h', and 'e' in a row. If that is found, we assume
 * we found the correct password. Finally, loop through each character in [result] and add its ASCII value
 * to [sum]. Return the result and print it.
 */

std::string Problem059::getAnswer() {
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
                    } else if (d == 2) {
                        if ((std::stoi(ch) ^ b) < 32 || (std::stoi(ch) ^ b) > 122) {
                            success = false;
                            break;
                        }
                    } else if (d == 3) {
                        if ((std::stoi(ch) ^ c) < 32 || (std::stoi(ch) ^ c) > 122) {
                            success = false;
                            break;
                        } else {
                            d = 1;
                            continue;
                        }
                    }
                    ++d;
                }
                if (success) {
                    std::vector<char> result;
                    int d = 0;
                    for (int i = 0; i < chars.size(); ++i) {
                        ++d;
                        if (d == 1) {
                            result.push_back(utils::asciiToChar((std::stoi(chars[i]) ^ a)));
                        } else if (d == 2) {
                            result.push_back(utils::asciiToChar((std::stoi(chars[i]) ^ b)));
                        } else if (d == 3) {
                            result.push_back(utils::asciiToChar((std::stoi(chars[i]) ^ c)));
                            d = 0;
                        }
                    }
                    bool correct = false;
                    for (int i = 0; i < chars.size(); ++i) {
                        if (result[i] == 't' && result[i + 1] == 'h' && result[i + 2] == 'e') {
                            correct = true;
                        }
                    }
                    if (correct) {
                        int sum = 0;
                        for (int i = 0; i < result.size(); ++i) {
                            sum += utils::charToAscii(result[i]);
                        }
                        return std::to_string(sum);
                    }
                    result.clear();
                } else {
                    success = true;
                }
            }
        }
    }
    return 0;
}