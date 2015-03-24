#include <stdio.h>
#include <math.h>
#include "gfx.h"
#include "gfx2.h"

void pole(int);

void slider(int);

double stick(double dummy2);

int main() {

int dummy, ro=250, ri=80, slidercenterx=700, slidercentery;

char c, q;

double x1,y1, x2, y2,x3, y3, x4, y4, x5, y5, x6, y6, theta=0, rtot=100, dy,dt,dummy2;

	gfx_open(2000,2000, "slider");

	while (c != 'q') {

		if (gfx_event_waiting()) {

			c = gfx_wait();
		}

//		pole(dummy);	

		stick(dummy2);	
	}
}


void pole (int dummy)
{
	gfx_clear();

	gfx_color(114, 4, 154);

	gfx_line(660,0, 660, 1000);

	gfx_line(740,0, 740, 1000);
}

double stick(double dummy2)
{

int dummy, ro=250, ri=80, slidercenterx=700, slidercentery=500;

double x1,y1, x2, y2,x3, y3, x4, y4, x5, y5, x6, y6, theta=0, rtot=100, dy,dt;

		x3 = slidercenterx + -ro*cos(theta);

		y3 = slidercentery + ro*sin(theta);

		x5 = x3 + 150*cos(theta);

		y5 = y3 + 150*sin(theta);
	
		gfx_line(slidercenterx,slidercentery, x3, y3); 


		x4 = slidercenterx + ro*cos(theta);

		y4 = slidercentery + -ro*sin(theta);

		x6 = x4 + 150*cos(theta);

		y6 = y4 + 150*sin(theta);

		gfx_line(slidercenterx,slidercentery, x4, y4);

		return theta;
}

