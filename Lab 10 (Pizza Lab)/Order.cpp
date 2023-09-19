//Created by Blake

#include "Order.h"
#include "Time.h"

order::order(string x, int y) {
    contents = x;
    time = y;
}

order::order(string x, pizzaTime y) {
    contents = x;
    time = y.toInt();
}

ostream& operator<<(ostream& os, const order& ordr)
{
    os << "Contents: " << ordr.contents << endl << "Time: " << ordr.time;
    return os;
}

order::order() {
    contents = "";
    time = 0;
}
