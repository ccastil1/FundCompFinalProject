// Celeste Castillo Lab 3 Prob3

#include <stdio.h>
#include <math.h>

double addxy(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double div(double x, double y);
int main ()
{

	double x, y;
	double addxy (double x, double y)
	{
		return x+y;
 	}

	double sub(double x, double y)
	{
		return x-y;
	}

	double mul(double x, double y)
	{
		return x*y;
	}

	double div(double x, double y)
	{
		return x/y;
	}

	double math;
	
		printf("Choose: 1 to Add, 2 to Subtract, 3 to Multiply, or 4 to Divide: ");
		scanf("%lf", &math);

		if(math == 1)
			{
			printf("Enter 2 numbers to add: ");
			scanf("%lf%lf", &x, &y);
		
			printf("%0.2lf + %0.2lf = %0.2lf", x, y, addxy(x, y));
			}

		else if (math == 2)
			{
			printf("Enter 2 numbers to subtract: ");
			scanf("%lf%lf", &x, &y);
	
			printf("%0.2lf - %0.2lf = %0.2lf", x, y, sub(x, y));
	 		}
		else if(math == 3)
			{
			printf("Enter 2 numbers to multiply: ");
			scanf("%lf%lf", &x, &y);

			printf("%0.2lf * %0.2lf = %0.2lf", x, y, mul(x, y));
			}
		else if (math == 4)
			{
			printf("Enter 2 numbers to divide: ");
			scanf("%lf%lf", &x, &y);

			printf("%0.2lf/%0.2lf = %0.2lf", x, y, div(x, y));
			}
}

		
