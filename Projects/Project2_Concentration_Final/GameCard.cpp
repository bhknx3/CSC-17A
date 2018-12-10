/* 
 * File:   GameCard.cpp
 * Author: Benjamin Kwon
 * Created on December 8, 2018, 10:00 PM
 * Purpose: Implementation of GameCard class
 */

#include "GameCard.h"
using namespace std;

//Constructor
GameCard::GameCard():Card() {
    flip = false;
    back = "\xe2\x98\x90";
}

//Constructor 2
GameCard::GameCard(int num) : Card(num) {
    flip = false;
    back = "\xe2\x98\x90";
}

//Constructor 3
GameCard::GameCard(string f, string symbol) : Card(f, symbol) {
    flip = false;
    back = "\xe2\x98\x90";
}

//Get flip status of card
bool GameCard::getFlip() const {
    return flip;
}

//Get the side of the card that is currently facing up
string GameCard::getBack() const {
    //If card is face down with back on top
    if (flip == false) {
        //Return the symbol for back of the card
        return back;
    }
    //If card is face up with picture side up
    else {
        //Return the face and suit value of the card
        return Card::getFace() + Card::getSuit();
    }
}

//Set flip status of card
void GameCard::setFlip(bool b) {
    //Set flip to true
    if (b == true) {
        flip = true;
    }
    //Set flip to false
    else if (b == false) {
        flip = false;
    }
    else {
        string error = "ERROR: Invalid input detected.\n";
        throw error;
    }
}

//Set back of card to a new symbol
void GameCard::setBack(std::string symbol) {
    //Assign symbol (string)
    back = symbol;
}