	//Celeste Castillo Lab 4 Part 1: Simple Array

#include <stdio.h>
#include <math.h>
int main()
{
	double average=0;
	int n, avg[50], i=0;
	int grade;
	double total=0;
	double variance=0;
	double deviation=0;
	int test;
	int k = 3;

	while (1) {
		scanf("%i", &grade);
		if (grade == -1){		
			break;}
		avg[i] = grade;
		++i;
	}

	
	for(n=0; n < i; ++n)
	{
		total += avg[n];
		
	}

	average = total/n;

	for (n=0; n < i; n++)
	{
		variance = variance + pow((avg[n] - average), 2.0);	
	}

		variance = variance/ (n-1);
		deviation = sqrt(variance);
	printf("Average is: %0.2f\n", average);
	printf("Standard deviation is: %0.2f\n", deviation);

	return 0;
}

