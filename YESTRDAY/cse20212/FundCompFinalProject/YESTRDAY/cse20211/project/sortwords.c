#include<stdio.h>
#include<string.h>


void main()
{
	FILE *wordlist, *ofp;
	wordlist = fopen("words.txt", "r");
	int i,j, n,result,index;
	char name[25][25],temp[25];
	
	printf("here");
	
	while(!feof(wordlist))
	{
		fscanf(wordlist, "%s\n", name[i]);
		i++;
		
		printf("there");

		for(i=0;i<100;i++)
		{
			scanf("%s",name[i]);
		}		
		for(i=0;i<100;i++)
		{
			index=i;
		
			for(j=i+1;j<100;j++)
			{
				result=strcmp(name[index],name[j]);
				if(result<0)
					index=j;
			}

			strcpy(temp,name[index]);
			strcpy(name[index],name[i]);
			strcpy(name[i],temp);
		}
		
		ofp = fopen("nwords.txt", "w");
		for(n=0; n<100; n++)
		{
			fprintf(ofp, "%s\n", name[i]);
		}	
		fputs("\n", ofp);
	}
}


