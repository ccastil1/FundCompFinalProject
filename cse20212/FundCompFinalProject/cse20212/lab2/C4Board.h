//Celeste Castillo
//CSE 20212
//Lab 2
//This header file establishes the class C4Board with its various member functions and variables

#ifndef C4BOARD_H
#define C4BOARD_H

#include <iostream>
#include "C4Col.h"
using std::ostream;
using namespace std;
using std::cout;

class C4Board{    //class definition for a connect four board game class to manage display the board, placing the discs with each move, etc
	friend ostream &operator<<(ostream &, const C4Board &);

	public:                     //public constructor, destructor, and member functions
		C4Board(int n = 7);    //default constructor, sets setColumns to 7
	//	~C4Board();                     //declare a destructor
		void display(){cout << *this << endl;}        //member function which will display the current board
		void play();            //member function which will allow two players to play the game

	private:                   //private variables
		int numCols;       //number of columns
		char helper();   //member function which determines if a player has won the game and displays a message if so
		C4Col columns[10];         //pointer for C4Col columns to store the character('X' or 'O')
};

#endif

