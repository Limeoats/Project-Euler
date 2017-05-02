
#include <fstream>
#include "main.h"
#include "utils.h"

std::string Problem082::getAnswer() {
    std::vector<std::string> lines;
    std::string line;
    std::ifstream in("data/problem82_data.txt");
    if (in.fail()) {
        std::cerr << "Unable to open file" << std::endl;
        return "";
    }
    while (!in.eof()) {
        getline(in, line);
        lines.push_back(line);
    }
    in.close();
    std::vector<std::vector<int>> numbers(lines.size());
    for (auto i = 0; i < lines.size(); ++i) {
        auto t = utils::split(lines[i], ',');
        std::vector<int> c;
        for (auto x : t) {
            c.push_back(atoi(x.c_str()));
        }
        numbers[i] = c;
    }
    std::vector<int> tmp(numbers.size());
    for (auto i = 0; i < numbers.size(); ++i) {
        tmp[i] = numbers[i][numbers.size() - 1];
    }
    for (int i = numbers.size() - 2; i >= 0; --i) {
        //Decide if it's better to go directly right or down-right
        tmp[0] = std::min(numbers[0][i] + numbers[1][i] + tmp[1], tmp[0] + numbers[0][i]);
        for (int j = 1; j < numbers.size() - 1; ++j) {
            //Loop through the rows in column [i]
            //Check if tmp[j - 1] has its minimum value by going right or up-right (look up)
            if (tmp[j - 1] != numbers[j][i] + numbers[j - 1][i] + tmp[j]) {
                //Set tmp[j] to the min of right, up-right, or down-right
                tmp[j] = std::min(tmp[j - 1] + numbers[j][i], std::min(tmp[j] + numbers[j][i],
                                                                       numbers[j][i] + numbers[j + 1][i] + tmp[j + 1]));
            }
            else {
                //Set tmp[j] to the min of right or down-right
                tmp[j] = std::min(tmp[j] + numbers[j][i], numbers[j][i] + numbers[j + 1][i] + tmp[j + 1]);
            }
        }
        //Check if right or up-right is less
        tmp[numbers.size() - 1] = std::min(tmp[numbers.size() - 1] + numbers[numbers.size() - 1][i],
                                           tmp[numbers.size() - 1] + numbers[numbers.size() - 1][i]);
    }
    return std::to_string(*std::min_element(std::begin(tmp), std::end(tmp)));
}
