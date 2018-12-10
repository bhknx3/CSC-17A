/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Game.h"
#include <iostream>
#include <windows.h> //Sleep/pause function - for Windows only
using namespace std;

//Constructor
Game::Game() {
    finish = false;
}

void Game::initGame(int rows, int cols) {
    //Loop until valid inputs are given [(row*column) must be even]
    do {
        //Get number of rows, loop until valid input
        do {
            cout << "\nEnter amount of rows    (Max: 9): ";
            cin >> rows;
            cinClr();
            if ( !(rows >= 1 && rows <= 9) ) {
                cout << "ERROR: Enter a valid number of rows.";
            }
        } while ( !(rows >= 1 && rows <= 9) );
        
        //Get number of columns, loop until valid input
        do {
            cout << "Enter amount of columns (Max: 9): ";
            cin >> cols;
            cinClr();
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

void Game::playGame(Board b, int rows, int cols) {
    
    int r1, c1,     //Element position of first card chosen
        r2, c2;     //Element position of second card chosen
    bool valid;     //Flag for whether card chosen is valid
    int nTurns = 0;
    
    //Output instructions
    cout << "\nInstructions:\n"
            "Enter row and column values with a space in between\n"
            "or\nEnter values one by one (row first, column second)\n\n"
            "Press ENTER key to continue: ";
    getchar();  //Have user press ENTER to play game

    //Loop until all cards are flipped
    do {
        finish = true;  //Game is finished
        valid = false;  //Valid response 
        
        //Clear screen and display board
        clrScrn();
        b.printBoard();
        
        
        //Loop until the first chosen card is valid
        do {
            //Prompt user to choose first card and loop until input is valid
            do {
                cout << "Enter row and column: ";   //Prompt output
                cin >> r1 >> c1;                    //Get input positions
                if ( !(r1>=1 && r1<=rows) || !(c1>=1 && c1<=cols) ) {
                    cout << "ERROR: Invalid input.\n";
                    cinClr();
                }
            } while ( !(r1>=1 && r1<=rows) || !(c1>=1 && c1<=cols) );
            
            //Subtract 1 from inputs to get index values
            r1--; 
            c1--;
            
            //If chosen card is already flipped over, output error message
            if (b.getIndex(r1,c1)->getFlip() == true) {
                cout << "ERROR: Choose another card.\n";
            }
            //Else, flip over chosen card
            else { 
                b.getIndex(r1,c1)->setFlip(true);
                valid = true;
            }
        } while (!valid);
        
        //Display board with first card flipped over
        clrScrn();
        b.printBoard();
        valid = false;  //Reset bool for valid
        
        //Loop until the second chosen card is valid
        do {
            //Prompt user to choose second card and loop until input is valid
            do {
                cout << "Enter row and column: ";   //Prompt output
                cin >> r2 >> c2;                    //Get input positions
                
                if ( !(r2>=1 && r2<=rows) || !(c2>=1 && c2<=cols) ) {
                    cout << "ERROR: Invalid input.\n";
                    cinClr();
                }
            } while ( !(r2>=1 && r2<=rows) || !(c2>=1 && c2<=cols) );
            
            //Subtract 1 from inputs to get index values
            r2--;
            c2--;
            
            //Change chosen position to show value of card underneath
            if (b.getIndex(r2, c2)->getFlip() == true) {
                cout << "ERROR: Choose another card.\n";
            }
            else { 
                b.getIndex(r2, c2)->setFlip(true);
                valid = true;
            }
        } while (!valid);
        
        //Display board with the first and second cards flipped over
        clrScrn();
        b.printBoard();
        Sleep(1500);    //Pause for 1.5 seconds
        
        //If the cards do not match, flip the cards back face down
        if ( b.getIndex(r1,c1)->getFace() != b.getIndex(r2,c2)->getFace() ) {
            b.getIndex(r1,c1)->setFlip(false);
            b.getIndex(r2,c2)->setFlip(false);
        }
        
        //Check if board has any remaining cards
        for (int row=0; row<rows; row++) {
            for (int col=0; col<cols; col++) {
                //If un-flipped cards remain
                if (b.getIndex(row, col)->getFlip() == false) {
                    finish = false;     //Game is not finished
                    break;              //Break out of loop
                }
            }
        }
        nTurns++;   //Count number of turns taken to finish game
    } while (!finish);
}