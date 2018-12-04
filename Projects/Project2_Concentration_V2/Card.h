/* 
 * File:   Card.h
 * Author: Benjamin Kwon
 * Created on December 2, 2018, 8:00 PM
 * Purpose: Specification file for Card class
 */

#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
    private:
        std::string suit;        //Suit of card
        std::string face;        //Face value of card
    public:
        //Constructor
        Card();
        //Card(std::string s=0, std::string f=0);
        //Destructor
        
        //Accessor
        std::string getSuit() const {return suit;}      //Get value of suit
        std::string getFace() const {return face;}      //Get value of face
        //Mutator
        void setSuit(std::string s) {suit = s;}         //Set suit value
        void setFace(std::string f) {face = f;}         //Set face value
        
};

#endif /* CARD_H */

