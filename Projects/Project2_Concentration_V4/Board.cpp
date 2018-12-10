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
    //Initialize member variables
    rows = row;
    cols = col;

    //Create new array to hold a new deck of cards
    Card *aDeck = new Card[rows*cols];
    int element = 0;    //To hold index value
    
    //Each card in the new deck will have a duplicate card
    for (int i=0; i<rows*cols; i++) {
        aDeck[i] = cards[element];      //Assign value
        element++;                      //Increase index counter
        //If counter reaches half of original size
        if (element == rows*cols/2) {
            //Assign to 0 to restart card value copying process
            element = 0;
        }
    }
    
    //Scramble new deck
    const int nScramble = 5;    //Number of times to scramble
    for (int n=0; n<nScramble; n++) {
        //Number of cards to go through
        for (int i=0; i<rows*cols; i++) {
            //Get random index value
            int cardNum = rand()%rows*cols;
            //Swap function
            Card temp = aDeck[i];
            aDeck[i] = aDeck[cardNum];
            aDeck[cardNum] = temp;
        }
    }
    
    for (int i=0; i<rows*cols; i++) {
        cout << aDeck[i].getFace() << aDeck[i].getSuit() << " ";
    }
    cout << endl;
    for (int i=0; i<rows*cols; i++) {
       cout << cards[i].getFace() << cards[i].getSuit() << " ";
    }
  
    //Create dynamic 2D array
    index = new Card*[row];         //Create rows
    for (int i=0; i<row; i++) {
        index[i] = new Card[col];   //Create columns
    }

    element = 0;    //Reset counter
    //Loop through rows
    for (int i=0; i<row; i++) {
        //Loop through columns
        for (int j=0; j<col; j++) {
            index[i][j] = aDeck[element];   //Assign value
            element++;                      //Increase counter
        }
    }
    
    //Deallocate memory
    delete [] aDeck;
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
 
 