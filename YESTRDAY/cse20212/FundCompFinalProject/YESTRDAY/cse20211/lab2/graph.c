#include <stdio.h>
#include <math.h>
int main ()
{  //Celeste Castillo CSE 20211 Lab 2
	double x, y, b, i, xmax, xmin, ymax, ymin; //declare the variables used
	
	printf("A plot of y = 25+(3*cos(x)) from x=0 to 35.0"); //display the plot function

	printf("\n    X\t  Y\n"); //format the columns for X and Y

	ymax = -100;
	ymin = 100;
	for (x=0; x<35; x+=0.5) //establish a for loop to plot the function 
	{
	   y = 25+(3*cos(x));
  	   printf("%5.2f ", x);
	   printf("%5.2f ", y);
		
		for(i=0; i<y; i+=0.5) //nested for loop to plot * for each y value
		  {
		   printf("*");	
	  	  }
	   	   printf("\n");
	  if (y >= ymax) {		//if, elseif, else statements to
		xmax=x;			//calculate max and min
		ymax=y;}
	  else if (y<=ymin) {
		xmin=x;
		ymin=y; }	
	 
	 else
		 (b=2);
	}
	   

	printf("The maximum of y=%2.2f was at x=%2.2f.\n", ymax, xmax); //display min and max
	printf("The minimum of y=%2.2f was at x=%2.2f.\n", ymin, xmin);
	  
}
