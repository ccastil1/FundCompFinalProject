#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main (){

int i, j, k, l;

int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	for (i=0; i<10; i++)
	{
		for (j=0; j<10 - i - 1; j++)
		{
			if(a[j] < a[j+1])
			{
				k = a[j];
				a[j] = a[j+1];
				a[j+1] = k;
			}
		}
	}
	for(i=0; i < 10; i++)
	{
		printf("%d\t", a[i]);
	}
}
