#include <stdio.h>
int main ()
{
   int x, y, i, j; //declare the variables x and y
		   //as the dimensions of the table;
	  	   // i and j are for the iterations 

     printf("Enter the X:\n");
     scanf("%d", &x);
	
     printf("Enter the Y:\n");
     scanf("%d", &y);

	printf(" * ");
	for(j = 1; j <= x; ++j)
		printf("%3d", j);
		printf("\n");
	for(i = 1; i <=y; ++i)
		{
			printf("%3d", i);
		for(j = 1; j <= x; ++j)
			printf(" %2d", i * j);
			printf("\n");
		}
}
