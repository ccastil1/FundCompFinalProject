/***********************************************************************
* Program:
*    Project 4, Sudoku
*    Brother Helfrich, CS124
* Author:
*    Casey Moffett
* Summary:
*    This program is designed to let the user play Sudoku
*
*    Estimated:  10.0 hrs.
*    Actual:     10.0 hrs. 
*      Figuring out that I put a wrong value in one of the square 
*      quadrant search loop, 
************************************************************************/

/***********************************************************************
* This assignment has been lots of fun, and probably one of the easiest
* that I have done of the projects. I have found that working with visual
* studio has really helped me speed up my coding, because I have syntax help,
* and can test as I go and have full use of all the settings that I am used to.
*
*
* Functions Required:
*   -Main -driver to call everything to action
*   -getFileName to prompt the user for the file which has the game card
*   -readFile stores the file as usable data
*   -interact -handles the commands and processing functions
*   -displayBoard - displays the Sudoku board
*   -saveFile -saves the board to a file and then exits the program
*   -displayCMD - displays the list of commands
*   -possibleVal - detects all the possible values of a set space
*   -cords - takes the inputted grid square and turns it into a usable 
*          -coordinates for the program
*   -col & row - searches a row/Colum for available numbers
*   -quad -searches a square for possible values.
*   -solve - solves the puzzle
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
* Function getFileName asks the user for a file name which contains the
* game board is located.
*
* Variables Used:    fileName error
***********************************************************************/
void getFileName(char fileName[256], int error)
{
   if (!(error > 0))
   {
      cout << "Where is your board located? ";
      cin >> fileName; // fileName is the variable for the Sudoku puzzle
      ifstream fin(fileName);
   }
   else
   {
      cout << "Something went wrong, please re-enter the file name: ";
      cin >> fileName; // fileName is the variable for the Sudoku
      ifstream fin(fileName);
   }
   
   return;
}

/**********************************************************************
* Function readFile will read Sudoku file and copy it to an array
*
*
* Variables Used:      fileName[256]  && gameBoard[9][9][11] && tBoard[9][9]
* Variables created:   input errorNum
***********************************************************************/
void readFile(char fileName[], int gameBoard[][9][11], int tBoard[][9])
{
   ifstream fin(fileName);
   int errorNum = 0; //number of times the person has to re-enter the file name
   // if user give a bad file name re-prompt user for a file 
   while (fin.fail())
   {
	   getFileName(fileName, ++errorNum);
      fin.open(fileName);
   }

   for (int i = 0; i < 9; i++)
   { //This loop grabs the data from the file and inputs it into the array 
	   for (int secI = 0; secI < 9; secI++) //that is usable by the game.
	   {
		   int input;
		   fin >> input;
		   for (int trdI = 0; trdI < 10; trdI++)
		   {
			   gameBoard[i][secI][trdI] = trdI;
		   }
		   gameBoard[i][secI][10] = input;
		   tBoard[i][secI] = input;
	   }

   }
   fin.close(); //close the file
   return;
}

/**********************************************************************
* Function displayCMD, displays the board commands for the game.
*
* Variables Used:      
***********************************************************************/
void displayCMD()
{
	cout << "  Options:\n"
		 << "   ?  Show these instructions\n"
	     << "   D  Display the board\n"
		 << "   E  Edit one square\n"
		 << "   S  Show the possible values for a square\n"
		 << "   V  Have the computer Solve the board"
		 << "   Q  Save and Quit\n\n";

	return;
}

