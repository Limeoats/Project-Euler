/*
 * Problem 54: Poker hands
 * By: Mark Guerra
 * 9/7/2016
*/

#include "main.h"
#include "utils.h"

#include <map>
#include <fstream>

std::string Problem054::getAnswer() {
    enum class Suit {
        Hearts, Diamonds, Clubs, Spades, None
    };
    std::map<char, int> cardValues = {
            {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5},
            {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9},
            {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}
    };
    auto hasCard = [&](char card, std::vector<std::string> hand)->bool {
        for (unsigned int i = 0; i < hand.size(); ++i) {
            if (hand[i][0] == card) return true;
        }
        return false;
    };
    auto getSuit = [&](std::string card)->Suit {
        return card[1] == 'H' ? Suit::Hearts : card[1] == 'D' ? Suit::Diamonds :
               card[1] == 'C' ? Suit::Clubs : card[1] == 'S' ? Suit::Spades : Suit::None;
    };
    auto p1WinsTieRank = [&](std::vector<std::string> p1, std::vector<std::string> p2) {
        //At this point, ranks don't matter. Go by the highest card.
        for (int i = 4; i >= 0; --i) {
            if (cardValues[p1[i][0]] > cardValues[p2[i][0]]) {
                return true;
            }
            else if (cardValues[p1[i][0]] < cardValues[p2[i][0]]) {
                return false;
            }
        }
        return false;
    };
    auto numOfAKind = [&](std::vector<std::string> cards)->std::pair<int,int> {
        int mostCount = 0;
        int numWithMost = 0;
        std::map<char, int> m;
        for (std::vector<std::string>::iterator it = cards.begin(); it != cards.end(); ++it) {
            m[(*it)[0]]++;
            if (m[(*it)[0]] > mostCount) {
                mostCount = m[(*it)[0]];
                numWithMost = cardValues[(*it)[0]];
            }
        }
        return std::make_pair(numWithMost, mostCount);
    };
    auto numPairs = [&](std::vector<std::string> cards)->int {
        std::map<int, int> items;
        for (std::string &card: cards) {
            ++items[cardValues[card[0]]];
        }
        int np = 0;
        for (auto &p : items) {
            np += p.second == 2 ? 1 : 0;
        }
        return np;
    };
    auto highCard = [&](std::vector<std::string> cards)->int {
        int highest = 0;
        for (unsigned int i = 0; i < cards.size(); ++i) {
            highest = cardValues[cards[i][0]] > highest ? cardValues[cards[i][0]] : highest;
        }
        return highest;
    };
    auto straight = [&](std::vector<std::string> cards)->int {
        return (cardValues[cards[0][0]] + 1 == cardValues[cards[1][0]] &&
              cardValues[cards[1][0]] + 1 == cardValues[cards[2][0]] &&
              cardValues[cards[2][0]] + 1 ==  cardValues[cards[3][0]] &&
              cardValues[cards[3][0]] + 1 == cardValues[cards[4][0]]) ? cardValues[cards[4][0]] : 0;
    };
    auto flush = [&](std::vector<std::string> cards)->int {
        bool sameSuit = true;
        Suit s = getSuit(cards[0]);
        for (std::vector<std::string>::iterator it = cards.begin() + 1; it != cards.end(); ++it) {
            if (getSuit(*it) != s) {
                sameSuit = false;
                break;
            }
        }
        auto x = !sameSuit ? 0 : cardValues[cards[4][0]];
        return x;
    };
    auto fullHouse = [&](std::vector<std::string> cards)->int {
        auto v = numOfAKind(cards);
        if (v.second != 3) {
            return 0;
        }
        int numNotThreeOfAKind = 0;
        int n = -1;
        for (unsigned int i = 0; i < 5; ++i) {
            if (cardValues[cards[i][0]] != v.first) {
                if (numNotThreeOfAKind == 0 && n == -1) {
                    numNotThreeOfAKind += 1;
                    n = cardValues[cards[i][0]];
                }
                else {
                    if (n == cardValues[cards[i][0]]) {
                        return cardValues[cards[4][0]];
                    }
                    else {
                        return 0;
                    }
                }
            }
        }
        return 0;
    };
    auto royalFlush = [&](std::vector<std::string> cards)->bool {
        if (hasCard('T', cards) && hasCard('J', cards) && hasCard('Q', cards) && hasCard('K', cards) && hasCard('A', cards)) {
            return flush(cards) > 0 ? true : false;
        }
        return false;
    };
    auto p1HighestPair = [&](std::vector<std::string> p1, std::vector<std::string> p2, int numPairs)->bool {
        std::map<int, int> p1Items;
        std::map<int, int> p2Items;
        for (std::string &card: p1) {
            ++p1Items[cardValues[card[0]]];
        }
        for (std::string &card: p2) {
            ++p2Items[cardValues[card[0]]];
        }
        if (numPairs == 1) {
            int p1H = 0, p2H = 0;
            for (auto it = p1Items.begin(); it != p1Items.end(); ++it) {
                if (it->second == 2) {
                    p1H = it->first;
                    break;
                }
            }
            for (auto it = p2Items.begin(); it != p2Items.end(); ++it) {
                if (it->second == 2) {
                    p2H = it->first;
                    break;
                }
            }
            if (p1H > p2H) {
                return true;
            }
            else if (p1H < p2H) {
                return false;
            }
            else {
                return p1WinsTieRank(p1, p2);
            }
        }
        else if (numPairs == 2) {
            int p1H = 0, p2H = 0;
            for (auto it = p1Items.begin(); it != p1Items.end(); ++it) {
                if (it->second == 2 && it->first > p1H) {
                    p1H = it->first;
                }
            }
            for (auto it = p2Items.begin(); it != p2Items.end(); ++it) {
                if (it->second == 2 && it->first > p2H) {
                    p2H = it->first;
                }
            }
            if (p1H > p2H) {
                return true;
            }
            else if (p1H < p2H) {
                return false;
            }
            else {
                return p1WinsTieRank(p1, p2);
            }
        }
        return false;
    };
    auto p1HighestNumOfAKind = [&](std::vector<std::string> p1, std::vector<std::string> p2)->bool {
        auto hp1 = numOfAKind(p1);
        auto hp2 = numOfAKind(p2);
        if (hp1.first > hp2.first) {
            return true;
        }
        else if (hp1.first < hp2.first) {
            return false;
        }
        else {
            return p1WinsTieRank(p1, p2);
        }
    };
    auto handValue = [&](std::vector<std::string> cards)->int {
        if (royalFlush(cards)) {
            return 23;
        }
        else if (straight(cards) && flush(cards)) {
            return 22;
        }
        else if (numOfAKind(cards).second == 4) {
            return 21;
        }
        else if (fullHouse(cards)) {
            return 20;
        }
        else if (flush(cards)) {
            return 19;
        }
        else if (straight(cards)) {
            return 18;
        }
        else if (numOfAKind(cards).second == 3) {
            return 17;
        }
        else if (numPairs(cards) == 2) {
          return 16;
        }
        else if (numPairs(cards) == 1) {
          return 15;
        }
        else {
          return highCard(cards);
        }
    };
    auto highCardResult = [&](std::vector<std::string> p1, std::vector<std::string> p2)->bool {
        if (highCard(p1) > highCard(p2)) {
            return true;
        }
        else if (highCard(p1) < highCard(p2)) {
            return false;
        }
        else {
            return p1WinsTieRank(p1, p2);
        }
    };
    auto p1Wins = [&](std::vector<std::string> p1, std::vector<std::string> p2)->bool {
        //Sort both hands by card value
        std::sort(p1.begin(), p1.end(), [&](std::string cv1, std::string cv2) { return cardValues[cv1[0]] < cardValues[cv2[0]]; });
        std::sort(p2.begin(), p2.end(), [&](std::string cv1, std::string cv2) { return cardValues[cv1[0]] < cardValues[cv2[0]]; });
        //Start at the highest possible hand and go down from there
        int hvp1 = handValue(p1), hvp2 = handValue(p2);
        if (hvp1 == hvp2) {
            //Hand values are identical, so figure out what to do from here....
            if (hvp1 == 22) {
                //Straight flush tie
                return highCardResult(p1, p2);
            }
            else if (hvp1 == 21) {
                //Four of a kind tie
                return p1HighestNumOfAKind(p1, p2);
            }
            else if (hvp1 == 20) {
                //Full house tie
                return highCardResult(p1, p2);
            }
            else if (hvp1 == 19) {
                //Flush tie
                return highCardResult(p1, p2);
            }
            else if (hvp1 == 18) {
                //Straight tie
                return highCardResult(p1, p2);
            }
            else if (hvp1 == 17) {
                //Three of a kind tie
                return p1HighestNumOfAKind(p1, p2);
            }
            else if (hvp1 == 16) {
                //Two pair tie
                return p1HighestPair(p1, p2, 2);
            }
            else if (hvp1 == 15) {
                //One pair tie
                return p1HighestPair(p1, p2, 1);
            }
            else if (hvp1 == 0) {
                return highCardResult(p1, p2);
            }
        }
        else {
            return hvp1 > hvp2;
        }
    };
    std::ifstream in("data/problem54_data.txt");
    std::stringstream ss;
    ss << in.rdbuf();
    std::vector<std::string> rounds = utils::split(ss.str(), '\n');
    int wins = 0;
    std::vector<std::string> p1, p2;
    for (std::vector<std::string>::iterator it = rounds.begin(); it != rounds.end(); ++it) {
        std::vector<std::string> roundHands = utils::split(*it, ' ');
        for (int i = 0; i < 5; ++i) {
            p1.push_back(roundHands[i]);
        }
        for (int i = 5; i < 10; ++i) {
            p2.push_back(roundHands[i]);
        }
        wins += p1Wins(p1, p2);
        p1.clear(), p2.clear();
    }
    return std::to_string(wins);
}