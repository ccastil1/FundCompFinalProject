#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main() {

int i, n, j;

char password[500];

printf("Enter the password: ");
scanf("%s", password);

if (strlen(password) < 30)
	{
		printf("Password is too short,");
		return 0;
	}
else {
	for(i=0; i< strlen(password); i++)
		{
			if(isxdigit(password[i])) 
			{	n++;
			}
			if(isalpha(password[i]))
			{	j++;
			}
	if(n > 0 && j > 0)
		{ 	printf("Password is strong\n");
	
		}
	else
		return 0;
		}
	}
}