/**********************************************************************
* Function displayBoard displays the board to the user
*
* Variables Used:      gameBoard[9][9][11]
***********************************************************************/
void displayBoard(int gameBoard[][9][11], int tBoard[][9])
{
	cout << "   A B C D E F G H I\n";
   for (int i = 0; i < 9; i++)
   {
	   cout << (i +1 );
	   cout << " ";
		    
	   for (int secI = 0; secI < 9; secI++)
	   {
		   if (secI == 3 || secI == 6)
			   cout << '|';
		   else
		   {
			   cout << ' ';
		   }
		   if (gameBoard[i][secI][10] == 0)
		   {
			   cout << ' ';
		   }
		   else if (!(tBoard[i][secI] == 0))
		   {
			   //cout << "\E[22;32m" << gameBoard[i][secI][10] << "\E[0m";
			   cout << gameBoard[i][secI][10];
		   }
		   else
		       cout << gameBoard[i][secI][10];
	   }
	   cout << endl;
	   if (i == 2 || i == 5)
	   {
		   cout << "   -----+-----+-----\n";
	   }
   }
   cout << endl;
   return;
}

/**********************************************************************
* Function cords processes coordinates input and gives the array values fo
* for the game board
*
* Variables s Used:      one && two && c1 && c2
***********************************************************************/
void cords(char one, char two, int &c1, int &c2)
{
	char swap2 = 0;
	if (one == 'a' || one == 'A')
		c1 = 0;
	else if (one == 'b' || one == 'B')
		c1 = 1;
	else if (one == 'c' || one == 'C')
		c1 = 2;
	else if (one == 'd' || one == 'D')
		c1 = 3;
	else if (one == 'e' || one == 'E')
		c1 = 4;
	else if (one == 'f' || one == 'F')
		c1 = 5;
	else if (one == 'g' || one == 'G')
		c1 = 6;
	else if (one == 'h' || one == 'H')
		c1 = 7;
	else if (one == 'i' || one == 'I')
		c1 = 8;
	else
	{
		swap2 = one;
		one = two; // this reverses the input, if the user inputted in this 
		two = swap2; // format 4a, it changes it to a4
		if (one == 'a' || one == 'A')
			c1 = 0;
		else if (one == 'b' || one == 'B')
			c1 = 1;
		else if (one == 'c' || one == 'C')
			c1 = 2;
		else if (one == 'd' || one == 'D')
			c1 = 3;
		else if (one == 'e' || one == 'E')
			c1 = 4;
		else if (one == 'f' || one == 'F')
			c1 = 5;
		else if (one == 'g' || one == 'G')
			c1 = 6;
		else if (one == 'h' || one == 'H')
			c1 = 7;
		else if (one == 'i' || one == 'I')
			c1 = 8;
	}

	if (two == '1')
		c2 = 0;
	else if (two == '2')
		c2 = 1;
	else if (two == '3')
		c2 = 2;
	else if (two == '4')
		c2 = 3;
	else if (two == '5')
		c2 = 4;
	else if (two == '6')
		c2 = 5;
	else if (two == '7')
		c2 = 6;
	else if (two == '8')
		c2 = 7;
	else if (two == '9')
		c2 = 8;
	else
		{
			cout << "ERROR: Square '"
			     << one << two
				 << "' is invalid";
		}
	return;
}

/**********************************************************************
* Function editBoard, allows the user to update a space on the board
* as long as it is not altering an original assigned space this is why
* we have two copies of the game board, gameBoard which is the editable
* copy and tBoard, which is what we test a change against. if the space is
* not zero on tBoard than it is invalid.
*
* Variables Used:      gameBoard[9][9][11] && tBoard
* Variables Created:   one && two && c1 && c2 && change
***********************************************************************/
void editBoard(int gameBoard[][9][11], int tBoard[][9])
{
	cout << "What are the coordinates of the square: ";
	char one; // first inputted char
	char two; // second user input
	int c1 = 0; //will be assigned as the first int grid cord
	int c2 = 0; // second grid cord
	int change; // the new number to go in the coordinates provided
	cin >> one >> two;
	cords(one, two, c1, c2);
	if (tBoard[c2][c1] == 0)
	{
		cout << "What is the value at '"
			 << one << two
			 << "': ";
		cin >> change;
	//	possibleVal(gameBoard);
		/*if (game)
		{

		}*/
		gameBoard[c2][c1][10] = change;
	}
	else
		{
			cout << "ERROR: Square '"
			     << one << two
				 << "' is filled.";
		}
	return;
}


