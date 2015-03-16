#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "gfx3.h"
 
//pi, thats it
double pi=3.14;
 
//function draws a 5 armed thing that is a snowflake part
void draw_star(int xcenter, int ycenter, int radius){
    double theta;
    for(theta=pi/2;theta<5*pi/2;theta+=2*pi/5){
        gfx_line(xcenter,ycenter,xcenter+radius*cos(theta),ycenter+radius*sin(theta));
        }
    }
 
//funcion draws a circle with a certain center and radius
void draw_circle(int xcenter, int ycenter, int radius){
    double theta;
    for(theta=0;theta<=2*pi;theta+=pi/100){
        gfx_line(xcenter+radius*cos(theta),
        ycenter+radius*sin(theta),
        xcenter+radius*cos(theta+pi/100),
        ycenter+radius*sin(theta+pi/100));
        }
    }
 
//function draws a triangle from 3 locations
void draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3){
    gfx_line(x1,y1,x2,y2);
    gfx_line(x2,y2,x3,y3);
    gfx_line(x3,y3,x1,y1);
    }
 
//function creates a square using a center and side length
void draw_square(int xcenter, int ycenter, int side){
    gfx_line(xcenter-side/2,ycenter-side/2,xcenter+side/2,ycenter-side/2);
    gfx_line(xcenter+side/2,ycenter-side/2,xcenter+side/2,ycenter+side/2);
    gfx_line(xcenter+side/2,ycenter+side/2,xcenter-side/2,ycenter+side/2);
    gfx_line(xcenter-side/2,ycenter+side/2,xcenter-side/2,ycenter-side/2);
    }
 
void sierpinski_triangle(int x1, int y1, int x2, int y2, int x3, int y3){
    // base case
    if(abs(x2-x1)<5) return;//if the distance between the corner of the traingle is below 5, return
 
    // drawing step
    draw_triangle(x1,y1,x2,y2,x3,y3);//draw a traingle with each corner location
 
    // recursive step
    //call function 3 times once for each new side created in triangle
    sierpinski_triangle(x1,y1,(x1+x2)/2,(y1+y2)/2,(x1+x3)/2,(y1+y3)/2);
    sierpinski_triangle((x1+x2)/2,(y1+y2)/2,x2,y2,(x2+x3)/2,(y2+y3)/2);
    sierpinski_triangle((x1+x3)/2,(y1+y3)/2,(x2+x3)/2,(y2+y3)/2,x3,y3);
    }
 
void shrinking_squares(int xcenter, int ycenter, int side){
    // base case
    if(side<5) return;//if side length of square is less than one then return
 
    // drawing step
    draw_square(xcenter,ycenter,side);//draws a square
 
    // recursive step
    // calls function 4 times, one for each shrinking square
    shrinking_squares(xcenter-side/2,ycenter-side/2,side/2);
    shrinking_squares(xcenter+side/2,ycenter-side/2,side/2);
    shrinking_squares(xcenter-side/2,ycenter+side/2,side/2);
    shrinking_squares(xcenter+side/2,ycenter+side/2,side/2);
    }
 
void spiral_squares(int side, int radius, double theta, int xspiralcenter, int yspiralcenter){
    // base case
    if(radius<1) return;//if radius of spiral is less than one then return
 
    // drawing step
    //sets up center for next square
    int xcenter=xspiralcenter+radius*cos(theta);
    int ycenter=yspiralcenter+radius*sin(theta);
    draw_square(xcenter,ycenter,side);//draws a square
 
    //recursive step
    //calls function again with smaller radius smaller square and pi/5 away
    spiral_squares(19*side/20,19*radius/20,theta+pi/5,xspiralcenter,yspiralcenter);
    }
 
void circular_lace(int xcenter, int ycenter, int radius){
    // base case
    if(radius<1) return;//if radius is less than one then return
 
    // drawing step
    draw_circle(xcenter,ycenter,radius);//draws a circle, that it.
 
    // recursive step
    //calls function 6 times spaced equally around the current circle
    circular_lace(xcenter+radius,ycenter,radius/3);
    circular_lace(xcenter+radius*cos(pi/3),ycenter+radius*sin(pi/3),radius/3);
    circular_lace(xcenter+radius*cos(2*pi/3),ycenter+radius*sin(2*pi/3),radius/3);
    circular_lace(xcenter+radius*cos(pi),ycenter+radius*sin(pi),radius/3);
    circular_lace(xcenter+radius*cos(4*pi/3),ycenter+radius*sin(4*pi/3),radius/3);
    circular_lace(xcenter+radius*cos(5*pi/3),ycenter+radius*sin(5*pi/3),radius/3);
    }
 
