#include <stdio.h>
#include "gfx3.h"

#define HEIGHT 800
#define WIDTH 800

void maze(dummy);w

int main()
{
	char c;
	int dummy;
	
	gfx_open(HEIGHT, WIDTH, "Pac-Man");

	while(c!='q')
	{
		c = gfx_wait();
	
		gfx_clear();

		switch(c)
		{
			case 'q':
			return 0;
			break;

			case '1':
				maze(dummy);
				break;
		}

	}
}

void maze(dummy)
{
	gfx_color(0, 0, 255);
	gfx_fill_rectangle(0, 0, HEIGHT, WIDTH);
	gfx_color(0,0,0);
	gfx_fill_rectangle(10, 10, HEIGHT-20, WIDTH-20);
	
}
