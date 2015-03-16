#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void display(int board[40][40]);

void generation(int board[40][40]);

void second(int board[40][40]);

void newcell(int x, int y, int board[40][40]);

void deletecell(int x, int y, int board[40][40]);


int main(int argc, char const *argv[])
{
	FILE *ifp;
	
	ifp = fopen(argv[1], "r");

	int x, y, board[40][40] = {0};

	char choice;

	display(board);

	if(ifp)
	{
		while(!feof(ifp))
		{
			fscanf(ifp, " %c", &choice);
			
			if(choice == 'a')
			{
				fscanf(ifp, " %d %d", &x, &y);
				newcell(x,y,board);
			}
			
			if(choice == 'r')
			{
				fscanf(ifp, " %d %d", &x, &y);
				deletecell(x,y,board);
			}
			
			if(choice == 'n')
			{
				generation(board);
			}
			
			if(choice == 'q')
			{
				break;
			}
			
			if(choice == 'p')
			{
				while(1)
				{
					generation(board);
					display(board);
					usleep(1000000/30);
					system("clear");
				}
			}
		}
		
		display(board);	
	}

	else if(!ifp)
	{
	while(1)
	{
	
		 printf("Enter 'a' to add a new live cell; 'r' to remove a cell; 'n' to advance the simulation to the next iteration;'q' to quit the program; or 'p' to play the game continuously.\n");

		printf("Enter your choice: ");
		scanf("%c", &choice);

		if(choice == 'a')
		{
		        printf("Enter coordinates for the new cell: ");
		        scanf("%d %d", &x, &y);

		        newcell(x, y, board);
			display(board);
		}

		if(choice == 'r')
		{
		        printf("Enter coordinates of the cell to remove: ");
		        scanf("%d %d", &x, &y);

		        deletecell(x, y, board);
			display(board);

		}

		if(choice == 'n')
		{

		        generation(board);

		}

		if(choice == 'q')
		{
		        printf("Goodbye!");

		}

		if(choice == 'p')
		{
		        while(1)
		        {
		                generation(board);
		                display(board);
		                usleep(1000000/20);
		                system("clear");
		        }
		}
	}
}
}

void display(int board[40][40])
{
	int x,y;

	char displayboard[40][40];
	
	for(x=0; x <40; x++)
	{
		for(y=0; y<40; y++)
		{
			if(board[y][x]==0)
			{
				displayboard[y][x] = '.';
			}
			else if(board[y][x]==1)
			{
				displayboard[y][x] = 'x';
			}
			
			printf("%c", displayboard[y][x]);
		}
			
		printf("\n");
		
	}
		
	printf("\n");
}

void generation(int board[40][40])
{
	int x, y, spot=0;
	int secondboard[40][40]={0};
	
	for(x=0; x<40; x++)
	{
		for(y=0; y<40; y++)
		{
			spot = nextto(x, y, board);
			
			if(board[x][y]==1)
			{
				if (spot<2)
				{
					secondboard[x][y]=0;
				}
				else if(spot>3)
				{
					secondboard[x][y]=0;
				}
				else
				{
					secondboard[x][y]=1;
				}
			}
		else if(board[x][y]==0)
		{
			if(spot == 3)
			{
				secondboard[x][y]=0;
			}
			else
			{
				secondboard[x][y]=1;
			}

		}
		}
	}
	
	for(x=0; x<40; x++)
	{
		for(y=0; y<40; y++)
		{
			board[x][y] = secondboard[x][y];
		}
	}
}

int nextto(int x, int y, int board[40][40])
{
	int i = 0;

	if(board[x-1][y] == 1)
	{
		i++;
	}

	if(board[x+1][y] == 1)
	{
		i++;
	}

	if(board[x+1][y-1] == 1)
	{
		i++;
	}

	if(board[x-1][y+1] == 1)
	{
		i++;
	}

	if(board[x-1][y] == 1)
	{
		i++;
	}
	
	if(board[x+1][y+1] == 1)
	{
		i++;
	}

	if(board[x-1][y-1] == 1)
	{
		i++;
	}

	if(board[x][y-1] == 1)
	{
		i++;
	}

	if(board[x][y+1] == 1)
	{
		i++;
	}

	return i;
}

void newcell(int x, int y, int board[40][40])
{
	board[x][y] = 1;
}

void deletecell(int x, int y, int board[40][40])
{
	board[x][y] = 0;
}

