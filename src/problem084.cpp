/*
 * Problem 84: Monopoly odds
 * By: Mark Guerra
 * 5/25/2017
*/

#include <ctime>
#include <numeric>
#include <algorithm>
#include "main.h"

/*
 * I decided to simulate 5,000,000 turns of Monopoly to solve this problem.
 * Two dice are rolled, the [location] is moved accordingly, and if
 * community chest or chance are landed on, the shuffled cards
 * are looked at and a new location is determined. All jail logic
 * is also implemented. The final location each turn is stored
 * in a map [counts]. When the simulation is over, I check for the
 * three highest values in [counts], pull out the key, and
 * append it to a string. The string is then returned and printed.
 */

void Problem084::chance(std::vector<int> &cards, int &location) {
    if (cards[0] == 1) location = 0;
    else if (cards[0] == 2) location = 10;
    else if (cards[0] == 3) location = 11;
    else if (cards[0] == 4) location = 24;
    else if (cards[0] == 5) location = 39;
    else if (cards[0] == 6) location = 5;
    else if (cards[0] == 7 || cards[0] == 8) location = (location < 5 || location > 35 ? 5 : location < 15 ? 15 : location < 25 ? 25 : 35);
    else if (cards[0] == 9) location = location < 12 || location > 28 ? 12 : 28;
    else if (cards[0] == 10) location -= 3;
    std::rotate(std::begin(cards), std::begin(cards) + 1, std::end(cards));
}

void Problem084::community_chest(std::vector<int> &cards, int &location) {
    if (cards[0] == 1) location = 0;
    else if (cards[0] == 2) location = 10;
    std::rotate(std::begin(cards), std::begin(cards) + 1, std::end(cards));
}

std::string Problem084::getAnswer() {
    srand(static_cast<unsigned int>(time(nullptr)));
    const int DICE_SIDES = 4;
    
    std::map<int, int> counts;
    int location = 0;
    int doubles_count = 0;
    std::vector<int> chance_cards = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    std::vector<int> community_chest_cards = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    
    std::random_shuffle(chance_cards.begin(), chance_cards.end());
    std::random_shuffle(community_chest_cards.begin(), community_chest_cards.end());
    
    for (int turns = 0; turns < 5000000; ++turns) {
        int r1 = rand() % DICE_SIDES + 1;
        int r2 = rand() % DICE_SIDES + 1;
        if (r1 == r2) ++doubles_count;
        else doubles_count = 0;
        bool just_jailed = false;
        if (doubles_count == 3) {
            location = 10;
            doubles_count = 0;
            just_jailed = true;
        }
        if (!just_jailed) {
            int sum = r1 + r2;
            for (; sum > 0; --sum) {
                ++location;
                if (location == 40) location = 0;
            }
        }
        if (location == 2 || location == 17 || location == 33) community_chest(community_chest_cards, location);
        else if (location == 7 || location == 22 || location == 36) chance(chance_cards, location);
        else if (location == 30) location = 10;
        counts[location]++;
    }
    std::string result = "";
    for (int i = 0; i < 3; ++i) {
        auto pr = std::max_element(counts.begin(), counts.end(), [](auto &p1, auto &p2) {
            return p1.second < p2.second;
        });
        result += (pr->first < 10 ? "0" : "") + std::to_string(pr->first);
        counts.erase(pr);
    }
    return result;
}
