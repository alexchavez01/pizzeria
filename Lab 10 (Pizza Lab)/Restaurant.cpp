//include statements
using namespace std;

#include "Restaurant.h"
#include "Driver.h"
#include "Order.h"
#include "Time.h"

//-----CONSTRUCTORS-----
//Default constructor.
Restaurant::Restaurant(){
    timeSum = 0;
    numOrders = 0;
}


//-----SETTERS (including associated w/ simulation actions)-----
//Called by a command function, ends simulation
//Pre:
//Post: Simulation is ended
void Restaurant::quit(){
    //not sure what to put here...?
}
//Used to update the timeSum value.
//Pre: Minutes is a positive number
//Post: Adds this many minutes to the total minutes of each order count
void Restaurant::updateTime(float minutes){
    timeSum += minutes;
}


//----------Driver-related functions--------------
//Passed a string representing a name of a driver.
//Post: If the driver did not already exist, a new Driver object has been made and put into the vector.
//If they did already exist, then they are logged in now.
void Restaurant::login(string driverName){
    Driver* driverDest = this->findDriver(driverName);
    //if the driver is already extant, log them in
    if (driverDest != nullptr){
        driverDest->logIn();
    }
    //if driver doesn't exist, we add them in
    else{
        //construct new driver
        Driver* newDriver = new Driver(driverName);
        //add them
        this->addDriver(newDriver);
    }
}
//Passed a string representing a name of a driver.
//Pre: Driver with this name exists
//Post: Finds the driver with this name and logs them out
void Restaurant::logout(string driverName){
    Driver* driverDest = this->findDriver(driverName);
    //don't do anything if this name isn't here
    if (driverDest != nullptr){
        driverDest->logOut();
    }
}
//Adds a pointer to a Driver to the vector of drivers
//Pre: No duplicate driver names are allowed.
//Post: Driver is now in the vector
void Restaurant::addDriver(Driver* d){
    //no duplicate names allowed. do nothing if a driver already has this name
        //POSSIBLE NOTE: this might be redundant because this is only called in login if we already searched for this driver's name
    if (this->findDriver(d->getName()) != nullptr){
        drivers.push_back(d);
    }
}
//Helper function:
//Returns a pointer to the driver in the restaurant's vector whose name matches the argument
//If no such name exists, returns nullptr.
Driver* Restaurant::findDriver(string name){
    Driver* result = nullptr;

    //loop thru each item of the drivers vector
    for (vector<Driver*>::iterator it = drivers.begin(); it < drivers.end(); it++){
        if ((*it)->getName() == name){
            result = *it;
            break;
        }
    }

    return result;
}


//-------------Delivery-related functions------------
//
//Parameters: The time the order was placed, and the order's info
//Post: Initializes an Order object with this info, adds it to the Oven
void Restaurant::addOrder(pizzaTime time, string info){
    //create a new order object
    order* newOrder = new order(info, time);    //for later: make sure this matches the finalized params for the order class's constructor
    oven.push_back(newOrder);
}
//Post: Pops the order at the top of Oven and queues it at the bottom of Counter
void Restaurant::serve(){
    order* thisOrder = oven.front();
    oven.pop_front();
    counter.push_back(thisOrder);
}

//Passed the current time and the name of the driver
//Pre: Driver of this name exists
//Post: Pops the top of Counter and passes it, and the time, to the driver's depart function
void Restaurant::depart(pizzaTime time, string driver){
    //get pointer to the topmost order
    order* thisOrder = counter.front();
    //pop topmost order
    counter.pop_front();
    //give that to the driver
        //getting a pointer to the driver we're calling upon
    Driver* thisDriver = this->findDriver(driver);
    thisDriver->Depart(thisOrder, &time);    //make sure this matches final params for driver. currently assuming it's (*order, time)

}


//Passed the time, the driver name, and the tip amount
//Pre: Driver exists
//Post: Calls the driver's deliver function, passing time & tip.
void Restaurant::deliver(pizzaTime time, string driver, float tip){
    //get pointer to the driver we're working with right now
    Driver* thisDriver = this->findDriver(driver);
    //call this driver's Deliver function
        //assuming the params are (Time time, float tip)
    thisDriver->Deliver(&time, tip);
    //NOTE!!!!!!!!!!!!!! right now my ADT says that the driver's deliver function calls the restaurant's updateTime function, but I actually think
        //maybe it makes more sense for the updateTime function to be called from here. less dependency I think? Discuss w/ teammates in class.
}


//Passed the time & the name of the driver
//Pre: driver exists
//Post: Calls the driver's arrive function.
void Restaurant::arrive(pizzaTime time, string driver){
    //get pointer to the driver we're working with right now
    Driver* thisDriver = this->findDriver(driver);
    //call their Arrive function
    thisDriver->Arrive(&time);
}


//-----GETTERS-----
//Returns the average amount of time each order took (from order placed to delivery at location)
float Restaurant::calculateAverage(){
    return (timeSum / numOrders);
}


//-----TERMINAL FUNCTIONS-----
//Prints the status of the restaurant into the terminal

void Restaurant::status(){
    cout << "Orders waiting to cook:\n";
    //loop through each order in Oven
    for(deque<order*>::iterator it = oven.begin(); it < oven.end(); it++){
        //doube check that begin = top of deque???
        cout << *it;    //this will only work if we overload order cout<<
    }

    cout << "Orders waiting to depart:\n";
    //loop through each order in Counter
    for(deque<order*>::iterator it = counter.begin(); it < counter.end(); it++){
        //doube check that begin = top of deque???
        cout << *it;    //this will only work if we overload order cout<<
    }

    cout << "Drivers out on delivery:\n";
    //loop through each driver, find those that're out
    for (vector<Driver*>::iterator it = drivers.begin(); it < drivers.end(); it++){
        //if currently out driving
        if ((*it)->isDeparted()){    //not 100% sure this is the right combination of *'s and ->'s but we'll see
            (*it)->printStatus();
        }
    }
}
//Prints the summary of things so far into the terminal
void Restaurant::summary(){
    //print restaurant data
    cout << "Number of orders completed: " << numOrders << endl;
    cout << "Average time per order: " << this->calculateAverage() << endl;

    //print data of All Drivers
    for (vector<Driver*>::iterator it = drivers.begin(); it < drivers.end(); it++){
        (*it)->printSummary();
    }
}
