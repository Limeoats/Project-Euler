#include "problem28.h"


long problem28::getAnswer() {
    const int TOTAL_SIZE = 1001 * 1001;
    int arr[1001][1001];
    int moveAmount = 1001;
    int arrayIndexX = 1000;
    int arrayIndexY = 0;
    problem28::Direction moveDirection = problem28::Direction::LEFT;
    for (int i = TOTAL_SIZE; i > 0; i--) {
        for (int j = 0; j < moveAmount; j++) {
            switch (moveDirection) {
                case Direction::LEFT:
                    arr[arrayIndexX][arrayIndexY] = i;
                    arrayIndexX--;
                    break;
                case Direction::DOWN:
                    arr[arrayIndexX][arrayIndexY] = i;
                    arrayIndexY++;
                    break;
                case Direction::RIGHT:
                    arr[arrayIndexX][arrayIndexY] = i;
                    arrayIndexX++;
                    break;
                case Direction::UP:
                    arr[arrayIndexX][arrayIndexY] = i;
                    arrayIndexY--;
                    break;
            }
            moveDirection =
                    moveDirection == Direction::LEFT ? Direction::DOWN :
                    moveDirection == Direction::DOWN ? Direction::RIGHT :
                    moveDirection == Direction::RIGHT ? Direction::UP :
                    Direction ::LEFT;

        }
        moveAmount--;
        //TODO: fix. not currently working. moveAmount is going to a very negative number and the array appears to have all 0's in it
    }

}