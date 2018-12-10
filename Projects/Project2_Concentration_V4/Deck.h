/* 
 * File:   Deck.h
 * Author: Benjamin Kwon
 * Created on December 6, 2018, 9:30 PM
 * 
 */

#ifndef DECK_H
#define DECK_H

#include "Card.h"

class Deck {
    private:
        int nCards;     //Number of cards in deck
        Card *card;     //Pointer to card
        int *index;     //
    public:
        //Constructor
        Deck(int);
        //Destructor
        ~Deck();
        
        
        //Accessors
        Card *getDeck() const {return card;}
        
        //Mutators
        
        
        //Functions
        void shuffle(int);
        int *deal(int);
        void printDeck();
        void printDeck(int *,int);
        void duplicate();
};

#endif /* DECK_H */

