/*
 * Problem 79: Passcode derivation
 * By: Mark Guerra
 * 3/30/2017
*/

#include <fstream>
#include "main.h"
#include "utils.h"

/*
 * We start by reading each [line] into an array [lines] from the text file. Then, iterate over each
 * [line] in [lines] and check if a dictionary [x] contains the value yet. If not, add it. The dictionary
 * [x] will contain all numbers that come after the key. Once this is finished, we build our first draft
 * of the passcode by simply looping through each key in [x] and prepending it to the string. We then
 * convert that first draft to an array for easy swapping later on. Next, loop through each value starting at the
 * end of the array. We then create a nested loop that goes through every value before the current value in
 * the array. If the original [x] dictionary's values (that come after the key) contain the value before
 * the key in [answer], they need to be swapped. Swap them and then keep going the rest of the way through
 * [answer]. Once this pass is over, increase [i] if anything was changed so that it will do another pass
 * for that index. Once these loops are finished, [answer] is in the correct order so convert it back
 * into a string and return it.
*/

std::string Problem079::get_answer() {
    std::vector<std::string> lines;
    std::string line;
    std::ifstream in("data/problem79_data.txt");
    if (in.fail()) {
        std::cerr << "Unable to open file" << std::endl;
        return "";
    }
    while (!in.eof()) {
        getline(in, line);
        lines.push_back(line);
    }
    in.close();
    utils::removeDuplicates(lines);
    std::map<char, std::vector<char>> x;
    for (auto l : lines) {
        char c1 = l[0], c2 = l[1], c3 = l[2];
        if (x.count(c1) <= 0)
            x[c1] = std::vector<char>();
        if (x.count(c2) <= 0)
            x[c2] = std::vector<char>();
        if (x.count(c3) <= 0)
            x[c3] = std::vector<char>();
        if (!utils::contains(x[c1], c2))
            x[c1].push_back(c2);
        if (!utils::contains(x[c2], c3))
            x[c2].push_back(c3);
    }
    std::string result = "";
    for (auto number : x) {
        result.insert(0, std::string(1, number.first));
    }
    for (auto i = result.size() - 1; i > 0; --i) {
        bool changed = false;
        for (auto j = i; j > 0; --j) {
            if (!utils::contains(x[result[i]], result[j - 1])) continue;
            std::swap(result[j], result[j - 1]);
            changed = true;
        }
        i += changed;
    }
    return result;
}