void snowflake(int xcenter, int ycenter, int radius){
    // base case
    //if radius of snowflake is less then one return
    if(radius<1) return;
 
    // drawing step
    //draws the 5 armed star looking thing that apparantly is a snowflake
    draw_star(xcenter,ycenter,radius);
 
    // recursive step
    //calls snowflake 5 times, one at the end of each arm
    snowflake(xcenter,ycenter+radius,radius/3);
    snowflake(xcenter+radius*cos(pi/2+2*pi/5),ycenter+radius*sin(pi/2+2*pi/5),radius/3);
    snowflake(xcenter+radius*cos(pi/2+4*pi/5),ycenter+radius*sin(pi/2+4*pi/5),radius/3);
    snowflake(xcenter+radius*cos(pi/2+6*pi/5),ycenter+radius*sin(pi/2+6*pi/5),radius/3);
    snowflake(xcenter+radius*cos(pi/2+8*pi/5),ycenter+radius*sin(pi/2+8*pi/5),radius/3);
    }
 
void tree(int xcenter, int ycenter, int length, double theta){
    // base case
    if(length<1) return;//if length of branch is less than 1 then return
 
    // drawing step
    //calculating the end of the branch
    int xend=xcenter+length*cos(theta);
    int yend=ycenter-length*sin(theta);
    //drawing branch calculated
    gfx_line(xcenter,ycenter,xend,yend);
 
    // recursive step
    //calls tree twice, one for each branch
    tree(xend,yend,2*length/3,theta-pi/6);
    tree(xend,yend,2*length/3,theta+pi/6);
    }
 
void fern(int xcenter, int ycenter, int length, double theta){
    // base case
    if(length<5) return;//if length of branch is less than 5 then return
 
    // drawing step
    //set up for the start point of each branch
    int xend1=xcenter+length*cos(theta);
    int yend1=ycenter-length*sin(theta);
    int xend2=xcenter+3*length/4*cos(theta);
    int yend2=ycenter-3*length/4*sin(theta);
    int xend3=xcenter+length/2*cos(theta);
    int yend3=ycenter-length/2*sin(theta);
    int xend4=xcenter+length/4*cos(theta);
    int yend4=ycenter-length/4*sin(theta);
    //drawing the branch
    gfx_line(xcenter,ycenter,xend1,yend1);
    gfx_line(xcenter,ycenter,xend2,yend2);
    gfx_line(xcenter,ycenter,xend3,yend3);
    gfx_line(xcenter,ycenter,xend4,yend4);
 
    // recursive step
    //call fern function eight times, one for each branch
    fern(xend1,yend1,length/3,theta-pi/6);
    fern(xend1,yend1,length/3,theta+pi/6);
    fern(xend2,yend2,length/3,theta-pi/6);
    fern(xend2,yend2,length/3,theta+pi/6);
    fern(xend3,yend3,length/3,theta-pi/6);
    fern(xend3,yend3,length/3,theta+pi/6);
    fern(xend4,yend4,length/3,theta-pi/6);
    fern(xend4,yend4,length/3,theta+pi/6);
    }
 
void spiral_of_spirals(int radius, double theta, int xcenter, int ycenter){
    // base case
    if(radius<1) return; //if radius is less then one then end
 
    //drawing step
    gfx_line(xcenter,ycenter,xcenter,ycenter);//draws a dot at the center of the next spiral
 
    // recursive step
    for(1;radius>1;radius=9*radius/10){//for loop that calls another spiral at each "dot" in the
        //current spiral
        spiral_of_spirals(35*radius/100,theta,xcenter+radius*cos(theta),ycenter+radius*sin(theta));
        theta+=pi/5;
        }
    }
 
int main(void){
    //setting up windowsize and switch statement variable
    int xsize=700;
    int ysize=700;
    char c;
 
    //opening window
    gfx_open(xsize,ysize,"fractal");
 
    //while loop that generates the fractals
    while(1){
        c=gfx_wait();
        gfx_clear();
 
        // switch statement set up for 1-8 and q
        switch(c){
 
            case 'q':
            return 0;
            break;
 
            case '1':
            sierpinski_triangle(0,0,xsize,0,xsize/2,ysize);
            break;
 
            case '2':
            shrinking_squares(xsize/2,ysize/2,xsize/2-50);
            break;
 
            case '3':
            spiral_squares(xsize/7,xsize/2-xsize/50,0,xsize/2,ysize/2);
            break;
 
            case '4':
            circular_lace(xsize/2,ysize/2,xsize/2-125);
            break;
 
            case '5':
            snowflake(xsize/2,ysize/2,xsize/2-125);
            break;
 
            case '6':
            tree(xsize/2, ysize-ysize/100, xsize/3,pi/2);
            break;
 
            case '7':
            fern(xsize/2,ysize-ysize/100,xsize/1.5,pi/2);
            break;
 
            case '8':
            spiral_of_spirals(xsize/1.5,0,xsize/2,ysize/2);
            break;
 
            }
        gfx_flush();
        }
    }
