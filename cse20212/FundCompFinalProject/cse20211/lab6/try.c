#include <stdio.h>
#include <math.h>
#include "gfx.h"
#include "gfx2.h"

void pole(int);

double rider(double dummy2);

int main() {

int dummy, ro=250, ri=80, slidercenterx=700, slidercentery=500, ht=2000,wd=2000;

char c, q;

double x1,y1, x2, y2,x3, y3, x4, y4, x5, y5, x6, y6, theta=0, rtot=100, dy=0,dt,dummy2,dk;

	gfx_open(ht,wd, "slider");
dt =1;
	while (c != 'q') {

		if (gfx_event_waiting()) {

			c = gfx_wait();
		}

		gfx_clear();

//slider
		gfx_line(600,dy, 800,dy);	

		gfx_line(600,dy, 600,dy+50);	

		gfx_line(600,dy+50, 800,dy+50);

		gfx_line(800,dy, 800,dy+50);

//		slidercentery = dt+15;

		dy += dt;

		if (dy>400) {
			dt=-dt;}
		if (dy<60) {
			dt=-dt;}

		gfx_flush();

		usleep(25000);


	}
}

