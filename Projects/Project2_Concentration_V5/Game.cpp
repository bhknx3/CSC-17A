/* 
 * File:   Game.cpp
 * Author: Benjamin Kwon
 * Created on December 8, 2018, 5:00 AM
 * Purpose: Implementation of Game class
 */

#include "Board.h"
#include "Data.h"
#include "Game.h"
#include <ctime>     //Time
#include <iostream>  //Input - Output Library
#include <windows.h> //Sleep/pause function - for Windows only
using namespace std;

//Constructor
Game::Game() {
    //Initialize member variables
    finish = false;
    rows = 0;
    cols = 0;
    turns = 0;
    timer = 0;
}

//Initialize game (get rows and columns from user)
void Game::initGame() {
    //Loop until valid inputs are given [(row*column) must be even]
    do {
        //Get number of rows, loop until input is valid
        do {
            cout << "\nEnter amount of rows    (Max: 9): ";
            cin >> rows;
            cinClr();
            
            //Input validation
            if ( !(rows >= 1 && rows <= 9) ) {
                cout << "ERROR: Enter a valid number of rows.";
            }
        } while ( !(rows >= 1 && rows <= 9) );
        
        //Get number of columns, loop until valid input
        do {
            cout << "Enter amount of columns (Max: 9): ";
            cin >> cols;
            cinClr();
            
            //Input validation
            if ( !(cols >= 1 && cols <= 9) ) {
                cout << "ERROR: Enter a valid number of columns.\n";
            }
        } while ( !(cols >= 1 && cols <= 9) );
        
        //Check if row and col numbers are both odd numbers (invalid)
        if ( rows%2 != 0 && cols%2 != 0 ) {
            cout << "ERROR: The product of the rows and columns "
                    "must be an even number.\n";
        }
    } while ( rows%2 != 0 && cols%2 != 0 );
}

void Game::playGame() {
    int tStart = time(0);       //Start timer
    
    //Variable containing number of cards in a deck
    const int numCard = 52;
    const int numShuf = 5;
    
    //Create deck of cards
    Deck<GameCard> deckCrd(numCard);
    
    //Shuffle deck of cards (using STL)
    deckCrd.shuffle();
    
    //Create board
    Board<GameCard> b(deckCrd.getDeck(), rows, cols);
    
    //Display answer if necessary
    //b.dspAns();
    
    int r1, c1,     //Element position of first card chosen
        r2, c2;     //Element position of second card chosen
    bool valid;     //Flag for whether card chosen is valid
    turns = 0;
    
    //Output instructions
    cout << "\nInstructions:\n"
            "Enter row and column values with a space in between\n"
            "or\nEnter values one by one (row first, column second)\n\n"
            "Press ENTER key to continue: ";
    getchar();  //Have user press ENTER to play game

    //Loop until all cards are flipped
    do {
        finish = true;  //Flag to determine whether the game is over or not
        valid = false;  //Flag indicating a valid response 
        
        //Clear screen and display board
        clrScrn();
        b.dspBrd();
        
        //Loop until the first chosen card is valid
        do {
            //Prompt user to choose first card and loop until input is valid
            do {
                cout << "Enter row and column: ";   //Prompt output
                cin >> r1 >> c1;                    //Get input positions
                
                //Input validation
                if ( !(r1>=1 && r1<=rows) || !(c1>=1 && c1<=cols) ) {
                    cout << "ERROR: Invalid input.\n";
                    cinClr();
                }
            } while ( !(r1>=1 && r1<=rows) || !(c1>=1 && c1<=cols) );
            
            //Subtract 1 from inputs to get index values
            r1--; 
            c1--;
            
            //If chosen card is already flipped over, output error message
            if (b.getIndx(r1,c1)->getFlip() == true) {
                cout << "ERROR: Choose another card.\n";
            }
            //Else, flip over chosen card
            else { 
                b.getIndx(r1,c1)->setFlip(true);
                valid = true;
            }
        } while (!valid);
        
        //Display board with first card flipped over
        clrScrn();
        b.dspBrd();
        valid = false;  //Reset bool for valid
        
        //Loop until the second chosen card is valid
        do {
            //Prompt user to choose second card and loop until input is valid
            do {
                cout << "Enter row and column: ";   //Prompt output
                cin >> r2 >> c2;                    //Get input positions
                
                //Input validation
                if ( !(r2>=1 && r2<=rows) || !(c2>=1 && c2<=cols) ) {
                    cout << "ERROR: Invalid input.\n";
                    cinClr();
                }
            } while ( !(r2>=1 && r2<=rows) || !(c2>=1 && c2<=cols) );
            
            //Subtract 1 from inputs to get index values
            r2--;
            c2--;
            
            //If the card chosen is already being shown, output error message
            if (b.getIndx(r2,c2)->getFlip() == true) {
                cout << "ERROR: Choose another card.\n";
            }
            //Change chosen position to show value of card underneath
            else { 
                b.getIndx(r2,c2)->setFlip(true);
                valid = true;
            }
        } while (!valid);
        
        //Display board with the first and second cards flipped over
        clrScrn();
        b.dspBrd();
        Sleep(1500);    //Pause for 1.5 seconds
        
        //If the cards do not match, flip the cards back face down
        if ( b.getIndx(r1,c1)->getFace() + b.getIndx(r1,c1)->getSuit() != 
             b.getIndx(r2,c2)->getFace() + b.getIndx(r2,c2)->getSuit() ) {
            b.getIndx(r1,c1)->setFlip(false);
            b.getIndx(r2,c2)->setFlip(false);
        }
        
        //Check if board has any remaining cards
        for (int row=0; row<rows; row++) {
            for (int col=0; col<cols; col++) {
                //If un-flipped cards remain
                if (b.getIndx(row, col)->getFlip() == false) {
                    finish = false;     //Game is not finished
                    break;              //Break out of loop
                }
            }
        }
        turns++;   //Count number of turns taken to finish game
    } while (!finish);
    
    int tEnd = time(0);      //End timer
    timer = tEnd - tStart;   //Total amount of time taken to play game
}
       
//Clear screen
void Game::clrScrn() {
    cout << string(100, '\n');
}

//Clear cin buffer to avoid input errors
void Game::cinClr() {
    cin.clear();                //Clear buffer
    cin.ignore(10000, '\n');    //Ignore and discard leftover characters
}

//Set finish status of game
void Game::setStat(bool b) {
    if (b == true) {
        finish = true;
    }
    else if (b == false) {
        finish = false;
    }
    else {
        string error = "ERROR: Invalid input detected.\n";
        throw error;
    }
}

//Set number of rows in game
void Game::setRows(int r) {
    if (r>0) {
        rows = r;
    }
    else {
        string error = "ERROR: Negative value detected.\n";
        throw error;
    }
}

//Set number of columns in game
void Game::setCols(int c) {
    if (c>0) {
        cols = c;
    }
    else {
        string error = "ERROR: Negative value detected.\n";
        throw error;
    }
}

//Return turn to friend
void Game::giveTurn(Data &info) const {
    info.setTurn(turns);
}

//Return time to friend
void Game::giveTime(Data &info) const {
    //Amount of minutes taken to complete game
    info.setMin(timer/60);
    //Amount of seconds taken to complete game
    info.setSec(timer%60);
}