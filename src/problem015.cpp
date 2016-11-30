/*
 * Problem 15: Lattice paths
 * By: Mark Guerra
 * 10/29/2015
 */


#include "main.h"
#include "utils.h"

long Problem015::calculateNumRoutes(int gridSize) {
    return utils::choose(gridSize * 2, gridSize);
}

std::string Problem015::getAnswer() {
    //The grid is 20x20
    //This means that there are always going to be 40 "moves" to get to the end (bottom-right corner)
    //The answer to this is out of 40, choose 20 changes in X (and 20 changes in Y)
    //The formula is 40! / (20!)^2
    return std::to_string(calculateNumRoutes(20));
}
