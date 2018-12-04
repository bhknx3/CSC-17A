/* 
 * File:   Board.h
 * Author: Benjamin Kwon
 * Created on December 2, 2018, 8:00 PM
 * Purpose: Specification file for Board class
 */

#ifndef BOARD_H
#define BOARD_H

#include "Card.h"

class Board {
    private:
        Card card;          //Card
        bool flip;          //Flag for whether the card is flipped or not
        std::string back;        //Symbol for back side of card
    public:
        //Constructor
        Board();
        
        //Destructor
        
        //Accessor
        Card getCard() const        {return card;}
        bool getFlip() const        {return flip;}
        std::string getBack() const {return back;}
        
        //Mutator
        void setFlip(bool s)        {flip = s;}         //Set flip value
        void setCard(Card c)        {card = c;}         //Set card
        void setBack(std::string b) {back = b;}
        
        
};

#endif /* BOARD_H */

