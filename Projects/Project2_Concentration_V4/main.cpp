/* 
 * File:   main.cpp
 * Author: Benjamin Kwon
 * Created on November 28, 2018, 12:00 PM
 * Purpose: Project 2 - Simulate Concentration Game
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <ctime>     //Time for rand
#include <cstdlib>   //Srand to set seed
#include <fstream>   //File I/O
#include <iomanip>   //Formatting output
#include <string>    //Strings
#include <cmath>     //Math functions
#include <windows.h> //Sleep/pause function - for Windows only
using namespace std;

//User Libraries
#include "Card.h"
#include "Board.h"
#include "Data.h"
#include "Deck.h"
#include "Game.h"

//Function Prototypes
void menu(int &rows, int &cols);
void clrScrn();
void inGame(int &rows, int &cols);
Card *inDeck(int size);
Board **inBoard(Card *deck, int rows, int cols);
void shuffle(Card *deck, int size);
void dspBrd(Board **b, int rows, int cols);
void destroy(Board **b, int rows);
void conGame(Board **b, int rows, int cols, int &nTurns);
void getStat(Data &player, int nTurns, int timer, int rows, int cols);
void fileOut(fstream &file, Data player);
void fileIn();
void search();
void dspRec(Data player);
void cinClr();

//Enum for menu choices
enum menu { OPTION1 = 1, OPTION2, OPTION3 };

//Execution begins here
int main(int argc, char** argv) {
    //Seed random generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Variable containing number of cards in a deck
    const int numCard = 52;
    
    //Create deck of cards
    Deck deckOfCards(numCard);
    
    cout << "Initialized cards:\n";
    deckOfCards.printDeck();
    
    //Shuffle deck of cards
    cout << "\nShuffled cards:\n";
    deckOfCards.shuffle(5);
    
    deckOfCards.printDeck();
    cout << endl << endl << endl;

    cout << "Example board:\n";
    Board board(deckOfCards.getDeck(), 2, 2);
    board.printBoard();
    
    cout << "TESTING:\n";
    
    Game game;
    game.playGame(board, 2, 2);
    
    cout << "Game over." << endl;
    return 0;
    
    
    
    
    
    
    
    
    
    /*
    //Declare & initialize variables
    int row;            //Number of rows
    int col;            //Number of columns
    Data p1;            //Info data for player
    fstream file;       //Create file for input/output
    int tTotal;         //Final amount of time taken in game
    int turns = 0;      //Number of turns in game
    const int numCard = 52;   //Number of cards
    
    //Initialize variables and structures
    menu(row, col);                 //Output menu
    Card *deck = inDeck(numCard);   //Pointer to initialized deck of cards
    shuffle(deck, numCard);         //Shuffle deck of cards
    Board **gameBrd = inBoard(deck, row, col);  //Initialize game board
    
    delete []deck;  //Deallocate unneeded memory
    
    //Play the game
    int tStart = time(0);                   //Start timer
    conGame(gameBrd, row, col, turns);      //Play game
    int tEnd = time(0);                     //End timer
    tTotal = tEnd - tStart;                 //Total amount of time taken
    
    destroy(gameBrd, row); //Deallocate memory
    
    //Output statistics and save to file
    cout << "\nCongratulations! You win!\n";    //Output congratulatory message
    getStat(p1, turns, tTotal, row, col);       //Output statistics to screen
    fileOut(file, p1);                          //Output statistics to file
    */
    
    
    return 0;   //Exit main
}

