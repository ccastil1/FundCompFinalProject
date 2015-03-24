#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {

int i=0, j=0, k=0, l=0;

char string1[30];
char string2[30];

printf("Enter two strings: ");
scanf("%s%s", string1, string2);

	if(strlen(string1) != strlen(string2))
	{
		printf("Strings are not the same length");
		return 0;
	}

        if(strlen(string1) == strlen(string2))
	{
		for(i=0, j=0; i<strlen(string1), j<strlen(string2); i++, j++)
		{
			if(isalpha(string1[i])==isalpha(string2[j]))
			{
				k++;
			}
		}
		if(k<= 2)
		{
			printf("true");
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
