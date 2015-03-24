#include <stdio.h>
#include <math.h>
#include "gfx.h"
#include "gfx2.h"

void pole(int);

double rider(double dummy2);

int main() {

int dummy, ro=250, ri=80, slidercenterx=700, slidercentery=25, ht=2000,wd=2000;

char c, q;

double x1,y1, x2, y2,x3, y3, x4, y4, x5, y5, x6, y6,x7,y7,x8,y8, theta=0, rtot=100, dy=11,dt,dk,dl,theta2=0;

gfx_open(ht,wd, "slider");
dt = 1;
	while (c != 'q') {

		if (gfx_event_waiting()) {

			c = gfx_wait();
		}

		gfx_clear();

		pole(dummy);	
//slider
		gfx_line(600,dy, 800,dy);	

		gfx_line(600,dy, 600,dy+50);	

		gfx_line(600,dy+50, 800,dy+50);

		gfx_line(800,dy, 800,dy+50);

		slidercentery += dt;
		dy += dt;

		if (dy>600) {
			dt=-dt;}
		if (dy<10) {
			dt=-dt;}
			
//main axel		
		gfx_color(255,255,255);

		x1 = slidercenterx + -100*cos(theta2);

		y1 = slidercentery + -100*sin(theta2);

		x2 = x1 + 75*cos(theta);

		y2 = y1 + 75*sin(theta);
	
		gfx_line(slidercenterx,slidercentery, x1, y1); 


		x1 = slidercenterx + 100*cos(theta2);

		y1 = slidercentery + 100*sin(theta2);

		x2 = x1 + 75*cos(theta);

		y2 = y1 + 75*sin(theta);
	
		gfx_line(slidercenterx,slidercentery, x1, y1);

		theta2 += 0.2;


		x3 = slidercenterx + -ro*cos(theta);

		y3 = slidercentery + ro*sin(theta);

		x5 = x3 + 200*cos(theta);

		y5 = y3 + 200*sin(theta);
	
		gfx_line(slidercenterx,slidercentery, x3, y3); 


		x4 = slidercenterx + ro*cos(theta);

		y4 = slidercentery + -ro*sin(theta);

		x6 = x4 + 200*cos(theta);

		y6 = y4 + 200*sin(theta);

		gfx_line(slidercenterx,slidercentery, x4, y4);

		if (slidercentery > 600 && y4 > 600 && y3 > 600) {	
		dt = dt;
		dy=-dt;}

//spheres
		gfx_color(255,0,0);

		gfx_circle(x3, y3, 70);
	
		gfx_circle(x4, y4, 70);

		gfx_color(255,180,0);

		gfx_circle(x3, y3, 60);
	
		gfx_circle(x4, y4, 60);
	
		gfx_color(248,255,0);

		gfx_circle(x3, y3, 50);
	
		gfx_circle(x4, y4, 50);

		gfx_color(35,242,0);

		gfx_circle(x3, y3, 40);
	
		gfx_circle(x4, y4, 40);

		gfx_color(0,0,255);

		gfx_circle(x3, y3, 30);
	
		gfx_circle(x4, y4, 30);		

//axels
		gfx_color(255,255,255);

		gfx_line(x3,y3, x5,y5);

		gfx_line(x4,y4, x6,y6);

//cart
		gfx_color(220,0,255);

		gfx_line(x5,y5, x5,y5+40);

		gfx_line(x5,y5, x5-80,y5);

		gfx_line(x5,y5+40, x5-80,y5+40);

		gfx_line(x5-80,y5, x5-80,y5+40);
	

		gfx_line(x6,y6, x6,y6+40);

		gfx_line(x6,y6, x6-80,y6);

		gfx_line(x6,y6+40, x6-80,y6+40);

		gfx_line(x6-80,y6, x6-80,y6+40);


//riders
		gfx_color(255,0,0);

		gfx_line(x5-40,y5+20, x5-50,y5+40);	//legs

		gfx_line(x5-40,y5+20, x5-30,y5+40);

		gfx_line(x5-40,y5+20, x5-40,y5-25);	//body

		gfx_circle(x5-40,y5-35,10);		//head

		gfx_line(x5-40,y5-10, x5-20,y5-30);	//arms

		gfx_line(x5-40,y5-10, x5-60,y5-30);


		gfx_line(x6-40,y6+20, x6-50,y6+40);	//legs

		gfx_line(x6-40,y6+20, x6-30,y6+40);

		gfx_line(x6-40,y6+20, x6-40,y6-25);	//body

		gfx_circle(x6-40,y6-35,10);		//head

		gfx_line(x6-40,y6-10, x6-20,y6-30);	//arms

		gfx_line(x6-40,y6-10, x6-60,y6-30);

		theta+=0.05;
		
		gfx_flush();

		usleep(25000);
	}
}

void pole (int dummy)
{
	gfx_color(114, 4, 154);

	gfx_line(640,0, 640, 1000);

	gfx_line(760,0, 760, 1000);
}
