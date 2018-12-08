/* 
 * File:   Card.cpp
 * Author: Benjamin Kwon
 * Created on December 2, 2018, 8:00 PM
 * Purpose: Implementation file for Card class
 */

#include "Card.h"
#include <iostream>
using namespace std;

//Constructor
Card::Card() {
    number = 0;
    suit = "";
    face = "";
    flip = false;
    back = "\xe2\x98\x90";
}

//Constructor 2
Card::Card(int num) {
    //Validate number
    if (num>0 && num<52) {
        number = num;
    }
    else {
        number = 0;
    }
    setSuit();
    setFace();
    flip = false;
    back = "\xe2\x98\x90";
}

//Constructor 3
Card::Card(std::string f, std::string symbol) {
    number = 0;
    setSuit(symbol);
    setFace(f);
    flip = false;
    back = "\xe2\x98\x90";
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

//Get back of card
string Card::getBack() const {
    if (flip == false) {
        return back;
    }
    else {
        return getFace() + getSuit();
    }
}

void Card::setSuit() {
    static string suits[] = { "\xe2\x99\xa5", "\xe2\x99\xa3", 
                              "\xe2\x99\xa6", "\xe2\x99\xa0" };
    suit = suits[number/13];
}

//Set suit value
void Card::setSuit(string symbol) {
    //Heart
    if (symbol == "H") {
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
        cout << "ERROR: Incorrect suit value detected.\n";
    }
}

void Card::setFace() {
    static string faces[] = { "2", "3", "4", "5", "6", "7", "8", 
                              "9", "10", "J", "Q", "K", "A" };
    face = faces[number/13];
}

//Set face value
void Card::setFace(string f) {
    face = "";
    static string faces[] = { "2", "3", "4", "5", "6", "7", "8", 
                              "9", "10", "J", "Q", "K", "A" };
    for (int i=0; i<sizeof(faces)/sizeof(faces[0]); i++) {
        if (f == faces[i]) {
            f = faces[i];
            break;
        }
    }
}

//Set flip status of card
void Card::setFlip(bool b) {
    //Set flip to true
    if (b == true) {
        flip = true;
    }
    //Set flip to false
    else {
        flip = false;
    }
}

//Set back of card to a new symbol
void Card::setBack(std::string symbol) {
    //Assign symbol (string)
    back = symbol;
}