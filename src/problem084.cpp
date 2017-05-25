/*
 * Problem 84: Monopoly odds
 * By: Mark Guerra
 * 5/25/2017
*/

#include "main.h"

std::map<int, float> Problem084::getDiceResultPercentages(const int diceSides) {
    std::map<int, float> r;
    std::map<int, int> counts;
    for (int i = 1; i <= diceSides; ++i) {
        for (int j = 1; j <= diceSides; ++j) {
            ++counts[i + j];
        }
    }
    for (auto &i : counts) {
        r[i.first] = (i.second / (float)(diceSides * diceSides)) * 100;
    }
    return r;
}

std::string Problem084::getAnswer() {
    const int DICE_SIDES = 6;
    std::map<int, float> diceResultPercentages = getDiceResultPercentages(DICE_SIDES);
    
}