/*
void menu(int &rows, int &cols)
{
    int input;  //Input
    
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
    cinClr();       //Clear input buffer
    
    switch (input)
    {
        case OPTION1:   //Initialize game set-up
            inGame(rows, cols);
            break;
        case OPTION2:   //Read file
            fileIn();
            cout << "Press ENTER key to return to main menu: ";
            getchar();
            cout << endl;
            menu(rows, cols);   //Return to menu
            break;
        case OPTION3:   //Search file for record
            search();
            cout << "Press ENTER key to return to main menu: ";
            getchar();
            cout << endl;
            menu(rows, cols);   //Return to menu
            break;
        default:        //Exit program
            cout << "\nExiting program..\n";
            exit(0);
    }
}

//Clear screen
void clrScrn() {
    cout << string(100, '\n');
}

//Initialize number of rows and columns for the board game
void inGame(int &rows, int &cols)
{
    //Loop until valid inputs are given [(row*column) must be even]
    do
    {
        //Get number of rows, loop until valid input
        do
        {
            cout << "\nEnter amount of rows    (Max: 9): ";
            cin >> rows;
            cinClr();
            if ( !(rows >= 1 && rows <= 9) )
                { cout << "ERROR: Enter a valid number of rows."; }
        } while ( !(rows >= 1 && rows <= 9) );
        
        //Get number of columns, loop until valid input
        do
        {
            cout << "Enter amount of columns (Max: 9): ";
            cin >> cols;
            cinClr();
            if ( !(cols >= 1 && cols <= 9) )
                { cout << "ERROR: Enter a valid number of columns.\n"; }
        } while ( !(cols >= 1 && cols <= 9) );
        
        //Check if row and col numbers are both odd numbers (invalid)
        if ( rows%2 != 0 && cols%2 != 0 )
        {
            cout << "ERROR: The product of the rows and columns "
                    "must be an even number.\n";
        }
    } while ( rows%2 != 0 && cols%2 != 0 );
}

//Initialize deck of cards
Card *inDeck(int size)
{
    const int nSuits = 4;     //Number of suits
    const int nCards = 13;    //Number of cards per suit
    //UTF-8 for 1.Black heart, 2.Black club, 3.Black diamond, 4.Black Spade
    string suitV[nSuits] = { "\xe2\x99\xa5", "\xe2\x99\xa3", 
                             "\xe2\x99\xa6", "\xe2\x99\xa0" };
    //Value for face cards
    string faceV[nCards] = { "2", "3", "4", "5", "6", "7", "8", 
                             "9", "10", "J", "Q", "K", "A" };
    
    //Create deck of cards with dynamic array
    Card *a = new Card[size];
     
    //Initialize deck of cards with suit and face values
    for (int i=0; i<size; i++) {
        if (i < nCards) {                           //0-12 Hearts
            a[i].setSuit( suitV[0] );               //Set suit to hearts
            a[i].setFace( faceV[i%nCards] );        //Set face value
        }
        else if (i >= nCards && i < nCards*2) {     //13-25 Clubs 
            a[i].setSuit( suitV[1] );               //Set suit to clubs
            a[i].setFace( faceV[i%nCards] );        //Set face value
        }
        else if (i >= nCards*2 && i < nCards*3) {   //26-38 Diamonds
            a[i].setSuit( suitV[2] );               //Set suit to diamonds
            a[i].setFace( faceV[i%nCards] );        //Set face value
        }
        else if (i >= nCards*3 && i < nCards*4) {   //39-51 Spades
            a[i].setSuit( suitV[3] );               //Set suit to spades
            a[i].setFace( faceV[i%nCards] );        //Set face value
        }
    }
    
    return a;
}

//Shuffle cards
void shuffle(Card *deck, int size)
{
    const int SHUF = 5;   //Number of times to shuffle
    
    for (int num=0; num<SHUF; num++)    //Shuffle shuf number of times
    {
        for (int i=0; i<size; i++)
        {
            int ranIdx = rand()%size;   //Get random index element [0, size-1]
            //Swap function
            Card temp = deck[i];
            deck[i] = deck[ranIdx];
            deck[ranIdx] = temp;
        }
    }
}

//Initialize board
Board **inBoard(Card *deck, int rows, int cols)
{
    int index = 0;  //Index value for deck input
    
    //Create new array of 2 sets of (size*size) amount of cards
    Card array[rows*cols];
    
    //Create dynamic 2D array
    Board **b = new Board*[rows];   //Create rows
    for (int i=0; i<rows; i++)
        { b[i] = new Board[cols]; } //Create columns
    
    //Insert (size) number of cards into an array twice (set of duplicates)
    for (int i=0; i<rows*cols; i++)
    {
        array[i] = deck[index];
        index++;
        if (index == rows*cols/2)
            { index = 0; }  //Reset index when half of total size is reached
    }
    shuffle(array, rows*cols);  //Shuffle new deck containing pairs
    
    index = 0;  //Reset index to 0
    //Initialize each element of the 2D array (board)
    for (int row=0; row<rows; row++)
    {
        for (int col=0; col<cols; col++)
        {
            b[row][col].setCard( array[index] );    //Set card
            b[row][col].setFlip( false );           //Set flip status to false
            b[row][col].setBack( "\xe2\x98\x90" );  //Back of card as square symbol
            index++;                            //Increase array index element
        }
    }
    return b;
}

//Display board
void dspBrd(Board **b, int rows, int cols)
{
    const int WIDTH = 7;    //Formatting

    //Output a row of numbered columns
    cout << endl << " ";
    for (int i=0; i<cols; i++)
        { cout << setw(WIDTH+1) << "C" << i+1; }
    cout << "\n\n";
    
    //Output 2D array
    for (int row=0; row<rows; row++)
    {
        cout << "R" << row+1;    //Output row number per row
        for (int col=0; col<cols; col++)
        {
            //If card is flipped, show face and suit value
            if (b[row][col].getFlip() == true)
            {
                cout << setw(WIDTH) << b[row][col].getCard().getFace()
                     << b[row][col].getCard().getSuit();
            }
            //Else card is not flipped, show back of card
            else
                { cout << setw(WIDTH+3) << b[row][col].getBack(); }
        }
        cout << endl;
    }
}

//Main game - Concentration
void conGame(Board **b, int rows, int cols, int &nTurns)
{
    int r1, c1,     //Element position of first card chosen
        r2, c2;     //Element position of second card chosen
    bool finish;    //Flag for whether the game is finished or not
    bool valid;     //Flag for whether card chosen is valid
    
    //Output instructions
    cout << "\nInstructions:\n"
            "Enter row and column values with a space in between\n"
            "or\nEnter values one by one (row first, column second)\n\n"
            "Press ENTER key to continue: ";
    getchar();  //Have user press ENTER to play game

    //Loop until all cards are flipped
    do
    {
        finish = true;  //Game is finished
        valid = false;  //Valid response 
        
        //Clear screen and display board
        clrScrn();
        dspBrd(b, rows, cols);
        
        //Loop until the first chosen card is valid
        do 
        {
            //Prompt user to choose first card and loop until input is valid
            do
            {
                cout << "Enter row and column: ";   //Prompt output
                cin >> r1 >> c1;                    //Get input positions
                if ( !(r1>=1 && r1<=rows) || !(c1>=1 && c1<=cols) )
                {
                    cout << "ERROR: Invalid input.\n";
                    cinClr();
                }
            } while ( !(r1>=1 && r1<=rows) || !(c1>=1 && c1<=cols) );
            
            //Subtract 1 from inputs to get index values
            r1--; 
            c1--;
            
            //If chosen card is already flipped over, output error message
            if (b[r1][c1].getFlip() == true)
                { cout << "ERROR: Choose another card.\n";}
            //Else, flip over chosen card
            else
            { 
                b[r1][c1].setFlip(true);  
                valid = true;
            }
        } while (!valid);
        
        //Display board with first card flipped over
        clrScrn();
        dspBrd(b, rows, cols);
        valid = false;  //Reset bool for valid
        
        //Loop until the second chosen card is valid
        do
        {
            //Prompt user to choose second card and loop until input is valid
            do
            {
                cout << "Enter row and column: ";   //Prompt output
                cin >> r2 >> c2;                    //Get input positions
                
                if ( !(r2>=1 && r2<=rows) || !(c2>=1 && c2<=cols) )
                {
                    cout << "ERROR: Invalid input.\n";
                    cinClr();
                }
            } while ( !(r2>=1 && r2<=rows) || !(c2>=1 && c2<=cols) );
            
            //Subtract 1 from inputs to get index values
            r2--;
            c2--;
            
            //Change chosen position to show value of card underneath
            if (b[r2][c2].getFlip() == true)
                { cout << "ERROR: Choose another card.\n";}
            else
            { 
                b[r2][c2].setFlip(true);
                valid = true;
            }
        } while (!valid);
        
        //Display board with the first and second cards flipped over
        clrScrn();
        dspBrd(b, rows, cols);
        Sleep(1500);    //Pause for 1.5 seconds
        
        //If the cards do not match, flip the cards back face down
        if ( b[r1][c1].getCard().getFace() + b[r1][c1].getCard().getSuit() !=
             b[r2][c2].getCard().getFace() + b[r2][c2].getCard().getSuit() )
        {
            b[r1][c1].setFlip(false);
            b[r2][c2].setFlip(false);
        }
        
        //Check if board has any remaining cards
        for (int row=0; row<rows; row++)
        {
            for (int col=0; col<cols; col++)
            {
                if (b[row][col].getFlip() == false)  //If un-flipped cards remain
                {
                    finish = false;             //Flag set to false
                    break;                      //Break out of loop
                }
            }
        }
        nTurns++;   //Count number of turns taken to finish game
    } while (!finish);
}

//Initialize Data structure values, and output statistics to screen
void getStat(Data &player, int nTurns, int timer, int rows, int cols)
{
    //Determine game mode/level of difficulty chosen
    char rowCol[4];
    rowCol[0] = rows + '0';
    rowCol[1] = 'x';
    rowCol[2] = cols + '0';
    rowCol[3] = '\0';
    
    //Initialize structure values
    player.setTurn(nTurns);
    player.setMin(timer/60);
    player.setSec(timer%60);
    //strncpy( player.getMode(), rowCol, sizeof( player.getMode() ) );
    player.setMode(rowCol);
    
    //Output statistics after getting player name
    string name;
    cout << "Enter name: ";
    cin >> name;
    player.setName(name);
    cout << "\nGame statistics:";
    player.dspRec();
}

//File output
void fileOut(fstream &file, Data player)
{
    string fileN = "GameData.dat"; //Filename
    
    //Open file
    file.open( fileN.c_str(), ios::out | ios::binary | ios::app );
    
    if (file)   //If file is valid
    {  
        file << fixed << setprecision(2);   //Formatting
        //Read record
        file.write(reinterpret_cast<char *>(&player), sizeof(player));
        
        file.close();   //Close file
        cout << "\nData successfully written to " << fileN << endl;
    }
    else
        { cout << "Could not open " << fileN << " for output.\n\n"; }
}

//Read file input
void fileIn()
{
    Data player;
    fstream file;       //Declare file
    string fileN;       //Filename - DEFAULT: "GameData.dat"
    
    cout << "\n(Default game file: GameData.dat)"
            "\nEnter name of file to open: ";
    getline(cin, fileN, '\n');
    
    //Open file
    file.open( fileN.c_str(), ios::in | ios::binary );
    
    if (file)   //If file is valid
    {
        //Read record
        file.read(reinterpret_cast<char *>(&player), sizeof(player));
        
        cout << "\nThe following records are stored:\n";
        while ( !file.eof() )
        {
            player.dspRec();    //Display record
            file.read(reinterpret_cast<char *>(&player), sizeof(player));
        }
        
        file.close();   //Close file
        cout << "\nData successfully read.\n\n";
    }
    else
        { cout << "Could not open " << fileN << " for input.\n\n"; }
}

//Search for a record in game data file
void search()
{
    Data player;
    fstream file;                   //Declare file
    ofstream outFile;               //Declare second file (output)
    string fileN = "GameData.dat";  //Filename for first file
    string outN = "Record.dat";     //Filename for second file
    int recNum;                     //Record number
    
    //Open file
    file.open( fileN.c_str(), ios::in | ios::out | ios::binary );
    
    if (file)   //If file is valid
    {
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
        cinClr();

        //If user wants to save new file
        if (outFile && input == 'y' || input == 'Y')
        {
            //Open file and write data
            outFile.open( outN.c_str(), ios::out | ios::binary );
            outFile.write(reinterpret_cast<char *>(&player), sizeof(player));
            cout << "\nData successfully written to " << outN << endl;
            outFile.close();    //Close file
        }
        else
            { cout << "Could not open " << outN << " for input.\n\n";  }

        file.close();   //Close file
        cout << endl;
    }
    else
        { cout << "Could not open " << fileN << " for input.\n\n"; }
}

//Clear cin buffer to avoid input errors
void cinClr() {
    cin.clear();                //Clear buffer
    cin.ignore(10000, '\n');    //Ignore and discard leftover characters
}
 * */