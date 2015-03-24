#include <stdio.h>
#include "gfx.h"
#include <math.h>

int square(int AB, int BC, int CD, int AD);


int main ()
{

int width=600, height=600;

gfx_open(width,height,"Symbol");



char c, t, q;

int r, x, y, AB, BC, CD, AD;

	while(1) {

                c = gfx_wait();

                if (c==1) {

                        gfx_color(26, 0, 255);

			square(AB, AD, BC, CD)		

                        }
}}


	int square(int AB, int AD, int DC, int BC) {

(void)	int x = gfx_xpos();

(void)	int y = gfx_ypos();

(void)	int r = 50;

(void)	AB = gfx_line(x-r, y+r, x+r, y+r);

(void)	AD = gfx_line(x-r, y-r, x-r, y+r);
	
(void)	DC = gfx_line(x-r, y-r, x+r, y-r);

(void)	BC = gfx_line(x+r, y+r, x+r, y-r);

(void)	return square;
	}
