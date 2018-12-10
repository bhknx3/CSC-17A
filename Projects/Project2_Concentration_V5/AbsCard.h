/* 
 * File:   AbsCard.h
 * Author: Benjamin Kwon
 * Created on December 8, 2018, 10:00 PM
 * Purpose: Implementation of AbsCard class
 */

#ifndef ABSCARD_H
#define ABSCARD_H

#include <string>

//Derive other classes with this abstract base class
class AbsCard {
    public:
        virtual std::string getSuit() const = 0;    //Suit value of card
        virtual std::string getFace() const = 0;    //Face value of card
};

#endif /* ABSCARD_H */