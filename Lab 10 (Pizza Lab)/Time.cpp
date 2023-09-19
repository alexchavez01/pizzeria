//Created by Blake

#include "Time.h"

pizzaTime::pizzaTime(std::string x) {
    string temp1;
    string temp2;

    if (x.length() == 8){
        temp1 = (x[0]);
        temp2 = (x[1]);
        hours = ((std::stoi(temp1)) *10) + (std::stoi(temp2));

        temp1 = (x[3]);
        temp2 = (x[4]);
        minutes = ((std::stoi(temp1)) *10) + (std::stoi(temp2));

        if (temp1 == "P"){
            hours = hours + 1200;
        }
        temp1 = x[0];
        temp1 = temp1 + x[1];
    } else if (x.length() == 5) {
        temp1 = (x[0]);
        temp2 = (x[1]);
        hours = ((std::stoi(temp1)) *10) + (std::stoi(temp2));

        temp1 = (x[3]);
        temp2 = (x[4]);
        minutes = ((std::stoi(temp1)) *10) + (std::stoi(temp2));
    }else{
        cout << "Error: Input must be a time";
    }

}

string pizzaTime::timeToString(int x) {
    string y;
    string temp;

    if (x < 2360 && (x%100)<60 ){
        if (x < 1000){
            temp = "0";
            if (x < 100){
                temp = temp + "0";
            }
        }
        temp = temp + to_string(x);
        for (int i = 0; i <= 3; ++i) {
            y = y + temp[i];
            if(i == 1){
                y = y + ":";
            }
        }
        if (x > 1200){
            y = y + " PM";
        } else {
            y = y + " AM";
        }
    }else{
        cout << "Error: Input must be a time";
    }
    return y;
}

//converts string to time
int pizzaTime::stringToTime(string x) {
    int y;
    int counter = 4;
    int hold;
    string temp;

    if (x.length() == 8) {
        for (int i = 0; i <= 5; ++i) {
            if (i == 2) {
            } else {
                temp = temp + (x[i]);
            }
            y = std::stoi(temp);
        }
        temp = x[6];
        if (temp == "P") {
            y = y + 1200;
        }
        temp = x[0];
        temp = temp + x[1];
        if (temp == "00") {
            y = y - 1200;
        }
    } else if (x.length() == 5) {
        for (int i = 0; i <= 5; ++i) {
            if (i == 2) {
            } else {
                temp = temp + (x[i]);
            }
            y = std::stoi(temp);
        }
    }else{
        cout << "Error: Input must be a time";
        y = 9999;
    }
    return y;
}

//get minute difference (no object)
float pizzaTime::getDifference(int x, int y) {
    float output;
    int tempDiff;
    if (x < 2360 && (x%100)<60 ){
        tempDiff = y - x;
    } else {
        tempDiff = 9999;
    }

    if (tempDiff > 59){
        output = ((tempDiff/100)*60) + (tempDiff%100);
    }else{
        output = ((tempDiff/100)*60);
    }

    return output;
}

//get minute difference (pizzaTime object)
float pizzaTime::getDifference(pizzaTime x) {
    float output;

    if (x.hours < hours){
        output = (2400-hours) + hours;
    } else {
        output = (x.hours - hours)*60;
    }

    output = output + (x.minutes - minutes);

    return output;
}

//access data
string pizzaTime::toString() {
    string temp = "";
    if (hours < 1){
        temp = "0";
    }
    temp = temp + to_string(hours) + ":" + to_string(minutes);
    return temp;
}

//access data
int pizzaTime::toInt() {
    int temp = 0;
    string temp2;
    if (hours < 1){
        temp2 = "0";
    }
    temp2 = temp2 + to_string(hours) + ":" + to_string(minutes);
    temp = stringToTime(temp2);
    return temp;
}

//defult constructor
pizzaTime::pizzaTime() {
    hours = 0;
    minutes = 0;
}
