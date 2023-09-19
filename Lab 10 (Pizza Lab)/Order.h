//Created by Blake Ryan


#ifndef UNTITLED_ORDER_H
#define UNTITLED_ORDER_H

//include statements
#include <string>
#include <iostream>
#include <math.h>
#include "Time.h"

using namespace std;

class order {
public:

    //Default constructor
    //Pre) string x and int y are received
    //Post) order object created. Values initialized with data from x and y
    order();

    //Value-based constructor
    //Pre) string x and int y are received
    //Post) order object created. Values initialized with data from x and y
    order(string x, int y);

    //pizzaTime constructor
    //Pre) string x and PizzaTime y are received
    //Post) order object created. Values initialized with data from x and y
    order(string x, pizzaTime y);

    //Prototype operator overload
    friend ostream& operator<<(ostream& os, const order& ordr);
private:
    string contents;
    int time;
};


#endif //UNTITLED_ORDER_H