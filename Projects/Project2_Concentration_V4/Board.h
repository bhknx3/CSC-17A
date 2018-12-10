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
        Card **index;        //Position on board
        int rows;            //Rows
        int cols;            //Cols

    public:
        //Constructor
        Board(const Card *, const int, const int);
        //Destructor
        ~Board();
        //Accessors
        int getRows() const             {return rows;}
        int getCols() const             {return cols;}
        Card **getIndex() const         {return index;}
        Card * getIndex(int, int) const;
        
        //Mutators
        void setRows(int);
        void setCols(int);      
        
        //Function
        void printBoard();
        
        
};

#endif /* BOARD_H */

