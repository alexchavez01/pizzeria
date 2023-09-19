#include <iostream>
#include "Mountain.hpp"

void jurassic() {
    cout << "This program creates two mountains having some "
            "peaks of same size. Then due to a volcano, one peak"
            "gets taller and that is reflected in both mountains" << endl;

    Triangle t1(1000), t2(2500), t3(3200), t4(4000);
    Triangle *t5 = new Triangle(5500);
    Triangle *t6 = new Triangle(6000);
    //static and dynamic examples of constructing the triangles

    Mountain Carpathian;
    Mountain Balkan;

    Carpathian.addPeak(&t1);
    Carpathian.addPeak(&t3);
    Carpathian.addPeak(t5);
    Carpathian.addPeak(t6);
    cout << "Len of Carpathians are: " << Carpathian.getLength() << endl;

    Balkan.addPeak(&t1);
    Balkan.addPeak(&t4);
    Balkan.addPeak(t5);
    //so t1 gets & but t5 doesn't, but you're passing ultimately the same thing cuz t5 was already a pointer
    cout << "Len of Balkans are: " << Balkan.getLength() << endl;

    cout << "Due to some tectonic activity, the peaks "
            "that were 1000 meters now are 1005 meters.";
    t1.setSide(1005);
    cout << "New lenghts are " << endl;
    cout << " Carpathians: " << Carpathian.getLength() << endl;
    cout << " Balkans: " << Balkan.getLength() << endl;

    delete t5;
    delete t6;
}

int main(){

    jurassic();

    //the output will be 31400 and 21000, then after the editing of t1 to be 5 longer, will be 31410 and 21010
    //so they were BOTH changed because t1 was

    return 0;
}
