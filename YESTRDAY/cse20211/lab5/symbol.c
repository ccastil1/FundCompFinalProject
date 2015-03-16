#include <stdio.h>
#include "gfx.h"
#include <math.h>

int main ()
{

int width=6000, height=6000;

gfx_open(width,height,"Symbol");

double r=200/sqrt(3), a=(200*sqrt(3))/6;		//establishing the length and apothem from the center of an equilateral triangle to each vertex

double x1, y1, x2, y2;

int rd=50, i=0;						//radius of the polygon for the purposes of polar coordinates

float pi= 3.14159265358979323846260288, theta=0;

char c, t, q;

int x, y;

	while(1) {

		c = gfx_wait();
		
		if (c==1) {
			
			gfx_color(26, 0, 255);

			x = gfx_xpos();

			y = gfx_ypos();

			gfx_line(x+50, y+50, x+50, y-50);

			gfx_line(x+50, y+50, x-50, y+50);

			gfx_line(x-50, y+50, x-50, y-50);

			gfx_line(x-50, y-50, x+50, y-50);
		
			}

		if (c=='t') {		

			gfx_color(0,200,100);

			x = gfx_xpos();

			y = gfx_ypos();

			gfx_line(x, y+r, x-100, y-a);

			gfx_line(x-100, y-a, x+100, y-a);

			gfx_line(x+100, y-a, x, y+r); 
			
			}
	 
		if (c=='c') {
			
			gfx_color(255, 255, 255);

			x = gfx_xpos();
		
			y = gfx_ypos();

			gfx_circle(x, y, 50);
			}
		
		if (c=='3') {
	
			theta = 0;

			gfx_color(114, 4, 154);			//for a polygon with n sides, the angle between each is 2pi/n. this concept was used in a for loop so that one gfx_line could be called and used to draw a line at each needed angle 

			x = gfx_xpos();

			y = gfx_ypos();

			for(i=0; i<3; i++) {
		
				x1 = x+rd*cos(theta);
			
				y1 = y+rd*sin(theta);

				theta += (2*pi)/3;

				x2 = x+rd*cos(theta);
		
				y2 = y+rd*sin(theta);

				gfx_line(x1, y1, x2, y2); }


			}

		if (c=='4') {

			theta = 0;

			gfx_color(114, 4, 154);

			x = gfx_xpos();

			y = gfx_ypos();

			for(i=0; i<4; i++) {
		
				x1 = x+rd*cos(theta);
			
				y1 = y+rd*sin(theta);

				theta += (2*pi)/4;

				x2 = x+rd*cos(theta);
		
				y2 = y+rd*sin(theta);

				gfx_line(x1, y1, x2, y2); }

			}
		
	
		if (c=='5') {
				
			theta = 0;
			gfx_color(114, 4, 154);

			x = gfx_xpos();

			y = gfx_ypos();

			for(i=0; i<5; i++) {
		
				x1 = x+rd*cos(theta);
			
				y1 = y+rd*sin(theta);

				theta += (2*pi)/5;

				x2 = x+rd*cos(theta);
		
				y2 = y+rd*sin(theta);

				gfx_line(x1, y1, x2, y2); }
			
			}

		if (c=='6') {
			theta = 0;
			gfx_color(114, 4, 154);

			x = gfx_xpos();

			y = gfx_ypos();

			for(i=0; i<6; i++) {
		
				x1 = x+rd*cos(theta);
			
				y1 = y+rd*sin(theta);

				theta += (2*pi)/6;

				x2 = x+rd*cos(theta);
		
				y2 = y+rd*sin(theta);

				gfx_line(x1, y1, x2, y2); }

			}

		if (c=='7') {
			
			theta = 0;
			gfx_color(114, 4, 154);

			x = gfx_xpos();

			y = gfx_ypos();

			for(i=0; i<7; i++) {
		
				x1 = x+rd*cos(theta);
			
				y1 = y+rd*sin(theta);

				theta += (2*pi)/7;

				x2 = x+rd*cos(theta);
		
				y2 = y+rd*sin(theta);

				gfx_line(x1, y1, x2, y2); }


			}

		if (c=='8') {
			
			theta = 0;
			
			gfx_color(114, 4, 154);

			x = gfx_xpos();

			y = gfx_ypos();

			for(i=0; i<8; i++) {
		
				x1 = x+rd*cos(theta);
			
				y1 = y+rd*sin(theta);

				theta += (2*pi)/8;

				x2 = x+rd*cos(theta);
		
				y2 = y+rd*sin(theta);

				gfx_line(x1, y1, x2, y2); }

	

			}

		if (c=='9') {
			
			theta = 0;
			
			gfx_color(114, 4, 154);

			x = gfx_xpos();

			y = gfx_ypos();

			for(i=0; i<9; i++) {
		
				x1 = x+rd*cos(theta);
			
				y1 = y+rd*sin(theta);

				theta += (2*pi)/9;

				x2 = x+rd*cos(theta);
		
				y2 = y+rd*sin(theta);

				gfx_line(x1, y1, x2, y2); }

			}

		




		if (c=='q') break; {
		}	
	}
}

