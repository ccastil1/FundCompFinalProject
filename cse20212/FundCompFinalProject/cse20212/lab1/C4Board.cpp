//Celeste Castillo
//CSE 20212
//Lab 1
//This .cpp file contains the definitions of the functions declared in the C4Board class in the C4Board.h file

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "C4Board.h"
using namespace std;

C4Board::C4Board(int n){
    numCols = n;
    columns = new C4Col[numCols];
}

void C4Board::display(){
    for(int rowNum = columns[0].getMaxDiscs(); rowNum >0; rowNum--){     //yvalue formatting for rows
        cout << "|";
        for(int colNum=0; colNum < numCols; colNum++){                      //xvalue formatting for columns
            cout << columns[colNum].getDisc(rowNum-1)<<"|";
        }
        cout << endl;
    }
    
    for(int i =0; i<numCols; i++){         //display column number labels
        cout << " " << i;
    }
    cout << endl;
}


void C4Board::play(){                       //definition of play() member function which allows there to be two players for a game
    int turn = 1, win = 0, choice = 0, helper = 0;
    char buffer;
    this->display();                        //"->" replaces the "." operator because pointers are in use
    
    while(1)
    {
        if(turn%2)
        {                         //for player 1
            cout << "Enter the column you want to put a disc in: " << endl;         //displays message to the user asking which column they want to put a disc in
            cin >> choice;                                                          //assigns the column to the variable choice
            while (!(choice >= 0 && choice < numCols && !(columns[choice].isFull())))
            {      //error handling, if the column is less than 0, greater than 7, or if the columm is full, an error message is displayed and the user is prompted to re-enter a column selection
                cout << "Error! Enter a valid column." << endl;
                cin >> choice;
            }
            
            columns[choice].addDisc('X');              //adds the character representation 'X' to the connect four board in the desired place
        }
        
        else{
            int player2 = rand() % 7;                  //in this case, player 2 would be the computer; rand is used with "%7" to randomize the selection of one of the 7 columns
            while(columns[choice].isFull()){
                player2 = rand() % 7;
            }
            
            columns[player2].addDisc('O');              //adds the character representation 'O' to the connect four board in the randomized computer selection
        }
        
        buffer = this->helper();               //"->" replaces the "." operator because pointers are in use
        if(buffer == 'X')                       //if the buffer value receives 'X' from the return of the helper function, win is set to 1
        {
            win = 1;
        }
        else if(buffer == 'O')                  //if the buffer value receives 'O' from the return of the helper function, win is set to 2
        {
            win = 2;
        }
        if(helper != 0) break;                  //error handling, if there is an error with the helper function, the program will end
        
        if (win == 1){
            cout << "Player 1 wins!" << endl;       //displays message that player 1 won
            break;
        }
        
        else if(win == 2){
            cout << "Player 2 wins!" << endl;       //displays message that player 2 won
            break;
        }
        
        this->display();                    //"->" replaces the "." operator because pointers are in use
        turn++;
    }
    
}

char C4Board::helper()
{
    int count = 0;              //count serves as a counter for the number of consecutive similar characters
    
    for(int rowNum = columns[0].getMaxDiscs(); rowNum > 0; rowNum--)        //for loop descends the rows to check for consecutive similar characters
    {
        for(int colNum = 0; colNum < numCols; colNum++)                     //for loop starts at the x=0 position and goes through the positions to count consecutive characters
        {
            if (columns[colNum].getDisc(rowNum) == 'X' || columns[colNum].getDisc(rowNum) == 'O')
            {
                count = 0;
                
                for(int j = 0; j<=4; j++)    //for loop to check the board spaces for vertical connections of 4 'X' or 'O' characters
                {
                    if(rowNum + j < columns[0].getMaxDiscs())
                    {
                        if(columns[colNum].getDisc(rowNum + j) == columns[colNum].getDisc(rowNum))      //increases count if the function finds consecutive characters
                        {
                            count++;
                        }
                    }
                    else
                    {
                        break;
                    }
                    if(count >=4)                                           //if 4 characters form a connection, the respective character is returned
                    {
                        return columns[colNum].getDisc(rowNum);
                    }
                }

                count =0;
                
                for(int i = 0; i<=4; i++)    // for loop to check for horizontal connections of 4 disc characters
                {
                    if((colNum + i) < numCols)
                    {
                        if(columns[colNum+i].getDisc(rowNum) == columns[colNum].getDisc(rowNum))
                        {
                            count++;
                        }
                    }
                    else
                    {
                        break;
                    }
                    
                    if(count >=4)
                    {
                        return columns[colNum].getDisc(rowNum);         //returns respective character if a connection of 4 is found

                    }
                }
            
                count =0;
                
                for(int i = 0,count = 0; i<=4; i++)                 //for loop checks for diagonal connections of 4 similar characters
                {
                    if(rowNum+i < columns[0].getMaxDiscs() && colNum + i < numCols)
                    {
                        if(columns[colNum + i].getDisc(rowNum + i) == columns[colNum].getDisc(rowNum))
                        {
                            count++;
                        }
                    }
                    else
                    {
                        break;
                    }
                    if(count >= 4)
                    {
                        return columns[colNum].getDisc(rowNum);     //returns respective character if a connection of 4 is found

                    }
                }
                
                count = 0;
                
                for (int j = 0,count = 0; j<=4; j++)            //for loop checks for diagonal connections of 4 similar characters
                {
                    if(rowNum + j < columns[0].getMaxDiscs() && colNum - j <= 0)
                    {
                        if(columns[colNum + j].getDisc(rowNum) == columns[colNum].getDisc(rowNum))
                        {
                            count++;
                        }
                    }
                    else
                    {
                        break;
                    }
                    if(count >=4)
                    {
                        return columns[colNum].getDisc(rowNum);         //returns respective character if a connection of 4 is found
                    }
                }
            }
        }
    }
}

C4Board::~C4Board()
{                                    //destructor utilizes the delete function to clear the elements and reset the pointer
    delete [] columns;
    columns = nullptr;
}





