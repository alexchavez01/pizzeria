//
// Created by Alex Chavez.
//

#include "Restaurant.h"
#include "Driver.h"

#include <utility>
#include "Time.h"
#include "Order.h"

Driver::Driver(std::string n) {
    name = n;
    tips = 0.0;
    totalDeliveries = 0.0;
    drivingTime = 0.0;
    currentOrder = nullptr;
    clockedIn = true;
    standBy = true;
}

void Driver::Deliver(pizzaTime* time, float tip) {
    //removes order

    tips += tip;  // add tips;
    drivingTime += time->getDifference(*time);
    totalDeliveries++; //updates deliveries completed
}

void Driver::Depart(order* o, pizzaTime* time) {
//update current Order
    if(isAvailable()){
        standBy = false;
        currentOrder = o;
        drivingTime += time->getDifference(*time);
    } else cout << "Driver not available";

}

void Driver::Arrive(pizzaTime* time) {
    //set standby meaning at restaurant---
    standBy = true;
    //updates driving time----
    drivingTime += time->getDifference(*time);

}

bool Driver::isAvailable() {

    return (clockedIn && standBy) ;
}

bool Driver::isDeparted() {
    return (clockedIn && !standBy);
}

bool Driver::logIn() {
    return clockedIn = true;
}

bool Driver::logOut() {
    return clockedIn = false;
}

std::string Driver::getName() {
    return name;
}

int Driver::getAvg() {
    float avg = drivingTime/totalDeliveries;
    return avg;
}

void Driver::printStatus() {
    std::cout << name << ": ";
}

void Driver::printSummary() {
    std::cout
              <<"Driver " << name << ":\n"
              << "Number of Deliveries: " << totalDeliveries
              <<"\nAverage time per delivery: " << getAvg()
              <<"Total Tips: " << tips << std::endl;
}






