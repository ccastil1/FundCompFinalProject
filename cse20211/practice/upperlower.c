#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {

int i, j, k, l;

char string[30];

printf("Enter a string: ");
fgets(string, 30, stdin);

	for (i=0; i< strlen(string); i++)
	{
		if (isspace(string[i]))
		{
			if(j==0)
			{	
				j = 1;
			}
			else if(j == 1)
			{
				j = 0;
			}
		}
		else
		{
			if (j == 1)
			{
				string[i] = toupper(string[i]);
			}
			if (j == 0)
			{
				string[i] = tolower(string[i]);
			}
		}
	}
	printf("%s\n", string);
}
