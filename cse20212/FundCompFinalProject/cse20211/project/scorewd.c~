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
    int diffThresh;

    char string[25];
} Word_type;

void drawHP(int);

void readFile(char words[100][25]);

void Update(Word_type *, int *, int, char words[100][25]);

void Reset(Word_type *, int, char words[100][25]);

void readScoreFile(int scores[11], int score);

void drawBackground();

void drawDeadBackground();

void drawScore(int);

int main()
{
    // Get from Dictionary files
    char words[100][25] = {0};
    readFile(words);
    /*-----Gameplay Values-----*/
    gfx_open(800, 600, "Word Defense");
    int  i, iew, iac, hp = 1, *health;
    health = &hp;
    int scores[11] = {0}, score = 0, diff = 1, typeLoc = 0; //TODO: change back to 100
    char c, input[25] = {0}, str[25];
    /*-----------*/

    for(i = 0; i < 100; i++)    printf("%s\n", words[i]);
    printf("%d\n", diff);

    /*-----Generate Enemies-----*/
    Word_type *p, x[5] = {};

    for (i = 0; i < 5; i++)
    {
        x[i].vectorX = centX;
        x[i].vectorY = 0; 
        x[i].xDelta = 0;
        x[i].yDelta = 2; 
        x[i].yDeltaT = 2;
        x[i].diffThresh = pow(2, i);

        srand(time(NULL));
        strcpy(str, words[rand() % 5]);
        strcpy(x[i].string, str);
      //  printf("x[%d] x: %d, y: %d, xDelta: %f, yDelta: %f, %s, diffThresh: %d\n", i, x[i].vectorX, x[i].vectorY, x[i].xDelta, x[i].yDelta, x[i].string, x[i].diffThresh); //TODO: DELETE TEST LINE
    }
    c = gfx_wait();
    /*-----MAIN GAME LOOP------*/

    while(1)
    {
        gfx_clear();

        drawBackground();

        /*-----UI------*/
        drawHP( hp );
        drawScore( score );
        /*-----------*/

        /*-----TypeUpdate------*/
        gfx_color(255, 255, 255);
        if (iew = gfx_event_waiting())
        {
            c = gfx_wait();
    //        printf("typed: %c\n", c); //TODO: DELETE TEST LINE
            if (isalpha(c))
            {
     //           printf("%c is alpha\n typeLoc: %d\n", c, typeLoc); //TODO: DELETE TEST LINE
                if( typeLoc >= 24)
                {
                    printf("typeLoc: %d >= 25", typeLoc);
                    //strcpy(input, "");
                    memset(input, 0, strlen(input));
                    typeLoc = 0;
                    printf("typeLoc: %d should = 0", typeLoc);
                }
                else  
                {
                    input[typeLoc] = c;
                    typeLoc++;
                }

            }
            else
            {
   //             printf("%c is not alph\n", c); //TODO: DELETE TEST LINE
                //strcpy(input, "");
                memset(input, 0, strlen(input));
                typeLoc = 0;
            }
       //     printf("typeLoc: %d input: %s\n", typeLoc, input); //TODO: DELETE TEST LINE
        }
        
        gfx_color(255, 255, 255);

        if(strcmp(input, "") == 0)         gfx_text(centX - 50, 550, "[ENTER TEXT TO SAVE THE WORLD]");
        else                                gfx_text(centX - 50, 550, input);
        /*----------*/

        /*-----Update------*/
        for(i = 0; i < 5; i++)
        {
            if(diff >= x[i].diffThresh)
            {
                //printf("diff: %d >= diffThresh: %d\n", diff, x[i].diffThresh);
                p = &x[i];
                Update(p, health, diff, words);
                //printf("x[%d] x: %d, y: %d, xDelta: %f, yDelta: %f, %s \n", i, p->vectorX, p->vectorY, x[i].xDelta, x[i].yDelta, p->string); //TODO: DELETE TEST LINE
            }
        }
        /*-----------*/
        
        /*-----TypeCheck------*/
        for(i = 0; i < 5; i++)
        {
            if(diff >= x[i].diffThresh);
            {
                if(strcmp(input, x[i].string) == 0)
                {
        //            printf("%s = %s\n", input, x[i].string);
                    memset(input, 0, strlen(input));
					typeLoc = 0;
                    p = &x[i]; 
                    Reset(p, diff, words);
                    diff += 1;
                    score += strlen(x[i].string);
                }
       //         else printf("%s != %s\n", input, x[i].string);
            }
        }

        /*-----------*/

        /*-----Draw-----*/
        gfx_color(255, 255, 255);
        for(i = 0; i < 5; i++)
        {
            if(diff >= x[i].diffThresh)
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
//updatescore(scores);


    int whiteness = 255;
    while(whiteness >= 0)
    {
        gfx_clear();

        gfx_color(whiteness, whiteness, whiteness);
        gfx_fill_rectangle(0, 0, 800, 800);

        gfx_color(255, 255, 255);
        gfx_text(centX-60, centY-80, "High Scores:");
    
        for(i = 0; i < 10; i++)
        {
            char str[10];
            sprintf(str, "%d.", i+1);
            gfx_text(centX - 50, centY - 65 + 13 * i, str);
            sprintf(str, "%d", scores[i]);
            gfx_text(centX -30, centY - 65 + 13 * i, str);
        }
        drawDeadBackground();
        whiteness -= 30;
        gfx_flush();
        usleep(MILLION/30);
    }

    gfx_color(255, 255, 255);
    gfx_text(centX-60, centY-80, "High Scores:");

    for(i = 0; i < 10; i++)
    {
        char str[10];
        sprintf(str, "%d.", i+1);
        gfx_text(centX - 50, centY - 65 + 13 * i, str);
        sprintf(str, "%d", scores[i]);
        gfx_text(centX-30, centY - 65 + 13 * i, str);
    }
    gfx_flush();

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

    while(!feof(wordlist))
    {
        fscanf(wordlist, "%s", words[i]);
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
        p->xDelta = -1 * rand() % (2 + diff);
    }

    if (p->vectorY >= 500)
    {
        //'Reset' the word
        srand(time(NULL));
        p->vectorX = 200 + rand() % 400;
        p->vectorY = 0;

        srand(time(NULL));
        p->xDelta = (rand() % 2) * rand() % (2 + diff); 

        p->yDelta = 0;
        srand(time(NULL));
        p->yDeltaT = 1 + rand() % (2 + diff);
        
        char newstr[25];

        srand(time(NULL));
//seg        strcpy(newstr, words[rand() % (5 + diff)]);
//seg       strcpy(p->string, newstr);

        //Update
        *health -= strlen(p->string);
    }

    p->vectorX += p->xDelta;
    p->yDelta = p->yDeltaT;
    p->vectorY += p->yDelta;
}

void Reset(Word_type *p, int diff, char words[100][25])
{
    //'Reset' the word
    srand(time(NULL));
    p->vectorX = 200 + rand() % 400;
    p->vectorY = 0;

    srand(time(NULL));
    p->xDelta = (rand() % 3 - 1) * rand() % (2 + diff); 

    p->yDelta = 0;
    srand(time(NULL));
    p->yDeltaT = 1 + rand() % (2 + diff);
    
    char newstr[25];

    srand(time(NULL));
    strcpy(newstr, words[rand() % (5 + diff)]);
    strcpy(p->string, newstr);
}

void readScoreFile(int scores[11], int score)
{
    FILE *scorefile, *ofp;

    scorefile = fopen("scores.txt", "r");

    int i=0, j=0, k=0, n=0, temp;

    for(i=0; i < 10; i++)
    {
        int d;
        fscanf(scorefile, "%d\n", &d);
        scores[i] = d;
    }
	for(k=12; k>=1; k--)
	{	
		scores[k+1] = scores[k];
		scores[1] = score;
	}		

        for(i=0; i < 12; i++)
        {
            for(j=i+1; j < 11; j++) 
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

void drawScore( int score )
{
    char dispScore[25];
    gfx_color( 255, 255, 255);
    sprintf(dispScore, "Score: %d", score);
    gfx_text(50, 50, dispScore);
}
