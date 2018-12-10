/* 
 * File:   GameCard.h
 * Author: Benjamin Kwon
 * Created on December 8, 2018, 10:00 PM
 * Purpose: Specification of GameCard class
 */

#ifndef GAMECARD_H
#define GAMECARD_H

#include "Card.h"

class GameCard : public Card {
    private:
        //If flip is true -> show value, if false -> show back of card
        bool flip;               //Flag for whether the card is flipped or not
        std::string back;        //Back of card
    public:
        //Constructors
        GameCard();
        GameCard(int);
        GameCard(std::string, std::string);
        //Accessors
        bool getFlip() const;           //Get flip status
        std::string getBack() const;    //Get side of card that is facing up
        //Mutators
        void setFlip(bool);             //Set flip status
        void setBack(std::string);      //Set symbol for back of card
};

#endif /* GAMECARD_H */