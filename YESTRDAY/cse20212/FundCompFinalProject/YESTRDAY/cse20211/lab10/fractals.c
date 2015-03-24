//Celeste Castillo Lab 10 Fractals

#include <stdio.h>
#include "gfx3.h"
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define theta M_PI/3
#define pi M_PI

void draw_square(int xcenter, int ycenter, int side)
{
    gfx_line(xcenter-side/2,ycenter-side/2,xcenter+side/2,ycenter-side/2);
    gfx_line(xcenter+side/2,ycenter-side/2,xcenter+side/2,ycenter+side/2);
    gfx_line(xcenter+side/2,ycenter+side/2,xcenter-side/2,ycenter+side/2);
    gfx_line(xcenter-side/2,ycenter+side/2,xcenter-side/2,ycenter-side/2);
}

void draw_snowflakeoutline(int xcenter, int ycenter, int radius)
{
    double theta5;
    for(theta5=pi/2;theta5<5*pi/2;theta5+=2*pi/5){
        gfx_line(xcenter,ycenter,xcenter+radius*cos(theta5),ycenter+radius*sin(theta5));
        }
}

void snowflake(int xcenter, int ycenter, int radius)
{
    // base case
    //if radius of snowflake is less then one return
    if(radius<1) return;
 
    // drawing step
    //draws the 5 armed star looking thing that apparantly is a snowflake
    draw_snowflakeoutline(xcenter,ycenter,radius);
 
    // recursive step
    //calls snowflake 5 times, one at the end of each arm
    snowflake(xcenter,ycenter+radius,radius/3);
    snowflake(xcenter+radius*cos(pi/2+2*pi/5),ycenter+radius*sin(pi/2+2*pi/5),radius/3);
    snowflake(xcenter+radius*cos(pi/2+4*pi/5),ycenter+radius*sin(pi/2+4*pi/5),radius/3);
    snowflake(xcenter+radius*cos(pi/2+6*pi/5),ycenter+radius*sin(pi/2+6*pi/5),radius/3);
    snowflake(xcenter+radius*cos(pi/2+8*pi/5),ycenter+radius*sin(pi/2+8*pi/5),radius/3);
}
 

 
void shrinking_squares(int xcenter, int ycenter, int side)
{
    // base case
    if(side<20) return;//if side length of square is less than one then return
 
    // drawing step
    draw_square(xcenter,ycenter,side);//draws a square
 
    // recursive step
    // calls function 4 times, one for each shrinking square
    shrinking_squares(xcenter-side/2,ycenter-side/2,side/2);
    shrinking_squares(xcenter+side/2,ycenter-side/2,side/2);
    shrinking_squares(xcenter-side/2,ycenter+side/2,side/2);
    shrinking_squares(xcenter+side/2,ycenter+side/2,side/2);
}


 
void spiral_squares(int side, int radius, double theta4, int xspiralcenter, int yspiralcenter)
{
    // base case
    if(radius<1) return;//if radius of spiral is less than one then return
 
    // drawing step
    //sets up center for next square
    int xcenter=xspiralcenter+radius*cos(theta4);
    int ycenter=yspiralcenter+radius*sin(theta4);
    draw_square(xcenter,ycenter,side);//draws a square
 
    //recursive step
    //calls function again with smaller radius smaller square and pi/5 away
    spiral_squares(19*side/20,19*radius/20,theta4+pi/5,xspiralcenter,yspiralcenter);
}

void spiral_of_spirals(int radius, double theta6, int xcenter, int ycenter)
{
    // base case
    if(radius<1) return;
 
    //drawing step
    gfx_line(xcenter,ycenter,xcenter,ycenter);//draws a dot at the center of the next spiral
 
    // recursive step
    for(1;radius>1;radius=9*radius/10)
	{//for loop that calls another spiral at each "dot" in the
        //current spiral
        	spiral_of_spirals(35*radius/100,theta6,xcenter+radius*cos(theta6),ycenter+radius*sin(theta6));
       		theta6+=pi/5;
        }
}



void sierpinski(int x1, int y1, int x2, int y2, int x3, int y3);

void circular_lace(int x1, int y1, int r);

void tree(int xcenter, int ycenter, int length, double theta2);

void fern(int xcenter, int ycenter, int length, double rho);


