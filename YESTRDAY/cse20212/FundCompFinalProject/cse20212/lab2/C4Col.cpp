//Celeste Castillo
//CSE 20212
//Lab 2
//This .cpp file defines the member functions of the class C4Col, established in the C4Col.h file

#include <iostream>
#include "C4Col.h"
using namespace std;

C4Col::C4Col(int newMaxDiscs){          //default constructor
    numDiscs = 0;                       //initializes the number of discs to 0
    maxDiscs = newMaxDiscs;
  //  Discs = new char[maxDiscs];
    for (int i; i < maxDiscs; i++)
    {
        Discs[i] = ' ';
    }
}

int C4Col::isFull(){                    //member funciton isFull() checks to see if the column is full
    numDiscs = 0;
    for(int i=0; i<maxDiscs; i++)
    {
     if(Discs[i] == 'X' || Discs[i] == 'O')
     {
         numDiscs++;
     }
    }
    if(numDiscs >= maxDiscs){
        return (1);
    }
    else return(0);
}

char C4Col::getDisc(int row) const{           //member function getDisc(int row) returns the desired element from the private character array Discs established in C4Col.h
    return Discs[row];
}


int C4Col::getMaxDiscs() const{               //member function getMaxDiscs() returns the maximum number of discs
    return maxDiscs;
}

void C4Col::addDisc(char newDisc){      //member function addDisc(char) adds the character('X' or 'O') to the next open slot in the Disc array
    if(this->isFull() == 0)
    {
        Discs[numDiscs++] = newDisc;
    }
    else
    {
        cout << "The row is full!" << endl;         //error handling, if the user chooses a row that is full, they will be shown an error message
    }
}

C4Col C4Col::operator+=(char a)
{
	addDisc(a);
	return(*this);
}

/*C4Col::~C4Col(){                        //declaration of destructor
    delete [] Discs;
}*/
