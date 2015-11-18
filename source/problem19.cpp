/* Problem 19: Counting Sundays
 * By: Mark Guerra
 * 11/17/2015
 */

#include "problem19.h"


int problem19::getDayOfWeek(int year, int month, int day) {
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + t[month-1] + day) % 7;
}

int problem19::getDaysInMonth(int month, int year) {
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else if (month == 2) {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
            return 29;
        }
        return 28;
    }
    else {
        return 31;
    }
}

int problem19::getNumSundaysBetweenDates() {
    int daysInMonth = 0;
    int numSundays = 0;
    for (int i = 1901; i < 2001; i++) {
        for (int j = 1; j <= 12; j++) {
            daysInMonth = getDaysInMonth(j, i);
            for (int k = 1; k < daysInMonth; k++) {
                if (k == 1 && getDayOfWeek(i, j, k) == 0) {
                    numSundays++;
                }
            }
        }
    }
    return numSundays;
}

int problem19::getAnswer() {
    return getNumSundaysBetweenDates();
}