/* 
 * File:   Board.h
 * Author: Benjamin Kwon
 * Created on December 2, 2018, 8:00 PM
 * Purpose: Specification and implementation file for Board class
 */

#ifndef BOARD_H
#define BOARD_H

#include <iomanip>
using namespace std;
#include "Deck.h"
#include "GameCard.h"

//Specification
template <class T>
class Board {
    private:
        T **index;    //Position on board
        int rows;     //Rows
        int cols;     //Columns
    public:
        //Exception class
        class NegSize {};   //Negative size
        //Constructor
        Board(const GameCard *, const int, const int);
        //Destructor
        ~Board();
        //Accessors
        int getRows() const {return rows;}  //Get rows
        int getCols() const {return cols;}  //Get columns
        T **getIndx() const {return index;} //Get index
        T * getIndx(int, int) const;        //Get address of certain element
        //Mutators
        void setRows(int);  //Set rows
        void setCols(int);  //Set columns
        //Function
        void dspBrd();      //Display board
        void dspAns();      //Display answer  
};

//Implementation

//Constructor
template <class T>
Board<T>::Board(const GameCard *cards, const int row, const int col) {
    //Initialize member variables
    if (row>0) {
        rows = row;
    }
    else {
        throw NegSize();
    }
    if (col>0) {
        cols = col;
    }
    else {
        throw NegSize();
    }

    T *aDeck = new T[rows*cols];    //Create array to hold new deck of cards
    int element = 0;                //To hold index value
    
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
    const int nScramble = 5;
    //Number of times to scramble
    for (int n=0; n<nScramble; n++) {
        //Number of cards to go through
        for (int i=0; i<rows*cols; i++) {
            //Get random index value
            int cardNum = rand()%rows*cols;
            //Swap function
            T temp = aDeck[i];
            aDeck[i] = aDeck[cardNum];
            aDeck[cardNum] = temp;
        }
    }
  
    //Create dynamic 2D array
    index = new T*[row];         //Create rows
    for (int i=0; i<row; i++) {
        index[i] = new T[col];   //Create columns
    }

    //Reset counter
    element = 0;
    //Loop through rows
    for (int i=0; i<row; i++) {
        //Loop through columns
        for (int j=0; j<col; j++) {
            index[i][j] = aDeck[element];   //Assign value to member variable
            element++;                      //Increase counter
        }
    }
    
    //Deallocate memory
    delete [] aDeck;
}

//Destructor
template <class T>
Board<T>::~Board() {
    //Deallocate memory
    for (int i=0; i<rows; i++) {
        delete []index[i];          //Delete columns
    }
    delete []index;                 //Delete rows
}

//Return address of 2D array
template <class T>
T * Board<T>::getIndx(int r, int c) const {
    return &index[r][c];
}

//Set rows
template <class T>
void Board<T>::setRows(int r) {
    if (r>0) {
        rows = r;
    }
    else {
        string error = "ERROR: Invalid number detected.\n";
        throw error;
    }
}

//Set columns
template <class T>
void Board<T>::setCols(int c) {
    if (c>0) {
        cols = c;
    }
    else {
        string error = "ERROR: Invalid number detected.\n";
        throw error;
    }
}

//Display board
template <class T>
void Board<T>::dspBrd() {
    const int WIDTH = 7;    //Formatting

    //Output a row of numbered columns
    cout << endl << " ";
    for (int i=0; i<cols; i++) {
        cout << setw(WIDTH+1) << "C" << i+1;
    }
    cout << "\n\n";
    
    //Output 2D array
    //Print row
    for (int row=0; row<rows; row++) {
        //Output row number per row
        cout << "R" << row+1;
        //Print column
        for (int col=0; col<cols; col++) {
            //Print out values in 2D array
            cout << setw(WIDTH+3) << index[row][col].getBack();
        }
        cout << endl;
    }
}
 
//Display answer
template <class T>
void Board<T>::dspAns() {
    const int WIDTH = 7;    //Formatting

    //Output a row of numbered columns
    cout << endl << " ";
    for (int i=0; i<cols; i++) {
        cout << setw(WIDTH+1) << "C" << i+1;
    }
    cout << "\n\n";

    //Print row
    for (int row=0; row<rows; row++) {
        //Output row number per row
        cout << "R" << row+1;
        //Print column
        for (int col=0; col<cols; col++) {
            //Print out values in 2D array
            cout << setw(WIDTH+3) << index[row][col].getFace()
                                  << index[row][col].getSuit();
        }
        cout << endl;
    }
}

#endif /* BOARD_H */