/**********************************************************************
* Function save(bool), collects the saving file name saves and exits
* if user inputs X it will save only re-writing the file and retuning
* false and not exiting the command loop.
*
* Varibles Used:      gameBoard[9][9][11]
* Varibles Created:   fileOut
***********************************************************************/
bool saveFile(int gameBoard[][9][11])
{
	char fileOut[256];
	cout << "What file would you like to write your board to: ";
	cin >> fileOut;
	ofstream oFile;
	oFile.open (fileOut);
      for (int i = 0; i < 9; i++)
      {
         for (int secI = 0; secI < 9; secI++)
         {
		     oFile << gameBoard[i][secI][11]
			       << ' ';
         }
	     oFile << '\n';
      }
	oFile.close();
	return true;
}

/**********************************************************************
* Function row, checks to find all the possible naked values from a row
*
* Variables Used:      gameBoard[9][9][11] && c1 && c2 && pValue
***********************************************************************/
void row(int gameBoard[][9][11], int c1, int c2, int pValue[])
{
   int val = 0;
   for (int i = 0; i < 9; i++)
   {
	   val = gameBoard[c2][i][10];
	   if (val > 0)
	   {
		  pValue[val] = 0;
	   }
   }
	return;
}

/**********************************************************************
* Function hRow, checks to find all the possible hidden values from a row
*
* Variables Used:      gameBoard[9][9][11] && c1 && c2 && pValue
***********************************************************************/
void hRow(int gameBoard[][9][11], int c1, int c2, int pValue[])
{
   int val = 0;
   for (int i = 0; i < 9; i++)
   {
	   for (int secI = 0; secI < 10; secI++)
	   {
		  val = gameBoard[c2][i][secI];
	      if (val > 0)
	      {
			 //cout << val << "  ";
			 //cout << pValue[val] << " ";
		     pValue[val] = 0;
			 //cout << pValue[val] << endl;
	      }
	   }
	   
   }
	return;
}

/**********************************************************************
* Function col, checks to find all the possible naked values from a col
*
* Variables Used:      gameBoard[9][9][11] && c1 && c2 && pValue
***********************************************************************/
void col(int gameBoard[][9][11], int c1, int c2, int pValue[])
{
   int val = 0;
   for (int i = 0; i < 9; i++)
   {
	   val = gameBoard[i][c1][10];
	   if (val > 0)
	   {
		   pValue[val] = 0;
	   }
   }
	return;
}

/**********************************************************************
* Function hCol, checks to find all the possible hiden values from a col
*
* Variables Used:      gameBoard[9][9][11] && c1 && c2 && pValue
***********************************************************************/
void hCol(int gameBoard[][9][11], int c1, int c2, int pValue[])
{
   int val = 0;
   for (int i = 0; i < 9; i++)
   {
	   for (int secI = 0; secI < 10; secI++)
	   {
		  val = gameBoard[i][c1][secI];
	      if (val > 0)
	      {
	         pValue[val] = 0;
	      }
	   }
	  
   }
	return;
}

/**********************************************************************
* Function qSearch, finds the search paramiters
*
* Variables Used:      gameBoard[9][9][11] && c1 && c2 && pValue
***********************************************************************/
void qSearch(int c1, int c2, int &s1, int &s2)
{
   if (c1 < 3)
	   s1 = 0;
   else if (c1 < 6 && c1 >= 3)
	   s1 = 3;
   else if (c1 < 9 && c1 >= 6)
	   s1 = 6;

   if (c2 < 3)
	   s2 = 0;
   else if (c2 < 6 && c2 >= 3)
	   s2 = 3;
   else if (c2 < 9 && c2 >= 6)
	   s2 = 6;
   else
   {
	   cout << "error " << endl;
   }
}

