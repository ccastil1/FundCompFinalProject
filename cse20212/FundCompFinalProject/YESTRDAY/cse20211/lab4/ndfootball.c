#include<stdio.h>
int wins[] = 
 { 6, 8, 6, 8, 5, 5, 6, 6, 8, 7, 4,
   6, 7, 7, 6, 7, 8, 6, 3, 9, 9, 10,
   8, 9, 10, 7, 9, 7, 5, 9, 10, 6, 6,
   3, 6, 7, 6, 6, 8, 7, 7, 8, 7, 9,
   8, 7, 8, 9, 9, 10, 4, 7, 7, 9, 9,
   8, 2, 7, 6, 5, 2, 5, 5, 2, 9, 7,
   9, 8, 7, 8, 10, 8, 8, 11, 10, 8, 9,
   11, 9, 7, 9, 5, 6, 7, 7, 5, 5, 8,
   12, 12, 9, 10, 10, 11, 6, 9, 8, 7, 9,
   5, 9, 5, 10, 5, 6, 9, 10, 3, 7, 6,
   8, 8, 12, 9 };

int losses[] = 
 { 3, 1, 2, 0, 3, 4, 1, 0, 1, 0, 1,
   0, 0, 0, 2, 1, 1, 1, 1, 0, 0, 1,
   1, 1, 0, 2, 1, 1, 4, 0, 0, 2, 2,
   5, 3, 1, 2, 2, 1, 2, 2, 0, 2, 1,
   2, 2, 0, 0, 0, 0, 4, 2, 2, 0, 1,
   2, 8, 3, 4, 5, 8, 5, 5, 7, 1, 2,
   0, 2, 2, 2, 1, 2, 3, 0, 2, 3, 3,
   1, 3, 4, 2, 6, 4, 5, 5, 6, 6, 4,
   0, 1, 3, 3, 1, 1, 5, 3, 3, 6, 3,
   7, 3, 6, 3, 7, 6, 3, 3, 9, 6, 6,
   5, 5, 1, 4 };

int main()
{
 double question1(double x, double y);
 double question2(double x, double y);
 double question3(double x, double y);

 int elements1;
 int elements2;
 int frequency=0;
 int total=0;
 int i=0;
 int sum=0;
 int use;
 int year;
 double question;

 elements1 = sizeof(wins)/sizeof(int);
 elements2 = sizeof(losses)/sizeof(int);



	printf(" 1. Display the number of wins in a given year.\n 2. Display the number of loses in a given year.\n 3. Display if the Irish had a winning or losing record in a given year.\n 4. Display the total number of games the Irish have won.\n 5. Display the total number of games the Irish have lost.\n 6. Display the number of years the Irish were undefeated.\n Enter the number of the question you choose:  ");
	scanf("%lf", &question);
	
	if (question == 1)
		{
			printf("Enter the year: ");
			scanf("%i", &year);
			
			use = year-1900;
			
			printf("The Irish won %i games in %i.", wins[use], year);
		}
	if (question == 2)
		{
			printf("Enter the year: ");
			scanf("%i", &year);

			use = year-1900;

			printf("The Irish lost %i games in %i.", losses[use], year);
		}
	if (question == 3)
		{
			printf("Enter the year: ");
			scanf("%i", &year);

			use = year-1900;
			
			if (wins[use] > losses[use])
				{
					printf("The Irish had a winning season in %i.\n", year);
				}		
			else
				{
					printf("The Irish did not have a winning season in %i.\n", year);
				}

		}

	if (question == 4)
		{
			for(i=0; i < elements1; ++i)
				{
					sum += wins[i];
				}
			printf("The Irish have won a total of %i games.\n", sum);	
		}
	
	if (question == 5)
		{
			for(i=0; i < elements2; ++i)
				{
					total += losses[i];
				}
			printf("The Irish have lost a total of %i games.\n", total);
		}
	if (question == 6)
		{
			for(i=0; i < elements2; ++i)
				{
					if(losses[i]==0)
						{
							frequency = frequency + 1;
						}
					else
						{
							frequency = frequency;
						}
				}
					printf("The Irish have been undefeated %i seasons.\n", frequency);
		}	
}	
