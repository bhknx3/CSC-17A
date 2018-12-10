/* 
 * File:   Deck.h
 * Author: Benjamin Kwon
 * Created on December 6, 2018, 9:30 PM
 * Purpose: Specification & Implementation of Deck class
 */

#ifndef DECK_H
#define DECK_H

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
#include "GameCard.h"

//Specification
template <class T>
class Deck {
    private:
        int nCards;             //Number of cards in deck
        T *card;                //Pointer to card
    public:
        //Constructor
        Deck(int);
        
        //Destructor
        ~Deck();
        
        //Accessors
        int getNCard() const;   //Get number of cards in deck
        T *getDeck() const;     //Get pointer to deck
        
        //Functions
        void shuffle();         //Shuffle deck (using algorithm)
        void shuffle(int);      //Shuffle deck
        void printDeck();       //Print deck
};

//Implementation

//Constructor
template <class T>
Deck<T>::Deck(int n) {
    //Validate number of cards
    if (n>=2) {
        nCards = n;
    }
    else {
        string error = "ERROR: Invalid number of cards.\n";
        throw error;
    }
    
    //Create pointer to deck(array) of cards
    card = new T[nCards];
    
    //Create cards
    for (int crd=0; crd<nCards; crd++) {
        card[crd] = T(crd);
    }
}

//Destructor
template <class T>
Deck<T>::~Deck() {
    //Deallocate memory
    delete [] card;
}

//Get number of cards in deck
template <class T>
int Deck<T>::getNCard() const {
    return nCards;
}

//Get pointer to deck
template <class T>
T * Deck<T>::getDeck() const {
    return card;
}

//Shuffle deck of cards using a vector
template <class T>
void Deck<T>::shuffle() {
    //Create a vector
    vector<int> vect;
    
    //Push back values (corresponding to index) to vector
    for (int i=0; i<nCards; i++) {
        vect.push_back(i);
    }
    
    //Use algorithm to shuffle vector
    random_shuffle(vect.begin(), vect.end());
    
    for (int i=0; i<nCards; i++) {
        T temp = card[i];
        card[i] = card[vect[i]];
        card[vect[i]] = temp;
    }
    
    //"Deallocate" memory by vector (swap vector with an empty vector)
    vector<int>().swap(vect);
}

//Shuffle deck of cards using swap function
template <class T>
void Deck<T>::shuffle(int nShuf) {
    //Number of times to shuffle
    for (int n=0; n<nShuf; n++) {
        //Number of cards to go through
        for (int cd=0; cd<nCards; cd++) {
            //Get random index value
            int indxNum = rand()%nCards;
            //Swap function
            T temp = card[cd];
            card[cd] = card[indxNum];
            card[indxNum] = temp;
        }
    }
}

//Output deck of cards
template <class T>
void Deck<T>::printDeck() {
    for(int cd=0; cd<nCards; cd++) {
        cout << card[cd].getFace() << card[cd].getSuit();
    }
}

#endif /* DECK_H */