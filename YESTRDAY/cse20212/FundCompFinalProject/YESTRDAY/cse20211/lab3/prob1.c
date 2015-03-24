//Celeste Castillo Lab 3 Prob1


#include <stdio.h>
int main ()
{
	int x,y;
	
	printf("Enter 2 numbers: ");
	scanf("%i%i", &x, &y);

		printf("The greatest common divisor of %i and %i is %i.", x, y, getgcd(x,y));
}
	int getgcd(long x, long y)
	  	{
			if(y==0)
			   return x;
			else
			   return getgcd(y, x%y);
		}
