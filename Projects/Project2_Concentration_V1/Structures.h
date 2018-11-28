/* 
 * File:   Structures.h
 * Author: Benjamin Kwon
 * Created on November 28, 2018, 12:00 PM
 * Purpose: Structures, Enum
 */

#ifndef STRUCTURES_H
#define STRUCTURES_H

//Enum for menu choices
enum menu { OPTION1 = 1, OPTION2, OPTION3 };

struct Card
{
    string suit;        //Suit of card
    string face;        //Face value of card
};

struct Board
{
    Card card;          //Card
    bool flip;          //Flag for whether the card is flipped or not
    string back;        //Symbol for back side of card
};

struct Data
{
    char name[10];      //Player name
    char mode[4];       //Game mode (2x2, 4x4...)
    int turn;           //Amount of turns taken to complete game
    int min;            //Amount of minutes taken to complete game
    int sec;            //Amount of seconds taken to complete game
};

#endif /* STRUCTURES_H */