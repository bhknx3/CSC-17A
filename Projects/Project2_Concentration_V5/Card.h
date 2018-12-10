/* 
 * File:   Card.h
 * Author: Benjamin Kwon
 * Created on December 2, 2018, 8:00 PM
 * Purpose: Specification file for Card class
 */

#ifndef CARD_H
#define CARD_H

#include "AbsCard.h"

class Card : public AbsCard {
    protected:
        int number;         //Number value of card
        std::string suit;   //Suit of card
        std::string face;   //Face value of card
    public:
        //Exception class
        class NegVal {};    //Empty class declaration
        //Constructor
        Card();
        Card(int);
        Card(std::string, std::string);
        //Copy constructor
        Card(Card &); 
        //Accessors
        int getNumb() const {return number;}    //Get number value
        std::string getSuit() const;            //Get suit value
        std::string getFace() const;            //Get face value       
        //Mutators
        void setNumb(int);                  //Set number
        void setSuit();                     //Set suit value
        void setSuit(std::string symbol);   //Set suit value
        void setFace();                     //Set face value
        void setFace(std::string f);        //Set face value
        //Operator overload
        Card operator ++(int);      //Overloaded postfix increment 
        Card operator ++();         //Overloaded prefix increment 
        Card operator --(int);      //Overloaded postfix decrement
        Card operator --();         //Overloaded prefix decrement      
};

#endif /* CARD_H */