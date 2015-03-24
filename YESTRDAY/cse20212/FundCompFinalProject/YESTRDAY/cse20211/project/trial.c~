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

void readScoreFile(int scores[11], int score);

void drawBackground();

void drawDeadBackground();

void concatenate(char *input, char c);

int main()
{
    // Get from Dictionary files
    char words[100][25] = {0};
    readFile(words);

    /*-----Gameplay Values-----*/
    gfx_open(800, 600, "Word Defense");
    int  i, iew, iac, hp = 100, *health;
    health = &hp;
    int scores[11] = {0}, score = 0, diff = 1, typeLoc = 0;;
    char c, initstr[25], input[25];
    /*-----------*/

    /*-----Generate Enemies-----*/
    Word_type *p, x[5] = {};

    for (i = 0; i < 5; i++)
    {
        srand(time(NULL));
        x[i].vectorX = centX;
        x[i].vectorY = 0; 
        x[i].xDelta = 0;
        x[i].yDelta = 2; 
        x[i].yDeltaT = 2;
	strcpy(initstr, words[rand() % 4]);
        strcpy(x[i].string, initstr);
        printf("x[%d] x: %d, y: %d, yDelta: %f %s \n", i, x[i].vectorX, x[i].vectorY, x[i].yDelta, x[i].string); //TODO: DELETE TEST LINE
    }
    /*-----------*/

    while(1)
    {
    gfx_clear();

	    drawBackground();

	    /*-----UI------*/
	    drawHP( hp );
	    /*-----------*/

	    /*-----TypeUpdate------*/
	    gfx_color(255, 255, 255);
	    if (iew = gfx_event_waiting())
	    {
		c = gfx_wait();
		iac = isalpha(c);
	      if (iac == 1)
		{
		   /* if( typeLoc >= 25)
		    {
			strcpy(input, NULL);
			typeLoc = 0;
		    }
		    input[typeLoc] = c;
		    typeLoc++;
		}
		    else if(iac == 0)
		    {
			strcpy(input, NULL);
			typeLoc = 0;
		    }
	    */
		//sprintf(input,"printf Works"); DO NOT USE
		}
	     }   
	
	

	strcpy(input,"autoInput");
	printf("input: %s\n", input); //TODO: DELETE TEST LINE
	gfx_color(255, 255, 255);
	gfx_text(centX, 575, input);
	/*----------*/

	/*-----Update------*/
	for(i = 0; i < 5; i++)
	{//for1
	    if(diff >= pow(2, i))
	    {//if1
	        p = &x[i];
	        printf("x[%d] x: %d, y: %d, xDelta: %f, yDelta: %f, %s \n", i, p->vectorX, p->vectorY, x[i].xDelta, x[i].yDelta, p->string); //TODO: DELETE TEST LINE
	        //Update(p, health, diff, words);
	        
		if(p->vectorX < 0)
		    {
			srand(time(NULL));

			p->xDelta = rand() % (2 + diff);
		    }
		    else if(p->vectorX > 800)
		    {
			srand(time(NULL));
			int d = diff;
			p->xDelta = -1* rand() % (2 + diff);
		    }

		    if (p->vectorY >= 500)
		    {
			//Reset(p, diff, words);
			srand(time(NULL));
		    	p->vectorX = 1 + rand() % 800;
			    p->vectorY = 0; 
			    p->xDelta = rand() % 2 * diff - diff; 
			    p->yDelta = 0;
			    p->yDeltaT = 1 + rand() % (2 + diff);
				*health -= strlen(p->string);
		    }

		    p->vectorX += p->xDelta;
		    p->yDelta = p->yDeltaT;
		    p->vectorY += p->yDelta;
		}
	    }
	/*-----------*/
	
	/*-----TypeCheck------*/
	for(i = 0; i < 5; i++)
	{
	    if(diff >= pow(2, i));
	    {
		p = &x[i];
	        if(strcmp(input, x[i].string))
	        {
	            //Reset(p, diff, words);
		    srand(time(NULL));
		    p->vectorX = 1 + rand() % 800;
		    p->vectorY = 0; 
		    p->xDelta = rand() % 2 * diff - diff; 
		    p->yDelta = 0;
		    p->yDeltaT = 1 + rand() % (2 + diff);

	char newstr[25];
// strcpy(newstr, words[rand()%(5+diff)]);
  //  strcpy(p->string, newstr);

	            diff += 1;
	            score += strlen(x[i].string);
	        }
	    }
	}

	/*-----------*/

	/*-----Draw-----*/
	gfx_color(255, 255, 255);
	for(i = 0; i < 5; i++)
	{
	    if(diff >= pow(2, i))
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
    
    
    //High Score Loop
    readScoreFile(scores, score);

    int whiteness = 255;
    while(whiteness >= 0);
    {
        drawDeadBackground();

        gfx_color(whiteness, whiteness, whiteness);
        gfx_fill_rectangle(0, 0, 800, 800);

        gfx_color(255, 255, 255);
        gfx_text(centX, centY-15, "High Scores:");
    
        for(i = 0; i < 10; i++)
        {
            char str[10];
            sprintf(str, "%d. :", i+1);
            gfx_text(centX - 50, centY + 13 * i, str);
            sprintf(str, "%d", scores[i]);
            gfx_text(centX, centY + 13 * i, str);
        }
        whiteness -= 255/30;
        usleep(MILLION/30);
    }
    //Write High SCore File

    c = gfx_wait();

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



void Reset(Word_type *p, int diff, char words[100][25
])
{
    srand(time(NULL));
  //  p->vectorX = 1 + rand() % 800;
  //  p->vectorY = 0; 
  //  p->xDelta = rand() % 2 * diff - diff; 
  //  p->yDelta = 0;
 //   p->yDeltaT = 1 + rand() % (2 + diff);

	char newstr[25];
// strcpy(newstr, words[rand()%(5+diff)]);
  //  strcpy(p->string, newstr);

}

void readScoreFile(int scores[11], int score)
{
    FILE *scorefile, *ofp;

    scorefile = fopen("scores.txt", "r");

    int i=0, j=0, n=0, temp;

    for(i=0; i < 10; i++)
    {
        int d;
        fscanf(scorefile, "%d\n", &d);
        scores[i] = d;
    }
    scores[11] = score;

        for(i=0; i < 11; i++)
        {
            for(j=i+1; j < 10; j++) 
            {
                if(scores[i] < scores[j])
                {
                    temp = scores[i];
                    scores[i] = scores[j];
                    scores[j] = temp;
                }            
            }    
        }
    ofp = fopen("highscores.txt", "w");
    for(i=0; i<10; i++)
    {
        fprintf(ofp, "%d\n", scores[i]);
    }
}

void drawBackground()
{
    /*-----Background-----*/
    //Mountain
    gfx_color(255, 0, 255);
    gfx_triangle(0, 500, 400, 500, 200, 300);
    gfx_triangle(400, 500, 600, 500, 500, 400);

    //Mountain Tip
    gfx_color(255, 255, 255);
    gfx_triangle(200, 300, 100, 400, 300, 400);
    gfx_triangle(500, 400, 450, 450, 550, 450);

    //"Threshold Line"
    gfx_color(255, 255, 255);
    gfx_line(0, 500, 800, 500);

    //LandScape
    gfx_color(0, 150, 0);
    gfx_rectangle(0, 500, 800, 100);
    gfx_fill_rectangle(0, 500, 800, 100);
    /*----------*/
}

void drawDeadBackground()
{
    gfx_clear();
    //Mountain
    gfx_color(175, 175, 0);
    gfx_triangle(0, 500, 400, 500, 200, 300);
    gfx_triangle(400, 500, 600, 500, 500, 400);
    
    //Mountain Tip
    gfx_color(255, 0, 0);
    gfx_triangle(200, 300, 100, 400, 300, 400);
    gfx_triangle(500, 400, 450, 450, 550, 450);
    
    //Dead landscape
    gfx_color(50, 50, 50);
    gfx_line(0, 550, 800, 550);
    gfx_rectangle(0, 500, 800, 100);
    gfx_fill_rectangle(0, 500, 800, 100);
}

void concatenate(char *input, char c)
{
	while(*input)	
		input++;

	while(c)
	{
		*input = c;
		c++;
		input++;
	}
	*input = '\0';
}
