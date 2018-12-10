/* 
 * File:   Game.h
 * Author: Benjamin Kwon
 * Created on December 8, 2018, 5:00 AM
 * Purpose: Specification of Game class
 */

#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include <iostream>
using namespace std;

class Data; //Forward declaration of Data class

class Game {
    private:
        bool finish;    //Game finished or not
        int rows;       //Rows in concentration game
        int cols;       //Columns in concentration
        int turns;      //Number of turns to finish game
        int timer;      //Time taken to finish game
    public:
        //Constructor
        Game();
        //Accessors
        bool getStat() const    {return finish;}    //Get status of game
        int getRows() const     {return rows;}      //Get rows in game
        int getCols() const     {return cols;}      //Get columns in game
        int getTurn() const     {return turns;}     //Get turns in game
        int getTime() const     {return timer;}     //Get time in game
        //Mutators
        void setStat(bool b);   //Set finish state
        void setRows(int r);    //Set rows
        void setCols(int c);    //Set columns
        //Functions
        void initGame();        //Initialize game
        void playGame();        //Play game
        static void clrScrn();  //Clear screen (static)
        static void cinClr();   //Clear input buffer (static)
        //Friend functions
        void giveTurn(Data &) const;    //Allow Data class to access turns
        void giveTime(Data &) const;    //Allow Data class to access timer
};

#endif /* GAME_H */