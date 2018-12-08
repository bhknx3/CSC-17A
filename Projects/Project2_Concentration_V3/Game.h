/* 
 * File:   Game.h
 * Author: Benjamin Kwon
 * Created on December 8, 2018, 5:00 AM
 * Purpose:
 */

#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include <iostream>
using namespace std;

class Game {
    private:
        bool finish;    //Game finished or not
    public:
        Game();
        
        //Functions
        void playGame(Board b, int rows, int cols);
        
        //Clear screen
        void clrScrn() {
            cout << string(100, '\n');
        }
        
        //Clear cin buffer to avoid input errors
        void cinClr() {
            cin.clear();                //Clear buffer
            cin.ignore(10000, '\n');    //Ignore and discard leftover characters
        }
        
        
        
};

#endif /* GAME_H */

