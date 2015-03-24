#include <stdio.h>
#include <math.h>
#include "gfx.h"
#include "gfx2.h"

int main(){

char c, q;

int dummy;

double x1,y2,dy;

gfx_open(200,200,"up");

	while (c != 'q') {

		if (gfx_event_waiting()) {

			c = gfx_wait();
		}
  		
		gfx_circle(470,dy,15);

		dy+=0.02
	}
}
