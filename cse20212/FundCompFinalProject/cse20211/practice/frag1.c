#include<stdio.h>

int main() {

int r = 10, s=20, t=30;
int *x=&r, *y=&t;
int **p=&x;

printf("%d %d %d\n", *y,*x,**p);

x = &s;
*y=40;
**p = 50;

printf("%d %d %d\n", r,s,t);
}
