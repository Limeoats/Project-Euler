#include "problem28.h"
#include <cmath>

//n^2 + 1 - down left
//n^2 - (n-1) - down right
//n^2 + (n+1) - up left
//odd n^2 - up right

long problem28::getAnswer() {
    int total = 1;
    for (int i = 2; i < 1002; i++) {
        total += (i & 1 == 1) ? pow(i, 2) : (3 + (pow(i, 2) * 3));
    }
    return total;
}