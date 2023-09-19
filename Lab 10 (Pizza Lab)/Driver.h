//
// Created by Alex Chavez
//


#ifndef FINAL_PROJECT_DRIVER_H
#define FINAL_PROJECT_DRIVER_H

#include "Restaurant.h"
#include "Time.h"
#include "Order.h"
#include <string>
#include <iostream>



class Driver{

public:
//pre-condition: takes a string called name
//post-condition: initialize all variables and sets driver name
    Driver(std::string n);

//pre-condition: none
//post-condition: checks whether the driver is available( on standby and not departed)
    bool isAvailable();

//pre-condition: none
//post-condition: checks whether the driver is available( on standby and not departed)
    bool isDeparted();

//pre-condition: none
//post-condition: sets clocked in as true, meaning he is ready to deliver orders
    bool logIn();

//pre-condition: none
//post-condition: sets clocked in as false and determines he is logged out
    bool logOut();

//pre-condition: none
//post-condition: returns the name of driver
    std::string getName();

//pre-condition: none
//post-condition: returns the average time of delivery
    int getAvg();

//pre-condition: current order waiting to be delivered and time
//post-condition: if driver is available
// sets the driver to an order, and time it departs, and updates total driving time also sets standy by to false
    void Depart(order* o, pizzaTime* time);

//pre-condition: time the driver delievered the order and amount of tips
//post-condition: add tips to total tips, and updates total driving time, increases total deliveries
    void Deliver(pizzaTime* time, float tip);

//pre-condition: time he arrrived back at restaurant
//post-condition: sets driving time to true again, and updates total drving time
    void Arrive(pizzaTime* time);

//pre-condition: none
//post-condition: print the status of driving, isAvailable, total driving time, driver name
    void printStatus();


//pre-condition: none
//post-condition: prints summary: name, total driving time, average driving time, tips accumalted per driver
    void printSummary();

private:
    std::string name;
    float tips,
            totalDeliveries,
            drivingTime;
    bool standBy, clockedIn;
    order* currentOrder;

};

#endif //FINAL_PROJECT_DRIVER_H