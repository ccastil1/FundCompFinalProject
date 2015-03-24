//Celeste Castillo Lab 5 Bounce

#include <stdio.h>
#include "gfx.h"
#include <time.h>

int main()
{
  int wd=1000;  
  int ht=1000;  
  char c=1;
  time_t t;
  srand(time(&t));
  int r = 10;
  int x, y;
  int dx = rand()%5;
  int dy = rand()%5;

  gfx_open(wd, ht, "bounce");

  gfx_color(0,255,0);	  

	while (c!='q') { 
    
  		gfx_clear();
    
		gfx_color(26, 0, 255);

   		if (x <r) {
			dx = -dx;}
    		else if (x>wd+r){
			dx = -dx;}
    		else if (y>wd-r){
			dy=-dy;}
    		else if (y>ht-r){
			dy =-dy; }
		else if (y<r) {
			dy =-dy;}

    		gfx_circle(x,y,r);
    		x+=dx;
    		y+=dy;
  	  	usleep(2000);
  	  	gfx_flush;
  	 	

		if(gfx_event_waiting()) {
     		 	c = gfx_wait();
     		 if (c == 1) {
    	  		dx = rand()%5;
    	  		dy = rand()%5;
    	  		x = gfx_xpos();
    	  		y = gfx_ypos();
    			 }	
    		}
	}
}

