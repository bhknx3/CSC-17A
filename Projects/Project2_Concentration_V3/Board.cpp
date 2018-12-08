/* 
 * File:   Board.cpp
 * Author: Benjamin Kwon
 * Created on December 2, 2018, 8:00 PM
 * Purpose: Implementation file for Board class
 */

#include "Board.h"
#include <iostream>
#include <iomanip>
using namespace std;

Board::Board(const Card *cards, const int row, const int col) {
    //card =;          //Card
    //flip = false;    //Flag for whether the card is flipped or not
    //back = "";  
    
    //int index = 0;  //Index value for deck input
    
    //Create new array of 2 sets of (size*size) amount of cards
    //Card array[rows*cols];
    rows = row;
    cols = col;
    
    //Create dynamic 2D array
    index = new Card*[row];   //Create rows
    for (int i=0; i<row; i++) {
        index[i] = new Card[col];
    }
    
    
   /* 
    Deck *ptr = new Deck[row*col];
    
    //Put into pointer the number of cards that will fill up the board
    for (int i=0; i<row*col, i++) {
        ptr[i] = cards[i];
    }
   */
    
    
    
    int element = 0;
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            index[i][j] = cards[element];
            element++;
        }
    }
    
    //Create columns
   
    
    /*
    //Insert (size) number of cards into an array twice (set of duplicates)
    for (int i=0; i<rows*cols; i++)
    {
        array[i] = deck[index];
        index++;
        if (index == rows*cols/2)
            { index = 0; }  //Reset index when half of total size is reached
    }
    shuffle(array, rows*cols);  //Shuffle new deck containing pairs
    
    index = 0;  //Reset index to 0
    //Initialize each element of the 2D array (board)
    for (int row=0; row<rows; row++)
    {
        for (int col=0; col<cols; col++)
        {
            b[row][col].setCard( array[index] );    //Set card
            b[row][col].setFlip( false );           //Set flip status to false
            b[row][col].setBack( "\xe2\x98\x90" );  //Back of card as square symbol
            index++;                            //Increase array index element
        }
    }
     */
}


//Destructor
Board::~Board() {
    //Deallocate memory
    for (int i=0; i<rows; i++) {
        delete []index[i];
    }
    delete []index;
}


void Board::setRows(int r) {
    if (r>0) {
        rows = r;
    }
}
void Board::setCols(int c) {
    if (c>0) {
        cols = c;
    }
}

 void Board::printBoard() {
    const int WIDTH = 7;    //Formatting

    //Output a row of numbered columns
    cout << endl << " ";
    for (int i=0; i<cols; i++)
        { cout << setw(WIDTH+1) << "C" << i+1; }
    cout << "\n\n";
    
    //Output 2D array
    //Print row
    for (int row=0; row<rows; row++)
    {
        //Output row number per row
        cout << "R" << row+1;
        //Print column
        for (int col=0; col<cols; col++)
        {
            //Print out values in 2D array
            cout << setw(WIDTH+3) << index[row][col].getBack();
        }
        cout << endl;
    }
}
 
 Card * Board::getIndex(int r, int c) const {
    return &index[r][c];
 }
 
 