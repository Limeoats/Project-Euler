/* Counting Sundays
 * Problem 19
 * By: Mark Guerra
 * 11/17/2015
 */

#ifndef PROBLEM_19_H
#define PROBLEM_19_H

/*
 * You are given the following information, but you may prefer to do some research for yourself.
 * 1 Jan 1900 was a Monday.
 * Thirty days has September,
 * April, June and November.
 * All the rest have thirty-one,
 * Saving February alone,
 * Which has twenty-eight, rain or shine.
 * And on leap years, twenty-nine.
 * A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 * How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 */


namespace problem19 {
    int getDayOfWeek(int year, int month, int day);
    int getDaysInMonth(int month, int year);
    int getNumSundaysBetweenDates();
    int getAnswer();
}


#endif