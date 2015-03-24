#include <stdio.h>
#include <math.h>
#include "gfx3.h"
#include <stdlib.h>
#include <time.h>
 
//PIE
double pi=3.14;
 
//function for drawing a tree
void tree(int xcenter, int ycenter, int length, double theta, int r, int g, int b){
        // base case
        if(length<1) return;//if length of branch is less than one then return
 
        // drawing step
    //calculate the ending position of current branch
        int xend=xcenter+length*cos(theta);
        int yend=ycenter-length*sin(theta);
    gfx_color(r,g,b);//decide color using a random r g and b
        gfx_line(xcenter,ycenter,xend,yend);//draw the branch
 
        // recursive step
    //converting theta into a 4 digit int so it can be easily used with rand()
    double pretheta0=theta*1000;
    int pretheta1=pretheta0;
 
    //generate a length for next branch between 3/4 and 1/4 of current length
    int finallength=rand()%(3*length/4-length/4+1)+(length/4);
    //generate a theta that is between 1 radian less than current theta and the current theta
    double pretheta2=rand()%(pretheta1-(pretheta1-1000)+1)+(pretheta1-1000);
    double endtheta=pretheta2/1000;//converts theta to usable number
    //generate random color value for R G and B
    r=rand()%255;
    g=rand()%255;
    b=rand()%255;
    //call tree at branch location with generated values
        tree(xend,yend,finallength,endtheta,r,g,b);
 
    //same process above except for theta, instead its between +1 and current theta
    finallength=rand()%(3*length/4-length/4+1)+(length/4);
    pretheta2=rand()%(pretheta1+1000-pretheta1+1)+pretheta1;
    endtheta=pretheta2/1000;
    r=rand()%255;
    g=rand()%255;
    b=rand()%255;
        tree(xend,yend,finallength,endtheta,r,g,b);
        }
 
 
int main(void)
    {
    //setting up window size and declaring variables for future use
    int xsize=700;
    int ysize=700;
    int length;
    double theta;
    int r;
    int g;
    int b;
    int n;
    char c;
 
    // open window
    gfx_open(xsize,ysize,"gallery of trees");
 
    //seed random with system clock so that its different every time it is ran
    srand(time(NULL));
 
    //while loop that creates the trees
    while(1){
        gfx_clear();//clear window
        //for loop that creates 16 trees equally spaced on xaxis
        for(n=1;n<=16;n++){
            //random starting length and color generated for each tree
            length=rand()%(xsize/2-25+1)+25;
            r=rand()%255;
            g=rand()%255;
            b=rand()%255;
            tree(n*xsize/17,ysize,length,pi/2,r,g,b);
 
            //make sure q was not pressed in between trees
            if(gfx_event_waiting()==1){
                c=gfx_wait();
                if(c=='q') return 0;
                }
 
            }
        //wait till something is pressed, if q is not pressed then redraw another 16 trees
        c=gfx_wait();
        if(c=='q') return 0;
        gfx_flush();
        }
    }
