#include <stdio.h>
#include <math.h>
#include "gfx.h"
#include "gfx2.h"

void pole(int);

void slider(int);

void lines(int);

int main() {

int dummy;

double x2,y2, theta=0, ro=100, ri=10, R = sqrt(1800);

char c, q;

	gfx_open(1000,1000, "Carnival");

	while (c != 'q') {

		pole(dummy);

		slider(dummy);

		lines(dummy);

		c = gfx_wait();

	gfx_line(470,500, )




		if (c == 'q') break;
	}
}

void pole(int dummy)
{
	gfx_line(480,0, 480,1000);
	
	gfx_line(520,0, 520,1000);
}

void slider(int dummy)
{

	gfx_line(470,500, 530,500);	

	gfx_line(470,500, 470,560);	

	gfx_line(470,560, 530,560);

	gfx_line(530,500, 530,560);	

}

void lines(int dummy)
{
	double x2,y2;

	float theta=0;

	int ro=100,ri=30;

	x2 = 460 + ro*cos(theta);

	y2 = 310 + ro*sin(theta);

	gfx_color(26, 0, 255);

	gfx_circle(x2, y2, ri);

	gfx_line(470,560, x2, y2); 

	theta+=0.05;
	
	gfx_flush();

	usleep(20000);
}

void wha(int dummy)
{
	gfx_line(470,560, 100,100);	//bottomleft

	gfx_line(530,560, 590,620);	//bottomright

	gfx_line(470,500, 410,440);

	gfx_line(530,500, 590,440);

}

void rectangles(dummy)
{
	gfx_line(560,650, 760,650); 

	gfx_line(760,650, 760,700);	

	gfx_line(560,700, 760,700);

	gfx_line(560,650, 560,700);


	gfx_line(440,650, 240,650); 

	gfx_line(240,650, 240,700);	

	gfx_line(240,700, 440,700);

	gfx_line(440,650, 440,700);	
	
	gfx_line(760,700, 800,740);
}

