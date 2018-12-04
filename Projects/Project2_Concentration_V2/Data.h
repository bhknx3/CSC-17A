/* 
 * File:   Data.h
 * Author: Benjamin Kwon
 * Created on December 2, 2018, 8:00 PM
 * Purpose: Specification file for Data class
 */

#ifndef DATA_H
#define DATA_H

#include <string>

class Data {
    private:
        std::string name;   //Player name                               *char
        std::string mode;   //Game mode (2x2, 4x4...)                   *char
        int turn;           //Amount of turns taken to complete game
        int min;            //Amount of minutes taken to complete game
        int sec;            //Amount of seconds taken to complete game
    public:
        //Constructor
        Data();
        
        //Accessors
        std::string getName() const     {return name;}      //Get name
        std::string getMode() const     {return mode;}      //Get mode
        int getTurn() const             {return turn;}      //Get # of turns
        int getMin() const              {return min;}       //Get minutes
        int getSec() const              {return sec;}       //Get seconds
        
        //Mutators
        void setName(std::string n)          {name = n;}      //Set name
        void setMode(std::string mo)         {mode = mo;}      //Set mode
        void setTurn(int t)          {turn = t;}     //Set number of turns
        void setMin(int m)           {min = m;}      //Set minutes
        void setSec(int s)           {sec = s;}      //Set seconds
        
        
        //Functions
        void dspRec();  //Display all information
        
};

#endif /* DATA_H */

