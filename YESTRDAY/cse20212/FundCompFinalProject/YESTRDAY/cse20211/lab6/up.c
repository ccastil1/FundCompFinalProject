#include <stdio.h>
#include <math.h>
#include "gfx.h"
#include "gfx2.h"

int main(){

char c, q;

int dummy;

double x1,y2,dy=0,dz;

gfx_open(500,500,"up");

dy = 1;
	while (c != 'q') {

		if (gfx_event_waiting()) {

			c = gfx_wait();
		}
  		
		gfx_clear();

		gfx_circle(250,dy,50);

		dy+=dz;

		if (dy>500-50) {

			dz=-dz;
		}

		if(c=='q') break;
		
		gfx_flush();

		usleep(2000);

	}
}
