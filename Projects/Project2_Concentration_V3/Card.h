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
        std::string back;        //Back of card
        int number;              //Number value of card
        //If flip is true -> show value, if false -> show back of card
        bool flip;               //Flag for whether the card is flipped or not
        
        
        
    public:
        //Constructor
        Card();
        Card(int);
        Card(std::string, std::string);
        
        //Destructor
        
        //Accessors
        std::string getSuit() const;
        std::string getFace() const;
        //std::string getSuit() const {return suit;}      //Get value of suit
        //std::string getFace() const {return face;}      //Get value of face
        bool getFlip() const {return flip;}
        std::string getBack() const;
                
        //Mutators
        void setSuit();                                 
        void setSuit(std::string symbol);               //Set suit value
        void setFace();
        void setFace(std::string f);                    //Set face value
        void setFlip(bool);
        void setBack(std::string);
        
        
        
        


            
        
        
        //virtual std::string getBack() const;
};

#endif /* CARD_H */