/**********************************************************************
* Function hQuad, searches for hidden singles instead of naked singles
*
* Variables Used:      gameBoard[9][9][11] && c1 && c2 && pValue
***********************************************************************/
void hQuad(int gameBoard[][9][11], int c2, int c1, int pValue[])
{
   int s1,s2; // search parameters
   qSearch(c1, c2, s1, s2);
   int val = 0;
   for (int i = s1; i < (s1 + 3); i++)
   {
	   for (int secI = s2; secI < (s2 + 3); secI++)
	   {
		   for (int trdI = 0; trdI < 10; trdI++)
		   {
			  val = gameBoard[i][secI][trdI];
		      if (val > 0)
		      {
			     pValue[val] = 0;
		      }
		   }
	   }
   }
   return;

}

/**********************************************************************
* Function quad, search of square quadrents.
*
* Variables Used:      gameBoard[9][9][11] && c1 && c2 && pValue
***********************************************************************/
void quad(int gameBoard[][9][11], int c2, int c1, int pValue[])
{
   int s1,s2; // search parameters
   qSearch(c1, c2, s1, s2);

      int val = 0;
   for (int i = s1; i < (s1 + 3); i++)
   {
	   for (int secI = s2; secI < (s2 + 3); secI++)
	   {
		   val = gameBoard[i][secI][10];
		   if (val > 0)
		   {
			   pValue[val] = 0;
		   }
	   }
   }

	return;
}



