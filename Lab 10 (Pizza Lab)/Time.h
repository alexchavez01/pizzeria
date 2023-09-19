//Created by Blake Ryan
/*
 * Format Information |
 *
 *         Possible formats:
 *         int - hhmm
 *         string - hh:mm
 *         string - hh:mm *M
 *
 *         Format conversions:
 *         int -> string (Assumes int is 24-hr format)
 *         100 -> 01:00 AM
 *         1300 -> 01:00 PM
 *
 *         string -> int (If AM/PM isn't included, 24-hr time is assumed)
 *         01:00 AM -> 100
 *         01:00 PM -> 1300
 *         13:00 -> 1300
 *
 */


#ifndef UNTITLED_TIME_H
#define UNTITLED_TIME_H

#include <string>
#include <iostream>
#include <math.h>

using namespace std;

class pizzaTime {
public:
    pizzaTime(int x, int y) {
        hours = x;
        minutes = y;
    }

    //Default constructor
    //Pre) None
    //Post) pizzaTime object created. Values initialized at 0
    pizzaTime();

    //String-based constructor
    //Pre) string x is received and is in one of the possible formats
    //Post) pizzaTime object created. Values initialized with data from converting x
    pizzaTime(string x);

    //string -> int converter for time
    //Pre) int x is received and is in one of the possible formats
    //Post) Time has been converted from int to string
    //int -> string (Assumes int is 24-hr format)
    //100 -> 01:00 AM
    //1300 -> 01:00 PM
    static string timeToString(int x);

    //int -> string converter for time
    //Pre) string x is received and is in one of the possible formats
    //Post) Time has been converted from string to int
    //string -> int (If AM/PM isn't included, 24-hr time is assumed)
    //01:00 AM -> 100
    //01:00 PM -> 1300
    //13:00 -> 1300
    static int stringToTime(string x);

    //Calculate y-x and return the difference in minutes
    //Pre) int x and int y are received
    //Post) y - x is returned in minutes
    static float getDifference(int x, int y);

    //Calculate x-'this' and return the difference in minutes
    //Pre) Type pizzaTime exists and pizzaTime x is received
    //Post) x - 'this' is returned in minutes
    float getDifference(pizzaTime x);

    //Access pizzaTime Data values
    //Pre) Type pizzaTime exists
    //Post) Returns 24-hr conversion of 'this''s Data values in string form
    string toString();

    //Access pizzaTime Data values
    //Pre) Type pizzaTime exists
    //Post) Returns 24-hr conversion of 'this''s Data values in int form
    int toInt();

private:
    int hours;
    int minutes;
};

#endif //UNTITLED_TIME_H
