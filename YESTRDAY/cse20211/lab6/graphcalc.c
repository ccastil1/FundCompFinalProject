//Celeste Castillo Lab 6 Part 1

#include <stdio.h>
#include "gfx2.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

float taylor(float, int);
double factorial(int);
char *num2str(int);
void axes(int);
void labels(int);

int main() {

char c, q;

double dx=0,dy=0,i =0, steps = 0, dummy, fact, l, y2, f, x, j, y, z;

double sum, k;

gfx_open(800,800, "Graph Calc");

	while (c!='q') {

		gfx_clear();

		axes(dummy);
		
		labels(dummy);

		if (c=='=')
		{
			steps++;
		}
		
		else if (c=='-')
		{
			if(steps > 1) {			
				steps--;
			}
		}

		
		for(k= -10, j=0; k<=10; j++, k+=0.1) {
	
		y = taylor(k, steps); 

		y2 = taylor(k+0.1, steps);

		gfx_color(255, 255, 255);

		gfx_line(30*k+400, 30*y+400, 30*(k+0.1)+400, 30*(y2)+400);
		
		}
	
		c = gfx_wait();
	
		if (c=='q') break;
	}
}

float taylor(float x, int steps)
{

	float sum = 0;
	int in, j;
		
		for(j=0,in=1; j<steps; in += 2, j++) {
			sum += (pow(-1, j) * pow(x, in))/factorial(in);
		}
		return sum;
	if (x >= 0) printf("Out of Taylor\n");
}

double factorial(int in)
{
		if(in<=1) return 1;
		else return in*factorial(in-1);
}

char *num2str(int n)
{
  static char a[4]; 
  sprintf(a, "%d", n);
  return (char *) a;
}


void axes(int dummy)
{
	int i=0, dy=0, dx=0;

	gfx_color(114,4,154);

	gfx_line(400,0,400,1000);

	gfx_line(0,400,1000,400);

	 for (i=0; i<=20; i++) {		//for loops for tick marks
		
		dy = dy + 40;

		gfx_line(395, dy, 405, dy);

	}
	
	for (i=0; i<=20; i++) {

		dx = dx + 40;

		gfx_line(dx,395, dx, 405);
	}
}
	
 void labels(int dummy)
{
	int dx=0, dy=0, i =0, l=0;
	
	for (i=0; i<=20; i++) {			//for loops for axis labels
		dx = dx + 36;
		gfx_text(dx, 420 , num2str(i-10));
	}

	for (l = 0; l<=20; l++) {
		dy = dy + 37;
		gfx_text(410, dy, num2str(10-l));
	}
	
}
