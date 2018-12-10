/* 
 * File:   Deck.h
 * Author: Benjamin Kwon
 * Created on December 6, 2018, 9:30 PM
 * 
 */


#include "Deck.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//Constructor
Deck::Deck(int n) {
    //Validate number of cards
    if (n>=2) {
        nCards = n;
    }
    else {
        cout << "ERROR: Invalid number of cards.\n";
    }

    //Create pointer to deck(array) of cards
    card = new Card[nCards];
    
    //Create cards
    for(int crd=0; crd<nCards; crd++) {
        card[crd]= Card(crd);  
    }
}

//Destructor
Deck::~Deck() {
    //Deallocate memory
    delete []card;
}

//Shuffle deck of cards
void Deck::shuffle(int nShuf) {
    //Number of times to shuffle
    for (int n=0; n<nShuf; n++) {
        //Number of cards to go through
        for (int cd=0; cd<nCards; cd++) {
            //Get random index value
            int cardNum = rand()%nCards;
            //Swap function
            Card temp = card[cd];
            card[cd] = card[cardNum];
            card[cardNum] = temp;
        }
    }
}

void Deck::printDeck() {
    for(int cd=0; cd<nCards; cd++) {
        cout << card[cd].getFace() << card[cd].getSuit();
    }
}