/* 
 * File:   Card.cpp
 * Author: Benjamin Kwon
 * Created on December 2, 2018, 8:00 PM
 * Purpose: Implementation file for Card class
 */

#include "Card.h"
using namespace std;

//Constructor
Card::Card() {
    number = 0;
    suit = "";
    face = "";
}

//Constructor 2
Card::Card(int num) {
    //Validate number
    if (num>51) {
        number = num%52;
    }
    else if (num>=0 && num<52) {
        number = num;
    }
    else {
        throw NegVal();
    }
    setSuit();  //Set suit based on number
    setFace();  //Set face based on number
}

//Constructor 3
Card::Card(std::string f, std::string symbol) {
    number = 0;
    //Set suit and face based on parameters passed in
    setSuit(symbol);
    setFace(f);
}

//Copy constructor
Card::Card(Card &obj) {
    number = obj.number;
    suit = obj.suit;
    face = obj.face;
}

//Get suit of card (based on number)
string Card::getSuit() const {
    static string suit[] = { "\xe2\x99\xa5", "\xe2\x99\xa3", 
                             "\xe2\x99\xa6", "\xe2\x99\xa0" };
    return suit[number/13];
}

//Get face of card (based on number)
string Card::getFace() const {
    static string faces[] = { "2", "3", "4", "5", "6", "7", "8", 
                              "9", "10", "J", "Q", "K", "A" };
    return faces[number%13];
}

//Set number and corresponding suit/face
void Card::setNumb(int n) {
    //Validate number
    if (n>51) {
        number = n%52;
    }
    else if (n>=0 && n<52) {
        number = n;
    }
    else {
        throw NegVal();
    }
    setSuit();  //Set suit based on number
    setFace();  //Set face based on number
}

//Set suit value based on number member variable
void Card::setSuit() {
    static string suits[] = { "\xe2\x99\xa5", "\xe2\x99\xa3", 
                              "\xe2\x99\xa6", "\xe2\x99\xa0" };
    suit = suits[number/13];
}

//Set suit value based on parameter
void Card::setSuit(string symbol) {
    //Heart
    if (symbol == "H" || symbol == "h" || symbol == "\xe2\x99\xa5") {
        suit = "\xe2\x99\xa5";
    }
    //Clubs
    else if (symbol == "C" || symbol == "c" || symbol == "\xe2\x99\xa3") {
        suit = "\xe2\x99\xa3";
    }
    //Diamonds
    else if (symbol == "D" || symbol == "d" || symbol == "\xe2\x99\xa6") {
        suit = "\xe2\x99\xa6";
    }
    //Spades
    else if (symbol == "S" || symbol == "s" || symbol == "\xe2\x99\xa0") {
        suit = "\xe2\x99\xa0";
    }
    //Error
    else {
        string error = "ERROR: Incorrect suit value detected.\n";
        throw error;
    }
}

//Set face value based on number member variable
void Card::setFace() {
    static string faces[] = { "2", "3", "4", "5", "6", "7", "8", 
                              "9", "10", "J", "Q", "K", "A" };
    face = faces[number/13];
}

//Set face value based on parameter
void Card::setFace(string f) {
    face = "";
    static string faces[] = { "2", "3", "4", "5", "6", "7", "8", 
                              "9", "10", "J", "Q", "K", "A" };
    //Validate that the input is valid
    for (int i=0; i<sizeof(faces)/sizeof(faces[0]); i++) {
        if (f == faces[i]) {
            face = faces[i];
            break;
        }
    }
}

//Postfix increment operator
Card Card::operator ++(int) {
    Card temp(number);
    number++;
    //Cycle to get accurate suit/face based on number
    if (number == 52) {
        number = 0;
    }
    setSuit();  //Set suit based on number
    setFace();  //Set face based on number
    
    return temp;
 }
 
//Prefix increment operator
Card Card::operator ++() {
    ++number;
    //Cycle to get accurate suit/face based on number
    if (number == 52) {
        number = 0;
    }
    setSuit();  //Set suit based on number
    setFace();  //Set face based on number
    
    return *this;
 }

//Postfix decrement operator
Card Card::operator --(int) {
    Card temp(number);
    number--;
    //Cycle to get accurate suit/face based on number
    if (number == -1) {
        number = 51;
    }
    setSuit();  //Set suit based on number
    setFace();  //Set face based on number
    
    return temp;
}

//Prefix decrement operator
Card Card::operator --() {
    --number;
    //Cycle to get accurate suit/face based on number
    if (number == -1) {
        number = 51;
    }
    setSuit();  //Set suit based on number
    setFace();  //Set face based on number
    
    return *this;
}