#include <stdio.h>
#inclide <math.h>

int main ()
{
	float x,y;
	
	for(x=-3; x<=3; x+=1){
	y = sin(x);
	printf("%.2f\t%.2f\n", x, y);
	}
}
