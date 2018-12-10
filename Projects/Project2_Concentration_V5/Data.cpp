/* 
 * File:   Data.cpp
 * Author: Benjamin Kwon
 * Created on December 2, 2018, 8:00 PM
 * Purpose: Implementation file for Data class
 */

#include "Data.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

//Constructor
Data::Data() {
    name = "";      //Player name
    mode = "";      //Game mode (2x2, 4x4...)
    turn = 0;       //Amount of turns taken to complete game
    min = 0;        //Amount of minutes taken to complete game
    sec = 0;        //Amount of seconds taken to complete game
}

//Constructor 2
Data::Data(Game &info) {
    name = "";                 //Player name
    mode = "";                 //Game mode (2x2, 4x4...)
    turn = info.getTurn();     //Amount of turns taken to complete game
    min = info.getTime()/60;   //Amount of minutes taken to complete game
    sec = info.getTime()%60;   //Amount of seconds taken to complete game
}

//Display information
void Data::dspRec() {
    //Formatting
    cout << fixed << setprecision(2);
    //Output information
    cout << "\nGame Statistics:\n";
    cout << "Name       : " << name << endl <<
            "Board size : " << mode << endl << 
            "Turns taken: " << turn << endl <<
            "Time taken : " << min << " minutes, " << sec << " seconds\n";
}

//Set name using extraction operator
void Data::cinName() {
    cout << "Enter name: ";
    cin >> name;
}

//Set mode by receiving row and column as parameters and returning as string
void Data::setMode(int r, int c) {
    mode = to_string(r) + "x" + to_string(c);
}

//File output
void Data::fileOut(fstream &file, Data player) {
    //Filename
    string fileN = "GameData.dat";
    
    //Open file
    file.open( fileN.c_str(), ios::out | ios::binary | ios::app );
    
    //If file is valid
    if (file) {  
        //Formatting
        file << fixed << setprecision(2);
        //Read record
        file.write(reinterpret_cast<char *>(&player), sizeof(player));
        //Close file
        file.close();
        //Output message confirming data writing
        cout << "\nData successfully written to " << fileN << endl << endl;
    }
    //If file is invalid
    else {
        cout << "Could not open " << fileN << " for output.\n\n";
    }
}

//Read file input
void Data::fileIn()
{
    Data player;
    fstream file;       //Declare file
    string fileN;       //Filename - DEFAULT: "GameData.dat"
    
    cout << "\n(Default game file: GameData.dat)"
            "\nEnter name of file to open: ";
    getline(cin, fileN, '\n');
    
    //Open file
    file.open( fileN.c_str(), ios::in | ios::binary );
    
    if (file) { //If file is valid
        //Read record
        file.read(reinterpret_cast<char *>(&player), sizeof(player));
        
        //Read and display record
        cout << "\nThe following records are stored:\n";
        while ( !file.eof() ) {
            player.dspRec();
            file.read(reinterpret_cast<char *>(&player), sizeof(player));
        }
        
        //Close file
        file.close();
        cout << "\nData successfully read.\n\n";
    }
    else {
        cout << "Could not open " << fileN << " for input.\n\n";
    }
}

//Search for a record in game data file
void Data::search() {
    Data player;                    //Data object
    fstream file;                   //Declare file
    ofstream outFile;               //Declare second file (output)
    string fileN = "GameData.dat";  //Filename for first file
    string outN = "Save.dat";       //Filename for second file
    int recNum;                     //Record number
    
    //Open file
    file.open( fileN.c_str(), ios::in | ios::out | ios::binary );
    
    if (file) { //If file is valid
        //Prompt user to enter record number to search for
        cout << "\nSearching specific record in GameData.dat .."
                "\nEnter record number (ex. 1): ";
        cin >> recNum;
        
        //Seek, read, and display record
        cout << "\nHere is record " << recNum << ":\n"; 
        file.seekg(sizeof(Data)*(recNum-1), ios::beg); 
        file.read(reinterpret_cast<char *>(&player), sizeof(player)); 
        player.dspRec();
        
        //Prompt user if he or she wants to save record to a new file
        char input;
        cout << "\nWould you like to save this record to a new file? "
                "(y/n): ";
        cin >> input;
        Game::cinClr();

        //If user wants to save new file
        if (outFile && input == 'y' || input == 'Y') {
            //Open file and write data
            outFile.open( outN.c_str(), ios::out | ios::binary );
            outFile.write(reinterpret_cast<char *>(&player), sizeof(player));
            cout << "\nData successfully written to " << outN << endl << endl;
            outFile.close();    //Close file
        }
        else {
            file.close();
        }
        cout << endl;
    }
    else {
        cout << "Could not open " << fileN << " for input.\n\n";
    }
}