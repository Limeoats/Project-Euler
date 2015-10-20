//Utils.h
//Contains helpful functions
//By: Mark Guerra

#ifndef UTILS_H
#define UTILS_H

#include <algorithm>


namespace utils {

    template <class C, class T>
    auto contains(const C &v, const T &x) -> decltype(end(v), true) {
        return end(v) != std::find(begin(v), end(v), x);
    }

}

#endif
