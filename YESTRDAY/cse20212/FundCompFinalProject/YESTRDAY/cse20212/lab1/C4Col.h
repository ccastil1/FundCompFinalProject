//Celeste Castillo
//CSE 20212
//Lab 1
//This header file establishes the class C4Col with its various member functions and variables.

#ifndef C4COL_H
#define C4COL_H

#include <iostream>
using namespace std;

class C4Col{            //class definition for a connect four board column class
public:
    C4Col(int newMaxDiscs = 6);            //default constructor;
    ~C4Col();
    int isFull();       //function to determine if the column is full
    char getDisc(int);  //function to return the requested element of the private character array
    int getMaxDiscs();  //function to return the maximum number of rows
    void addDisc(char); //function to add the a specific disc's character representation
    
private:
    int numDiscs;       //current number of discs used
    int maxDiscs;       //maximum number of discs allowed
    char *Discs;       //character array to store the discs's representations
};

#endif
