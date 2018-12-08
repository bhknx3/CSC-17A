/* 
 * File:   Board.h
 * Author: Benjamin Kwon
 * Created on December 2, 2018, 8:00 PM
 * Purpose: Specification file for Board class
 */

#ifndef BOARD_H
#define BOARD_H

#include "Card.h"
#include "Deck.h"

class Board {
    private:
        Card **index;             //Position on board
        int rows;            //Rows
        int cols;            //Cols

    public:
        //Constructor
        Board(const Card *, const int, const int);
        //Destructor
        ~Board();
        //Accessors
        int getRows() const     {return rows;}
        int getCols() const     {return cols;}
        Card **getIndex() const   {return index;}
        Card * getIndex(int, int) const;
        
        
        //bool getFlip() const        {return flip;}
       //std::string getBack() const {return back;}
        
        //Mutators
       // void setFlip(bool s)        {flip = s;}         //Set flip value
       // void setCard(Card c)        {card = c;}         //Set card
       // void setBack(std::string b) {back = b;}
        void setRows(int r);
        void setCols(int c);
        
        
        //Function
        void printBoard();
        
        
};

#endif /* BOARD_H */