/**********************************************************************
* Function solve, solves the board for the user.
*
* Variables Used:      gameBoard[9][9][11] 
***********************************************************************/
void solve(int gameBoard[][9][11], int tBoard[][9])
{
	int c1, c2;
	int count;
	do
	{
		int Udate = 0;
		count = 0;
		for (int i = 0; i < 9; i++)
		{
			for (int secI = 0; secI < 9; secI++)
			{
				c1 = (secI);
				c2 = (i);
				int pValue[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
				if (gameBoard[i][secI][10] == 0)
				{
					count++;
				    row(gameBoard, c1, c2, pValue);
					col(gameBoard, c1, c2, pValue);
					quad(gameBoard, c1, c2, pValue);
					int val = 0; //value of possible values
					int possiblCount = 0; // counts the number of possible values
					for (int thrI = 0; thrI < 10; thrI++)
					{
						if (!(pValue[thrI] == 0))
						{
							val = pValue[thrI];
							++possiblCount;
						}
						gameBoard[i][secI][thrI] = pValue[thrI];
					}
					if (possiblCount == 1 && val < 10)
						{
							gameBoard[i][secI][10] = val;
							Udate++;
						}
				    
				}
				else
				{
					for (int trdI = 0; trdI < 10; trdI++)
					{
						if (gameBoard[i][secI][trdI] == gameBoard[i][secI][10])
						{

						}
						else
						   gameBoard[i][secI][trdI] = 0;
					}
				}
			}
		}
		if (Udate == 0)
		{
			for (int i = 0; i < 9; i++)
			{
				for (int secI = 0; secI < 9; secI++)
				{
					c1 = (secI);
					c2 = (i);
					int pValue[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
					if (gameBoard[i][secI][10] == 0)
					{
						count++;
						//hRow(gameBoard, c1, c2, pValue);
						//hCol(gameBoard, c1, c2, pValue);
						//hQuad(gameBoard, c1, c2, pValue);
						int val = 0; //value of possible values
						int possiblCount = 0; // counts the number of possible values
						for (int thrI = 0; thrI < 10; thrI++)
						{
							if (!(pValue[thrI] == 0))
							{
								val = pValue[thrI];
								++possiblCount;
							}
							//gameBoard[i][secI][thrI] = pValue[thrI];
						}
						if (possiblCount == 1 && val < 10)
							{
								gameBoard[i][secI][10] = val;
								Udate++;
							}
					}
				}
			}
		}
		if (Udate == 0)
		{
			break;
		}

	} while (count > 0);
	displayBoard(gameBoard, tBoard);
	return;
}

void pid(int gameBoard[][9][11])
{
   cout << "What are the coordinates of the square: ";
   char one; // first inputed char
   char two; // seconed user input
   int c1 = 0; //will be assinged as the first int grid cord
   int c2 = 0; // seconed grid cord
   int change; // the new number to go in the coordinates provided
   cin >> one >> two;
   cords(one, two, c1, c2);
   cout << "The possible values for '"
	    << one << two
		<< "' are: ";
   int first = 0;//determins if the output is the first to be outputed
   for (int i = 0; i < 10; i++)
   {
	   
	   if (!(gameBoard[c2][c1][i] == 0))
	   {
		   if (first == 0)
		   {
			   cout << gameBoard[c2][c1][i];
			   ++first;
		   }
		   else
		   {
			   cout << ", ";
			   cout << gameBoard[c2][c1][i];
		   }
	   }
   }
   cout << endl;
	return;
}

/**********************************************************************
* Function possibleVal, checks to find all the possible values for a space
*
* Variables Used:      gameBoard[9][9][11] 
***********************************************************************/
void possibleVal(int gameBoard[][9][11])
{
   cout << "What are the coordinates of the square: ";
   char one; // first inputed char
   char two; // seconed user input
   int c1 = 0; //will be assinged as the first int grid cord
   int c2 = 0; // seconed grid cord
   int change; // the new number to go in the coordinates provided
   cin >> one >> two;
   cords(one, two, c1, c2);
   int pValue[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   row(gameBoard, c1, c2, pValue);
   col(gameBoard, c1, c2, pValue);
   quad(gameBoard, c1, c2, pValue);
   cout << "The possible values for '"
	    << one << two
		<< "' are: ";
   int first = 0;//determins if the output is the first to be outputed
   for (int i = 0; i < 10; i++)
   {
	    
	   if (!(pValue[i] == 0))
	   {
		   if (first == 0)
		   {
			   cout << pValue[i];
			   ++first;
		   }
		   else
		   {
			   cout << ", ";
			   cout << pValue[i];
		   }
	   }
	   if (pValue[i] == 0)
		      gameBoard[c2][c1][i] = 0;
   }
   cout << endl;
   return;
}


/**********************************************************************
* Function Interact will is the command processor for the game, housing
* the command line functions that the game uses. 
*
*
* Variables Used:      gameBoard[9][9][11] && tBoard[9][9]
* Variables Created:   cmd && quit
***********************************************************************/
void interact(int gameBoard[][9][11], int tBoard[][9])
{
   displayCMD();
   displayBoard(gameBoard, tBoard);
   bool quit = false;
   char cmd;
   while (!(quit == true))
   {
      cout << '>';
      cin >> cmd;
	  if (cmd == '?')
         displayCMD();
      else if (cmd == 'D' || cmd == 'd')
         displayBoard(gameBoard, tBoard);
	  else if (cmd == 'E' || cmd == 'e')
         editBoard(gameBoard, tBoard);
	  else if (cmd == 'S' || cmd == 's')
         possibleVal(gameBoard);
	  else if (cmd == 'V' || cmd == 'v')
		  solve(gameBoard, tBoard);
	  else if (cmd == 'p' || cmd == 'P')
		  pid(gameBoard);
	  else if (cmd == 'Q' || cmd == 'q')
	  {
         saveFile(gameBoard);
		 break;
	  }
	  else
	  {
		  cout << "ERROR: Invalid command";
	  }

   }
   return;
}


/**********************************************************************
 * The driver function for the reading and output of the tic-tac-toe board
 ***********************************************************************/
int main()
{
   char fileName[256];
   int gameBoard[9][9][11]; //users game board
   int tBoard[9][9]; //test board, non-changed form origional for valid change
   getFileName(fileName, 0);
   readFile(fileName, gameBoard, tBoard);
   interact(gameBoard, tBoard);
   return 0;
}


