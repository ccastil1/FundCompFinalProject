#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	FILE *wordlist, *ofp;

	wordlist = fopen("words.txt", "r");

	int i=0, j=0, n=0;
	char words[1000][20], temp[25];
	while(fgets(words[i], 100, wordlist))
	{
		i++;
	}	
		for(i = 0; i < 100; i++)
		{
			for(j=0; j < 99; j++)
			{
				if(strlen(words[i]) < strlen(words[j]))
				{
					strcpy(temp, words[i]);

					strcpy(words[i], words[j]);

					strcpy(words[j], temp);


				}
	
			}
		}
		
	ofp = fopen("newwords.txt", "w");
	for(n=0; n<100; n++)
	{
		fprintf(ofp, "%s", words[n]);
	}		
}	
