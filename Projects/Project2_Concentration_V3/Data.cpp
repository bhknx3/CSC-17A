/* 
 * File:   Data.cpp
 * Author: Benjamin Kwon
 * Created on December 2, 2018, 8:00 PM
 * Purpose: Implementation file for Data class
 */

#include "Data.h"
#include <iomanip>
#include <iostream>
using namespace std;

Data::Data() {
    name = "";      //Player name
    mode = "";      //Game mode (2x2, 4x4...)
    turn = 0;       //Amount of turns taken to complete game
    min = 0;        //Amount of minutes taken to complete game
    sec = 0;        //Amount of seconds taken to complete game
}

//Display information
void Data::dspRec() {
    cout << fixed << setprecision(2);   //Formatting
    
    cout << "\nName       : " << name << endl <<
            "Board size : "   << mode << endl << 
            "Turns taken: "   << turn << endl <<
            "Time taken : "   << min << " minutes, "
                              << sec << " seconds\n";
}