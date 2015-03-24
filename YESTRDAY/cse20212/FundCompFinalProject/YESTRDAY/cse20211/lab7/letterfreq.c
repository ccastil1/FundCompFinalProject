//Celeste Castillo

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void counter(FILE *, int [], int []);

void display(int [], int[]);

int main() {	

	char text[50];

	FILE *fp;

	int lettercount[26]={0};

	int totalcount[3]={0};

	printf("Enter file name: ");
	scanf("%s", text);

	fp = fopen(text,"r");	

	counter(fp, lettercount , totalcount);

	display(lettercount, totalcount);

	fclose(fp);

}

void counter(FILE *fp, int lettercount[26], int totalcount[3])
{
	
	char c = 'a';

	while(c!=EOF) {
	
		c = getc(fp);

		if (isalpha(c)) {

			totalcount[0]++;
			
			lettercount[tolower(c)-'a']++;	

		}
	
		else if (isspace(c)) {
	
			totalcount[1]++;

		}

	}


}

void display(int lettercount[26], int totalcount[3])
{ 
	int i;

	float j = totalcount[1];

	int column;

	for(i=0, column=0; i<26; i++, column++) {

		if(!(column % 5)) {

			printf("\n");

		}

		printf("%c: %d\t", i + 'a', lettercount[i]);
	 
	}

	printf("\nLetters: %d\n", totalcount[0]);

	printf("White space: %d\n", totalcount[1]);

	printf("Total characters: %d\n", totalcount[0]+totalcount[1]);

	printf("Space percentage: %0.1f\n", 100*(j/(j+totalcount[0])));

}

