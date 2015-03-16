#include <stdio.h>
#include <math.h>
#include "gfx.h"
#include "gfx2.h"

void pole(int);

double slider(double dummy2);

int main() {

int dummy, ro=250, ri=80, slidercenterx=700, slidercentery;

char c, q;

double x1,y1, x2, y2,x3, y3, x4, y4, x5, y5, x6, y6, theta=0, theta2=0, rtot=100, dy,dt,dummy2;

	gfx_open(500,500, "slider");

	while (c != 'q') {

		if (gfx_event_waiting()) {

			c = gfx_wait();
		}

		gfx_clear();

		pole(dummy);	

		slider(dummy2);

	}
}

void pole (int dummy)
{
	gfx_clear();

	gfx_color(114, 4, 154);

	gfx_line(660,0, 660, 1000);

	gfx_line(740,0, 740, 1000);
}
			
double slider(double dummy2)
{
double ro=250, ri=80, slidercenterx=700, slidercentery;

char c, q;

double dy,dt;


		gfx_clear();

		gfx_line(600,dy, 800,dy);	

		gfx_line(600,dy, 600,dy+50);	

		gfx_line(600,dy+50, 800,dy+50);

		gfx_line(800,dy, 800,dy+50);

		dy += dt;

		dt = 1;

		if (dy> 400) {
			dt=-dt;}
	
		gfx_flush();

		usleep(25000);
		return dt;

}
