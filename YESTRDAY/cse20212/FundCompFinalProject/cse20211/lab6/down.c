#include <stdio.h>
#include <math.h> 
#include "gfx2.h"

int main(){

char c, q;

double dummy;

double x1,y2,dy, x, y, dz,dx;

int wd=700, ht=700, r=50;

gfx_open(wd, ht, "up");
dy = 1;
y=1;
	while (c != 'q') {

		if (gfx_event_waiting()) {

			c = gfx_wait();
		}
		
  		gfx_clear();
    
		gfx_color(26, 0, 255);    		

    	//	if (y>ht-r){
	//		dy =-dy; }
		if (y<r) {		
			y =-dy;}

    		gfx_circle(250,y,r);
    		y+=dy;
  	  	usleep(2000);
  	  	gfx_flush;
  	 	
		if (c=='q') break;

	}
}
