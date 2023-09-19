#include <iostream>
#include <string>
#include <vector>

#include "Restaurant.h"

using namespace std;

//Helper function that will get the nth word in a phrase expressed as a vector of chars
//Inputs:
    //Phrase: A vector of chars with words separated by spaces
    //n: The nth word. EG, n = 1 will return the 1st word in the phrase.
//Pre: Phrase has characters in it. N is greater than 0. The phrase has at least N words.
//Postcondition: Will return a string of the phrase.
string getWord(vector<char> phrase, int n);


int main() {
    //------------COMMAND INPUT HANDLING-----------------------
    //Making placeholders so I can start making commands
    Restaurant myRest;
    string userInput = "login Dennis";

    //make user input into a vector
    vector<char> inputVec;
    for (char c: userInput) {
        inputVec.push_back(c);
    }
    //extract just the first word of the user input
    string command = "";    //this is the command-word
    for (vector<char>::iterator it = inputVec.begin(); (it < inputVec.end()) && (*it != ' '); it++){
        command.push_back(*it);
    }



    //Now we check which command word was used
    if (command == "login"){
        //get second word of UserInput as a string
        string name = getWord(inputVec, 2);
        //pass that as drivername to function
        myRest.login(name);

        cout << command << " " << name; //FOR DEBUGGING PURPOSES
    }
    else if (command == "logout"){
        //get second word of UserInput as a string
        string name = getWord(inputVec, 2);
        //pass that as drivername to function
        myRest.logout(name);
    }
    else if (command == "order"){
        //get second word for TIME
        string timeS = getWord(inputVec, 2);
        //construct a time object out of that string
        pizzaTime time(timeS);

        //get third word for INFO
        string info = getWord(inputVec, 3);

        //pass the Time obj and Info object to order
        myRest.addOrder(time, info);
    }
    else if (command == "serve"){
        //???? doesn't seem to need time here even though it's given in the command
        myRest.serve();
    }
    else if (command == "depart"){
        //2nd word is time
        string timeS = getWord(inputVec, 2);
        //construct a time object out of that string
        pizzaTime time(timeS);

        //3rd word is driver
        string driver = getWord(inputVec, 3);

        myRest.depart(time, driver);
    }
    else if (command == "deliver"){
        //2nd word is time
        string timeS = getWord(inputVec, 2);
        //construct a time object out of that string
        pizzaTime time(timeS);

        //3rd word is driver
        string driver = getWord(inputVec, 3);

        //4th word is tip
            //stof = string to float
        float tip = stof(getWord(inputVec, 3));

        myRest.deliver(time, driver, tip);
    }
    else if (command == "arrive"){
        //2nd word is time
        string timeS = getWord(inputVec, 2);
        //construct a time object out of that string
        pizzaTime time(timeS);

        //3rd word is driver
        string driver = getWord(inputVec, 3);

        myRest.arrive(time, driver);
    }
    else if (command == "status"){
        myRest.status();
    }
    else if (command == "summary"){
        myRest.summary();
    }
    else if (command == "quit"){
        myRest.quit();
    }
    else{
        cout << "Invalid command! :(" << endl;
    }
    //-----------------END COMMAND INPUT HANDLING------------------------

    return 0;
}


string getWord(vector<char> phrase, int n){
    //declare an iterator
    vector<char>::iterator location = phrase.begin();

    //move that iterator to the first letter of the nth word, by passing the right number of spaces
        //how many spaces will we need to pass? n - 1
    int spacesToPass = n - 1;
    while (spacesToPass > 0){
        //check if we're currently looking at a space. decrease
        if (*location == ' '){
            spacesToPass -= 1;
        }
        location++;
    }
    //location will now be pointing to the first letter of the nth word.

    //empty string to hold the final result
    string result = "";

    //get every char until the next space or end of phrase
    for (vector<char>::iterator it = location; (it < phrase.end()) && (*it != ' '); it++){
        result.push_back(*it);
    }
    return result;
}
