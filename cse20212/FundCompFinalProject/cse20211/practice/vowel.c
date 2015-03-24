#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {

int i, j=0, k;

char string[30];

printf("Enter a string: ");
scanf("%s", string);

	for(i=0; i<strlen(string); i++)
	{
		if(string[i]=='a' || string[i]=='e' || string[i]=='i' || string[i]=='o' || string[i]=='u' || string[i]=='y')
		{
			j++;
		}
	}
	
	printf("the number of vowels is: %d\n", j);
	
}
