#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gfx3.h"
#include <time.h>

#define HEIGHT 800
#define WIDTH 800
#define pi M_PI

int main()
{





}

void fern(int xcenter, int ycenter, int length, double rho, int red, int green, int blue);
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
