//Celeste Castillo

#include <stdio.h>
#include<string.h>
#include <ctype.h>

int main() {

	char k, newsaying[80], file [100] [80], searchword[80], str1, str2, match, newfilename[100];

	int q=0,row=0, i=0, column=0, j=0, newsayinglength, a=0,b=0, c=0, d=0, u=0;

	int choice;

	FILE *fp;

	FILE *ofp;

	printf("Enter a startup data file name: ");
	scanf("%s", file);

	fp = fopen(file,"r");		

	while(fgets(file[row], 80, fp))
	{
		row++;

	}
	
	while(1) {
		printf("1. Display all sayings currently in the database.\n" "2. Enter a new saying into the database.\n" "3. List all the sayings that contain a given word.\n" "4. Save all sayings in a new text file.\n" "5. Quit the program.\n");
		printf("Enter your choice: ");
		scanf(" %c", &choice);
	
		switch (choice) {

			case '1': 	
				for(i = 0; i<row; i++) {
					for(j = 0; j < 80; j++) {
						printf("%c", file[i][j]);
					}
				}
				break;

			case '2':
		
				u = 0;

				while(isalpha(file[u][1])) {
	
					u++;
				}

				printf("Enter new saying: ");
				
				fgetc(stdin);

				fgets(file[u],100, stdin);
			
				break;

			case '3':

				a=0, b=0, c=0, d=0;

				char searchword[80];

				printf("Enter search word: ");
		
				scanf("%s", searchword);

				for (a=0; a<80; a++) 
				{	//for each row
			
			
					for(b=0; b<100; b++) {  //for each char
			
						if(file[a][b]==searchword[0]) {
							
							d = 0;
							for (c=0; c<strlen(searchword); c++) //for each char in wrod
							{
								if(file[a][b+c] == searchword[c]) {
									d++;
								}
							}
						}
					}
			

					if(d==strlen(searchword)) 
					{
						printf("%s", file[a]);
					}
				}
				break;

			case '4':

				printf("Enter new file name: ");

				scanf("%s", newfilename);

				ofp = fopen(newfilename, "w");

				a = 0;

				for(a=0; a<80; a++) {

					fprintf(ofp, "%s", file[a]);
				}

				break;

			case '5':
				printf("Goodbye\n");
				q=1;
				break;

			default:
				printf("Error\n");
		}	
			if (q==1) {
				break;
			}
	}
}


		
	
