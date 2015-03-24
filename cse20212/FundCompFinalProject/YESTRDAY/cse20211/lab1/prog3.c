#include <stdio.h>
int main ()
{
 	float velocity;
	float acceleration;
	float time;
	float distance1;
	float distance2;
	float totaldistance;

	printf("Enter the initial velocity of the object:\n");
	scanf("%f", &velocity);

	printf("Enter the acceleration of the object:\n");
        scanf("%f", &acceleration); 

	printf("Enter the time  of the object's journey:\n");
        scanf("%f", &time);

	distance1 = velocity * time;

	distance2 = 0.5 * acceleration * time * time;

	totaldistance = ( distance1 + distance2);
	printf("The distance the object travelled is %f\n", totaldistance);
}
