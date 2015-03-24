#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include "gfx3.h"

#define centX 400
#define centY 300
#define MILLION 1000000

typedef struct targetWord
{
	int vectorX;
	int vectorY;

	float xDelta;
	float yDelta;
	float yDeltaT;

	char string[25];
} Word_type;

void drawHP(int);

void readFile(char words[100][25]);

void Update(Word_type *, int *, int, char words[100][25]);

void Reset(Word_type *, int, char words[100][25]);

int main()
{
	// Get from Dictionary files
	char words[100][25] = {0};
	readFile(words);

	/*-----Gameplay Values-----*/
	gfx_open(800, 600, "Word Defense");
	int  i, iac, iew, hp = 100, *health;
	health = &hp;
	int diff = 1;
	char c, input[25] = {0};
	/*-----------*/

	/*-----Generate Enemies-----*/
	Word_type *p, x[10] = {};
	
	for (i = 0; i < 10; i++)
	{
		srand(time(NULL));
		x[i].vectorX = centX;
		x[i].vectorY = 0; 
		x[i].xDelta = 0;
		x[i].yDelta = 1; 
		x[i].yDeltaT = 2;
		strcpy(x[i].string, words[rand() % 5]);
		printf("x[%d] x: %d, y: %d, yDelta: %f %s \n", i, x[i].vectorX, x[i].vectorY, x[i].yDelta, x[i].string);
	}
	/*-----------*/

	while(1)
	{
		gfx_clear();

		//Background
		gfx_color(255, 0, 255);
		gfx_triangle(0, 500, 400, 500, 200, 300);
		gfx_triangle(400, 500, 600, 500, 500, 400);
		
		gfx_color(255, 255, 255);
		gfx_triangle(200, 300, 100, 400, 300, 400);
		gfx_triangle(500, 400, 450, 450, 550, 450);
		
		gfx_color(255, 255, 255);
		gfx_line(0, 550, 800, 550);

		gfx_color(0, 150, 0);
		gfx_rectangle(0, 500, 800, 100);
		gfx_fill_rectangle(0, 500, 800, 100);

		/*-----UI------*/
		drawHP( hp );
		/*-----------*/

		/*-----TypeUpdate------*/
		if (iew = gfx_event_waiting())
		{
			c = gfx_wait();
			iac = isalpha(c);
			if (iac == 1)
			{
				if((strlen(input)) > 24)
				{
					strcpy(input, NULL);
				}
				input[strlen(input) + 1] = c;
			}
			else if(iac == 0)
			{
				strcpy(input, NULL);
			}
		}
		printf();
		gfx_color(255, 255, 255);
		gfx_text(centX, 575, input);
		/*----------*/

		/*-----Update------*/
		for(i = 0; i < 10; i++)
		{
			if(diff >= pow(2, i))
			{
				p = &x[i];
				printf("x[%d] x: %d, y: %d, yDelta: %f, %s \n", i, p->vectorX, p->vectorY, x[i].yDelta, p->string);
				Update(p, health, diff, words);
				printf("x[%d] x: %d, y: %d, yDelta: %f, %s \n", i, p->vectorX, p->vectorY, x[i].yDelta, p->string);
			}
		}
		/*-----------*/
		
		/*-----TypeCheck------*/
		for(i = 0; i < 10; i++)
		{
			if(diff >= pow(2, i));
			{
				if(strcmp(input, x[i].string))
				{
					Reset(p, diff, words);
					diff += 0.1;
				}
			}
		}

		/*-----------*/

		/*-----Draw-----*/
		for(i = 0; i < 10; i++)
		{
			if(diff > pow(2, i))
			{
				gfx_text(x[i].vectorX, x[i].vectorY, x[i].string);
			}
		}
		/*----------*/

		if( hp <= 0 ) break;

		gfx_flush();
		usleep(MILLION/30);
	}

	// TODO: Get the High Score file
	while(1)
	{
		//High Score Loop
		//TODO: Display High Score
		char c = gfx_wait();
		if(c) break;
	}

	//Write High SCore File

	return 0;
}

void drawHP( int hp )
{
	gfx_color(255 - 255 * hp / 100, 255 * hp / 100, 0);
	char str[10];
	sprintf(str, "%d", hp);
	gfx_text(centX, centY, str);
}

void readFile(char words[100][25])
{
	FILE *wordlist, *ofp;

	wordlist = fopen("words.txt", "r");

	int i=0, j=0, n=0;
	char temp[25];

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
}

void Update(Word_type *p, int *health, int diff, char words[100][25])
{
	if(p->vectorX < 0)
	{
		srand(time(NULL));
		
		p->xDelta = rand() % (2 + diff);
	}
	else if(p->vectorX > 800)
	{
		srand(time(NULL));
		int d = diff;
		p->xDelta = -1 * rand() % (2 + diff);
	}

	if (p->vectorY >= 500)
	{
		Reset(p, diff, words);
		*health -= strlen(p->string);
	}

	p->vectorX += p->xDelta;
	p->yDelta += p->yDeltaT;
	p->vectorY += p->yDelta;
}

void Reset(Word_type *p, int diff, char words[100][25
])
{
	srand(time(NULL));
	p->vectorX = 1 + rand() % 800;
	p->vectorY = 0; 
	p->xDelta = rand() % 4 * diff - 2 * diff; 
	p->yDelta = 0;
	p->yDeltaT = 1 + rand() % (2 + diff);
	strcpy(p->string, words[rand() % (5 + diff)]);
}
