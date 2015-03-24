//Celeste Castillo Lab 3 Prob2

#include <stdio.h>
#include <math.h>

float mag(float x, float y);
float theta(float x, float y);

int main ()
{	
	float x, y;
	printf("Enter the point in Cartesian coordinates: ");
	scanf("%f %f", &x, &y);
	
	float r = mag(x, y);

	float t = theta(x,y);
	
	printf("The point in polar coordinates is: (%f, %f)", r, t);
	
	int quad;
		if(x>0 && y>0)
		{
			quad = 1;
			printf("The point is in quadrant 1.\n");
		}

		else if (x<0 && y>0)
		{
			quad = 2;
			printf("The point is in quadrant 2.\n");
		}
		else if (x<0 && y<0)
		{
			quad = 3;
			printf("The point is in quadrant 3.\n");
		}
		else if (x>0 && y<0)
		{
			quad = 4;
			printf("The point is in quadrant 4.\n");
		}
		else if (x==0 && y==0)
		{
			quad = 0;
			printf("The point is on the axis.");
		}

}
	float mag(float x, float y)
	{
		float mag;
		mag = sqrt(x * x + y * y);
		return mag;
	}
	

	float theta(float x, float y)
	{
		float theta;
		theta = atan(y/x)* 180/3.14;
		return theta;
	}
