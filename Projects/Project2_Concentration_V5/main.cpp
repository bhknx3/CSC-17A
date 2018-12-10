/* 
 * File:   main.cpp
 * Author: Benjamin Kwon
 * Created on November 28, 2018, 12:00 PM
 * Purpose: Project 2 - Simulate Concentration Game
 */

//System Libraries
#include <ctime>     //Time for rand
#include <cstdlib>   //Srand to set seed
#include <fstream>   //File I/O
#include <iostream>  //Input - Output Library
using namespace std;

//User Libraries
#include "Board.h"
#include "Card.h"
#include "Data.h"
#include "Deck.h"
#include "Game.h"

//Function Prototypes
void menu(Game, Data, fstream &);

//Menu choices
enum menu {OPTION1 = 1, OPTION2, OPTION3};

//Execution begins here
int main(int argc, char** argv) {
    //Seed random generator
    srand(static_cast<unsigned int>(time(0)));
    
    Game game1;     //Create game
    Data player1;   //Create player data
    fstream stat;  //Create a file
    
    //Output menu
    menu(game1, player1, stat);
    
    //Exit
    return 0;
}

//Menu
void menu(Game game, Data player, fstream &f) {
    int input;  //Input for menu option
    
    //Output menu
    cout << "----------------------------------\n"
            "\tConcentration Game\n"
            "----------------------------------\n"
            "1. Play game\n"
            "2. Read game file\n"
            "3. Search game file\n"
            "4. Exit\n"
            "\nInput: ";
    cin >> input;   //Get input
    Game::cinClr(); //Clear input buffer
    
    //Read input from user
    switch (input) {
        case OPTION1:
            //Initialize and play game
            game.initGame();
            game.playGame();

            //Output statistics and save to file
            cout << "\n\nCongratulations! You win!\n";
            game.giveTime(player);      //Transfer time to Data class
            game.giveTurn(player);      //Transfer turns to Data class
            player.cinName();           //Get name from player
            player.setMode(game.getRows(), game.getCols()); //Get mode
            player.dspRec();            //Display statistics
            player.fileOut(f, player);  //Output statistics to file
            Game::cinClr();             //Clear input buffer
            
            //Return to main menu
            cout << "Press ENTER key to return to main menu:";
            getchar();
            cout << endl;
            menu(game, player, f);
            break;
            
        case OPTION2:
            //Read file
            player.fileIn();
            
            //Return to main menu
            cout << "Press ENTER key to return to main menu: ";
            getchar();
            cout << endl;
            menu(game, player, f);
            break;
            
        case OPTION3:
            //Search file for record
            player.search();
            
            //Return to main menu
            cout << "Press ENTER key to return to main menu: ";
            getchar();
            cout << endl;
            menu(game, player, f);
            break;
            
        default:
            //Exit program
            cout << "\nExiting program..\n";
            exit(0);
    }
}