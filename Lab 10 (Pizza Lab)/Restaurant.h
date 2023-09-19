//Created by Izzie Corley 11/11/2022


using namespace std;

//class definition
#ifndef RESTAURANT_H
#define RESTAURANT_H

//include statements go here
#include <string>
#include <iostream>
#include <vector>
#include <deque>

#include "Order.h"
#include "Driver.h"
#include "Time.h"

    class Restaurant{
public:
    //-----CONSTRUCTORS-----
    //Default constructor.
    Restaurant();

    //-----SETTERS (including associated w/ simulation actions)-----
    //Called by a command function, ends simulation
    //Pre:
    //Post: Simulation is ended
    void quit();
    //Used to update the timeSum value.
    //Pre: Minutes is a positive number
    //Post: Adds this many minutes to the total minutes of each order count
    void updateTime(float minutes);

    //----------Driver-related functions--------------
    //Passed a string representing a name of a driver.
    //Post: If the driver did not already exist, a new Driver object has been made and put into the vector.
        //If they did already exist, then they are logged in now.
    void login(string driverName);
    //Passed a string representing a name of a driver.
    //Pre: Driver with this name exists
    //Post: Finds the driver with this name and logs them out
    void logout(string driverName);
    //Adds a pointer to a Driver to the vector of drivers
    //Pre: No duplicate driver names are allowed.
    //Post: Driver is now in the vector
    void addDriver(Driver* d);
    //Helper function:
    //Returns a pointer to the driver in the restaurant's vector whose name matches the argument
        //If no such name exists, returns nullptr.
    Driver* findDriver(string name);

    //-------------Delivery-related functions------------
    //
    //Parameters: The time the order was placed, and the order's info
    //Post: Initializes an Order object with this info, adds it to the Oven
    void addOrder(pizzaTime time, string info);
    //Post: Pops the order at the top of Oven and queues it at the bottom of Counter
    void serve();
    //Passed the current time and the name of the driver
    //Pre: Driver of this name exists
    //Post: Pops the top of Counter and passes it, and the time, to the driver's depart function
    void depart(pizzaTime time, string driver);
    //Passed the time, the driver name, and the tip amount
    //Pre: Driver exists
    //Post: Calls the driver's deliver function, passing time & tip.
    void deliver(pizzaTime time, string driver, float tip);
    //Passed the time & the name of the driver
    //Pre: driver exists
    //Post: Calls the driver's arrive function.
    void arrive(pizzaTime time, string driver);

    //-----GETTERS-----
    //Returns the average amount of time each order took (from order placed to delivery at location)
    float calculateAverage();


    //-----TERMINAL FUNCTIONS-----
    //Prints the status of the restaurant into the terminal
    void status();
    //Prints the summary of things so far into the terminal
    void summary();
private:
    //The sum of the total number of minutes each completed order took
    float timeSum;
    //The number of completed orders
    int numOrders;

    //A queue of Orders being cooked
    deque <order*> oven;
    //A queue of Orders ready to be delivered
    deque <order*> counter;
    //A vector of all drivers (logged in or not) associated with this restaurant
    vector <Driver*> drivers;

};

#endif