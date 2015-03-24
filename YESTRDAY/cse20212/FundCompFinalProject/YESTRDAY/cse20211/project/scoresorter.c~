#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *file, *ofp;

	file = fopen("scores.txt", "r");

	int i=0, j=0, n=0;
	int scores[11], temp;
	for(i = 0; i < 11; i++)
	{
		int d;
		fscanf(file, "%d\n", &d);
		//printf("%d\n", d);
		scores[i] = d;
	}
			for(i=0; i<11; i++)
			{
				for(j = i+1; j< 10; j++)
				{
					if(scores[i] < scores[j])
					{
						temp = scores[i];
	
						scores[i] = scores [j];
	
						scores[j] = temp;
					}	
				}
			}

		ofp = fopen("highscores.txt", "w");
		for(n=0; n<10; n++)
		{
		printf("%d\n", scores[n]);
			fprintf(ofp, "%d\n", scores[n]);
		}	
	
}				
