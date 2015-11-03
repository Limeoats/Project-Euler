//Utils.h
//Contains helpful functions
//By: Mark Guerra

#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>


namespace utils {

    //bool contains(const C &v, const T &x)
    //Parameters:
    //  v: a container of some sort
    //  x: the value being checked
    //Returns:
    //  true if the container v contains x, otherwise false
    template <class C, class T>
    bool contains(const C &v, const T &x) {
        return std::end(v) != std::find(std::begin(v), std::end(v), x);
    }


    //bool isPrime(int num)
    //Parameters:
    //  num: the number being checked
    //Returns:
    //  true if num is prime, otherwise false
    bool isPrime(int num) {
        if ((num & 1) == 0)
            return num == 2;
        int root = sqrt(num);
        for (int i = 3; i <= root; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    //vector<string> split(string str, char c)
    //Parameters:
    //  str: the string being split
    //  c: the delimiting character
    //Returns:
    //  a vector containing each of the split strings
    std::vector<std::string> split(std::string str, char c) {
        std::vector<std::string> list;
        std::stringstream ss(str);
        std::string item;
        while (std::getline(ss, item, c)) {
            list.push_back(item);
        }
        return list;
    }

}

#endif
