/* 
 * File:   Data.h
 * Author: Benjamin Kwon
 * Created on December 2, 2018, 8:00 PM
 * Purpose: Specification file for Data class
 */

#ifndef DATA_H
#define DATA_H

#include "Game.h"
#include <fstream>
#include <string>

class Data {
    private:
        std::string name;   //Player name
        std::string mode;   //Game mode (2x2, 4x4...)
        int turn;           //Amount of turns taken to complete game
        int min;            //Amount of minutes taken to complete game
        int sec;            //Amount of seconds taken to complete game
    public:
        //Constructor
        Data();
        Data(Game &);
        //Accessors
        std::string getName() const {return name;}  //Get name
        std::string getMode() const {return mode;}  //Get mode
        int getTurn() const         {return turn;}  //Get # of turns
        int getMin() const          {return min;}   //Get minutes
        int getSec() const          {return sec;}   //Get seconds
        //Mutators
        void cinName();                                 //Get name as input
        void setName(std::string n)     {name = n;}     //Set name
        void setMode(std::string mo)    {mode = mo;}    //Set mode
        void setMode(int, int);                         //Set mode w/ row&col
        void setTurn(int t)             {turn = t;}     //Set number of turns
        void setMin(int m)              {min = m;}      //Set minutes
        void setSec(int s)              {sec = s;}      //Set seconds
        void setData(Game &);
        //Functions
        void dspRec();                  //Display all information
        void fileOut(fstream &, Data);  //Create out file w/ game statistics
        void fileIn();                  //Read in file containing game statistics
        void search();                  //Search for specific file number
        //Friend functions
        friend void Game::giveTurn(Data &) const;   //Pass in # of turns
        friend void Game::giveTime(Data &) const;   //Pass in timer value
};

#endif /* DATA_H */