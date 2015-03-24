#include <stdio.h>
#include <math.h>
#include "gfx.h"

int main()
{
	gfx_open(600,600,"person");

	double x1, x2, y1, y2;

	int rd = 50, i=0;

	float theta = 0;

	double r=200/sqrt(3), a = (200*sqrt(3))/6;

	int x, y;

	char p, c, q;

	while (1) {
		
		c = gfx_wait();

		if (c=='p') {
		
			gfx_color(0,200,100);

			x = gfx_xpos();

			y = gfx_ypos();

			gfx_line(x, y+r, x-100, y-a);

			gfx_line(x-100, y-a, x+100, y-a);

			gfx_line(x+100, y-a, x, y+r);
		

 			}


		

		if(c=='q') break; {}
}
}
