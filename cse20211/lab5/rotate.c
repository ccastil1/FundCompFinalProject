//Celeste Castillo Lab 5 Part 3

#include <stdio.h>
#include <math.h>
#include "gfx.h"

int main() {

	gfx_open(6000,6000,"rotate");

	int x, y,ri=16, ro=40, i=0;

	float theta=0;

	double x1, x2, y1, y2;

	char c, q, s, g, f;		

	printf("Press 'f' to make the yo-yo spin faster\n");

	printf("Press 's' to make the yo-yo spin faster\n");

	printf("Press 'g' to make the yo-yo blink green\n");

	printf("Press '2' to make two yo-yos\n");
	
	while(1) {

		if (gfx_event_waiting()) {

			c = gfx_wait();
		}

		x = gfx_xpos();

		y = gfx_ypos();

		gfx_clear();		
		
		gfx_color(114, 4, 154);			

		gfx_clear();

		gfx_line(400,450, 400,300);

		gfx_circle(400,260,40);

		gfx_line(400,375, 470,310); 		//*

		gfx_line(400,375, 340,310);
	
		gfx_line(400,450, 350,485);
		
		gfx_line(400,450, 460, 485);

		x2 = 460 + ro*cos(theta);

		y2 = 310 + ro*sin(theta);

		gfx_color(26, 0, 255);

		gfx_circle(x2, y2, ri);

		gfx_line(470,310, x2, y2); 

		theta+=0.05;
	
		gfx_flush();

		usleep(20000);

		if (c=='g') {

			x = gfx_xpos();

			y = gfx_ypos();

			gfx_clear();		
		
			gfx_color(114, 4, 154);			

			gfx_clear();

			gfx_line(400,450, 400,300);

			gfx_circle(400,260,40);

			gfx_line(400,375, 470,310); 		//*

			gfx_line(400,375, 340,310);
	
			gfx_line(400,450, 350,485);
		
			gfx_line(400,450, 460, 485);

			x2 = 460 + ro*cos(theta);

			y2 = 310 + ro*sin(theta);

			gfx_color(0, 255, 0);

			gfx_circle(x2, y2, ri);

			gfx_line(470,310, x2, y2); 

			theta+=0.05;
	
			gfx_flush();

			usleep(20000);
		}

		if (c=='f') {

			x = gfx_xpos();

			y = gfx_ypos();

			gfx_clear();		
		
			gfx_color(114, 4, 154);			

			gfx_clear();

			gfx_line(400,450, 400,300);

			gfx_circle(400,260,40);

			gfx_line(400,375, 470,310); 		//*

			gfx_line(400,375, 340,310);
	
			gfx_line(400,450, 350,485);
		
			gfx_line(400,450, 460, 485);

			x2 = 460 + ro*cos(theta);

			y2 = 310 + ro*sin(theta);

			gfx_color(26, 0, 255);

			gfx_circle(x2, y2, ri);

			gfx_line(470,310, x2, y2); 

			theta+=0.05;
	
			gfx_flush();

			usleep(2000);
		}

		if (c=='s') {

			x = gfx_xpos();

			y = gfx_ypos();

			gfx_clear();		
		
			gfx_color(114, 4, 154);			

			gfx_clear();

			gfx_line(400,450, 400,300);

			gfx_circle(400,260,40);

			gfx_line(400,375, 470,310); 		//*

			gfx_line(400,375, 340,310);
	
			gfx_line(400,450, 350,485);
		
			gfx_line(400,450, 460, 485);

			x2 = 460 + ro*cos(theta);

			y2 = 310 + ro*sin(theta);

			gfx_color(26, 0, 255);

			gfx_circle(x2, y2, ri);

			gfx_line(470,310, x2, y2); 

			theta+=0.05;
	
			gfx_flush();

			usleep(200000);
		}

		if (c=='2') {
		
			x = gfx_xpos();

			y = gfx_ypos();

			gfx_clear();		
		
			gfx_color(114, 4, 154);			

			gfx_clear();

			gfx_line(400,450, 400,300);

			gfx_circle(400,260,40);

			gfx_line(400,375, 470,310); 		//*

			gfx_line(400,375, 340,310);
	
			gfx_line(400,450, 350,485);
		
			gfx_line(400,450, 460, 485);

			x2 = 340 + ro*cos(theta);

			y2 = 310 + ro*sin(theta);

			gfx_color(26, 0, 255);

			gfx_circle(x2, y2, ri);

			gfx_line(340,310, x2, y2); 

			gfx_circle(x2,y2,ri);

			gfx_line(340,310, x2, y2);

			theta+=0.05;
	
			gfx_flush();

			usleep(25000);
		}
		if (c=='q') break;
	}
}


