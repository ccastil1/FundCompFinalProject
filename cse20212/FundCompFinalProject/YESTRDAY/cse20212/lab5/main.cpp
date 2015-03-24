#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include "Puzzle.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "here";
    if(argc != 1)
    {
        cout << "\nUsing " << argv[1] <<endl;
        return 1;
    }
  
  Puzzle<int> Sudoku(argv[1]);
  
  Sudoku.print_puzzle();

    
   /* int game = 2;
    while(game != 1)
    {
        Sudoku.boardPlacement();
    }
    
    cout << endl; */
}
