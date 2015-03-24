#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "gfx3.h"

#define height 800
#define width 800
#define theta M_PI/3


void circular_lace(int x1, int y1, int r)


int main(){
    char c;
 
    gfx_open(height,width,"Fractals");
 
    while(1){
        c=gfx_wait();
        gfx_clear();
 
        switch(c){
 
            case 'q':
            return 0;
            break;
 
            case '1':
            sierpinski_triangle(0,0,height,0,height/2,width);
            break;
 
            case '2':
            shrinking_squares(height/2,width/2,height/2-50);
            break;
 
            case '3':
            spiral_squares(height/7,height/2-height/50,0,height/2,width/2);
            break;
 
            case '4':
            circular_lace(400,400,150);
            break;
 
            case '5':
            snowflake(height/2,width/2,height/2-125);
            break;
 
            case '6':
            tree(height/2, width-width/100, height/3,pi/2);
            break;
 
            case '7':
            fern(height/2,width-width/100,height/1.5,pi/2);
            break;
 
            case '8':
            spiral_of_spirals(height/1.5,0,height/2,width/2);
            break;
 
}
        gfx_flush();
}
}

void circular_lace(int x1, int y1, int r){
	if (abs(r)<5) return;

	gfx_circle(x1, y1, r);

	circular_lace(x1+r, y1, r/3);//0	
	circular_lace(x1+r*cos(theta), y1+r*sin(theta), r/3);//pi/3
	circular_lace(x1+r*cos(4*theta), y1+r*sin(2*theta), r/3);//2pi/3
	circular_lace(x1+r*cos(3*theta), y1+r*sin(3*theta), r/3);//4pi/3
 	circular_lace(x1+r*cos(4*theta), y1+r*sin(4*theta), r/3);//5pi/3
	circular_lace(x1+r*cos(5*theta), y1+r*sin(5*theta), r/3);//2pi
}}