int main()
{
char c, q;

int x1, x2, x3, y1, y2, y3, x4, y4, r, w, h, length, radius, side;
float R;
double theta2, theta3, theta4, theta5, theta6, rho;


	gfx_open(HEIGHT,WIDTH, "Fractals");

	while(c != 'q')
	{
		c = gfx_wait();
	
		gfx_clear();
		if (c == '1'){		
			sierpinski(0,0,HEIGHT, 0, HEIGHT/2, WIDTH);
		}

		if (c == '2'){
			x1 = HEIGHT/2 - 250;
			y1 = WIDTH/2 -250;
			w = 450;
			h = 450;			
			//shrinking_squares(x1, y1, w, h);
			shrinking_squares(HEIGHT/2, WIDTH/2, HEIGHT/2-50);
		}

		if (c == '3'){

			spiral_squares(HEIGHT/7, HEIGHT/2 - HEIGHT/50, 0, HEIGHT/2, WIDTH/2);
		}

		if (c == '4'){

			circular_lace(400, 400, 150);
		}

		if (c == '5'){

			snowflake(HEIGHT/2, WIDTH/2, HEIGHT/2-150);
		}

		if (c == '6'){
		
			tree(HEIGHT/2, WIDTH- WIDTH/100, HEIGHT/3, M_PI/2);
		}

		if (c == '7'){

			fern(HEIGHT/2, WIDTH-WIDTH/100, HEIGHT/2, pi/2);
		}

		if (c == '8'){
		
	            spiral_of_spirals(HEIGHT/2,0,HEIGHT/2,WIDTH/2);
		}
		
		if (c == 'q') break;
	}

}

void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3)
{

   // Base case. 
   if( abs(x2-x1) < 2 ) return;

   // Draw the triangle
   gfx_triangle(x1,y1,x2,y2,x3,y3);

   // Recursive calls
   sierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
   sierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
   sierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
}


void tree(int xcenter, int ycenter, int length, double theta2)
{
    // base case
    if(length<1) return;//if length of branch is less than 1 then return
 
    // drawing step
    //calculating the end of the branch
    int xend=xcenter+length*cos(theta2);
    int yend=ycenter-length*sin(theta2);
    //drawing branch calculated
    gfx_line(xcenter,ycenter,xend,yend);
 
    // recursive step
    //calls tree twice, one for each branch
    tree(xend,yend,2*length/3,theta2-M_PI/6);
    tree(xend,yend,2*length/3,theta2+M_PI/6);
}


void circular_lace(int x1, int y1, int r)
{

	if (abs(r)<5) return;

	gfx_circle(x1, y1, r);

	circular_lace(x1+r, y1, r/3);//0	
	circular_lace(x1+r*cos(theta), y1+r*sin(theta)  , r/3);//pi/3
	circular_lace(x1+r*cos(4*theta), y1+r*sin(2*theta), r/3);//2pi/3
	circular_lace(x1+r*cos(3*theta), y1+r*sin(3*theta), r/3);//4pi/3
 	circular_lace(x1+r*cos(4*theta), y1+r*sin(4*theta), r/3);//5pi/3
	circular_lace(x1+r*cos(5*theta), y1+r*sin(5*theta), r/3);//2pi
}

void fern(int xcenter, int ycenter, int length, double rho)
{    // base case
    if(length<5) return;
 
    // drawing step
    //set up for the start point of each branch
    int xend1=xcenter+length*cos(rho);
    int yend1=ycenter-length*sin(rho);
    int xend2=xcenter+3*length/4*cos(rho);
    int yend2=ycenter-3*length/4*sin(rho);
    int xend3=xcenter+length/2*cos(rho);
    int yend3=ycenter-length/2*sin(rho);
    int xend4=xcenter+length/4*cos(rho);
    int yend4=ycenter-length/4*sin(rho);
   
	//drawing the branch
    gfx_line(xcenter,ycenter,xend1,yend1);
    gfx_line(xcenter,ycenter,xend2,yend2);
    gfx_line(xcenter,ycenter,xend3,yend3);
    gfx_line(xcenter,ycenter,xend4,yend4);
 
    // recursive step
    fern(xend1,yend1,length/3,rho-pi/6);
    fern(xend1,yend1,length/3,rho+pi/6);
    fern(xend2,yend2,length/3,rho-pi/6);
    fern(xend2,yend2,length/3,rho+pi/6);
    fern(xend3,yend3,length/3,rho-pi/6);
    fern(xend3,yend3,length/3,rho+pi/6);
    fern(xend4,yend4,length/3,rho-pi/6);
    fern(xend4,yend4,length/3,rho+pi/6);
}
