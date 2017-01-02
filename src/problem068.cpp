/*
 * Problem 68: Magic 5-gon ring
 * By: Mark Guerra
 * 12/12/2016
*/

#include "main.h"

std::string Problem068::getAnswer() {
    // I solved this problem with a pen and paper, so there is no programmatic solution here.
    // Since we're looking for the highest possible number and the numbers always start from the outer nodes,
    // we need to put the highest numbers in the outer nodes (6,7,8,9,10).
    // That leaves 1,2,3,4,5 for the inner nodes. Each of the inside nodes gets touched from two
    // different paths. Adding up all of the numbers (and two for each inner node) equals 70. Since there
    // are 5 paths, 70 / 5 = 14. We'll assume that each path must equal 14.
    //
    // 10 - 3 - 1
    // 10 - 1 - 3
    //  9 - 2 - 3
    //  9 - 1 - 4
    //  9 - 3 - 2
    //  9 - 4 - 1
    //  8 - 1 - 5
    //  8 - 5 - 1
    //  8 - 2 - 4
    //  8 - 4 - 2
    //  7 - 1 - 6
    //  7 - 6 - 1
    //  7 - 2 - 5
    //  7 - 5 - 2
    //  7 - 4 - 3
    //  7 - 3 - 4
    //  6 - 5 - 3
    //  6 - 3 - 5
    //
    // 18 possible solutions.
    // I then placed the first combination I came up with, 10 - 3 - 1, at the top, and put
    // 9, 8, 7, 6 around the circle in clockwise order. Since the order begins at the lowest number, I wanted
    // 10 to come right after 6 so that it would produce the biggest number possible. I then drew in the combinations
    // so that they all fit together (I managed to do this first try). The combinations ended up being:
    //
    // 10 - 3 - 1
    //  9 - 1 - 4
    //  8 - 4 - 2
    //  7 - 2 - 5
    //  6 - 5 - 3
    //
    // Added together, each line equals 14, which is correct. Concatenating the numbers started at 6
    // and going clockwise produces the correct answer.
    return "6531031914842725";
}
