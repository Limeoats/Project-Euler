#ifndef PROBLEM_15_H
#define PROBLEM_15_H

//Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down,
// there are exactly 6 routes to the bottom right corner.
//How many such routes are there through a 20×20 grid?

namespace problem15 {

    long choose(long n, long k) {
        if (k == 0)
            return 1;
        return (n * choose(n - 1, k - 1)) / k;
    }

    long calculateNumRoutes(int gridSize) {
        return choose(gridSize * 2, gridSize);
    }

    long getAnswer() {
        //The grid is 20x20
        //This means that there are always going to be 40 "moves" to get to the end (bottom-right corner)
        //The answer to this is out of 40, choose 20 changes in X (and 20 changes in Y)
        //The formula is 40! / (20!)^2
        return calculateNumRoutes(20);
    }
}


#endif 
