//
// Created by Sofia Visa on 11/28/21.
//
#include <iostream>
#include <math.h>
#include <list>
#include "Triangle.hpp"
using namespace std;

#ifndef JURASSICMOUNTAINS_MOUNTAIN_HPP
#define JURASSICMOUNTAINS_MOUNTAIN_HPP
class Mountain{
private:
    list<Triangle*> peaks;
    //a list of POINTERS TO triangle objects
public:
    //Mountain();
    //Not even a constructor, woaaaow
        //the only thing this class HAS is a list that is allocated (to an empty list) at this class instance's birth

    void addPeak(Triangle* p);
    double getLength();
};

void Mountain::addPeak(Triangle* p){
    peaks.push_back(p);
    //adding a pointer to a triangle to the peaks list
}
double Mountain::getLength(){
    double mountain_len = 0;
    list<Triangle*>::iterator it;

    for( it = peaks.begin(); it != peaks.end(); it++) {
        //cout << *it << ' ';
        mountain_len = mountain_len + 2 * (*it)->getSideLen();
        //accumulates (2 * (sidelen of each triangle))
            //it's 2*len because len = 1 single side of a triangle, and the mountain has more than 1 side
    }
    return mountain_len;
}


#endif //JURASSICMOUNTAINS_MOUNTAIN_HPP
