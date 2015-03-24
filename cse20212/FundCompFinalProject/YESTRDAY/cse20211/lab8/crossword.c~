#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 15
#define WORDMAX 20
#define LETTERMAX 15

void board_setup(char board[SIZE][SIZE], char list[WORDMAX][LETTERMAX], int word_pos[], int word_direction[]);

int list_input(char list[WORDMAX][LETTERMAX]);

void sort_list(char list[WORDMAX][LETTERMAX], int word_tot);

void print_board(char board[SIZE][SIZE]);

int check_vertical(char board[SIZE][SIZE], int y, int x);

int check_horizontal(char board[SIZE][SIZE], int y, int x);

int check_up(char board[SIZE][SIZE], int y, int x);

int check_down(char board[SIZE][SIZE], int y, int x);

int check_left(char board[SIZE][SIZE], int y, int x);

int check_right(char board[SIZE][SIZE], int y, int x);

void place_word_up(char board[SIZE][SIZE], char list[WORDMAX][LETTERMAX], int word, int y, int x);

void place_word_down(char board[SIZE][SIZE], char list[WORDMAX][LETTERMAX], int word, int y, int x);

void place_word_left(char board[SIZE][SIZE], char list[WORDMAX][LETTERMAX], int word, int y, int x);

void place_word_right(char board[SIZE][SIZE], char list[WORDMAX][LETTERMAX], int word, int y, int x);

int letter_check(char board[SIZE][SIZE], char list[WORDMAX][LETTERMAX], int list_pos, int word_pos[], int word_dir[]);

void list_board(char board[SIZE][SIZE], char list[WORDMAX][LETTERMAX], int word_tot, int word_pos[], int word_dir[]);

void upper(char list[WORDMAX][LETTERMAX], int word_tot);

void print_solution(char board[SIZE][SIZE]);

void make_puzzle(char board[SIZE][SIZE]);

void print_clue(char list[WORDMAX][LETTERMAX], int word_pos[], int word_direction[], int word_tot);


int main () {

int word_tot, word_pos[word_tot*2], word_direction[word_tot];
char list[WORDMAX][LETTERMAX], board[SIZE][SIZE];

	word_tot = list_input(list);	//function returns the number of words

	upper(list, word_tot);		//function converts words to uppercase

	sort_list(list, word_tot);	//function sorts list by size
	
	board_setup(board, list, word_pos, word_direction); 	//creates board and places first word

	list_board(board, list, word_tot, word_pos, word_direction); 	//places words on board
	
	print_solution(board);
	
	make_puzzle(board);

	print_clue(list, word_pos, word_direction, word_tot);
}

void board_setup(char board[SIZE][SIZE], char list[WORDMAX][LETTERMAX], int word_pos[], int word_direction[])
{ int i, j, word_size, start_pos;
	for(i=0; i< SIZE; i++) {
		for(j=0; j< SIZE; j++) {
			board[i][j]='.';
		}
	}

	word_size=strlen(list[0]);

	start_pos=(SIZE-word_size)/2;

	word_pos[0]=start_pos;
	
	word_pos[1]=SIZE/2;
	
	word_direction[0]=2;

	for(i=start_pos, j=0; i<word_size + start_pos; i++, j++) {
		board[SIZE/2][i] = list[0][j];
	}
}

int list_input(char list[WORDMAX][LETTERMAX])
{ int i;
    printf("Enter a list of at most 20 words followed by a '.':\n");
    for(i=0;i<WORDMAX;i++){
        scanf("%s",list[i]);//loop creates strings out of input
        if(list[i][0]=='.') return i;//if dot is pressed list ends and number of words is returned
    }
    return i+1;//if the loop ends the number of words is returned
}

void sort_list(char list[WORDMAX][LETTERMAX], int word_tot)
{
  int i, j;
    char temp[LETTERMAX];
    for(i=1;i<word_tot;i++){
        for(j=0;j<word_tot-i;j++){
            if(strlen(list[j])<strlen(list[j+1]))
		{					//bubble sort checks size
	                strcpy(temp,list[j]);
	                strcpy(list[j],list[j+1]);
	                strcpy(list[j+1],temp);
                }
          }
     }
}

void print_solution(char board[SIZE][SIZE])
{ int i, j;
    printf("\n\nSolution:\n");
    for(i=0;i<SIZE;i++){
        printf("\n");
        for(j=0;j<SIZE;j++){
            printf("%c",board[i][j]);//loops through board array and prints each character
        }
     }
}

int check_vertical(char board[SIZE][SIZE], int y, int x)
{ int check=0;
    if(board[y-1][x]=='.'){
        if(board[y+1][x]=='.')check=1;//if both are empty 1 is returned
    }
    
	return check;//if either of them have a non empty character 0 is returned
}

int check_horizontal(char board[SIZE][SIZE], int y, int x)
{ int check=0;
    if(board[y][x-1]=='.'){
        if(board[y][x+1]=='.')check=1;
     }

	    return check;
}

int check_up(char board[SIZE][SIZE], int y, int x)
{ int check=0;
    if(board[y-1][x+1]=='.'){
        if(board[y-1][x-1]=='.')check=1;//if the top left and top right are empty 1 is returned
    }
    
	return check;//if both checks are not passed 0 is returned
}

int check_down(char board[SIZE][SIZE], int y, int x)
{  int check=0;
    if(board[y+1][x+1]=='.'){
        if(board[y+1][x-1]=='.')check=1;
    }
  
	  return check;
}

int check_left(char board[SIZE][SIZE], int y, int x)
{ int check=0;
    if(board[y-1][x-1]=='.'){
        if(board[y+1][x-1]=='.')check=1;
    }

	    return check;
}

int check_right(char board[SIZE][SIZE], int y, int x)
{ int check=0;
    if(board[y-1][x+1]=='.'){
        if(board[y+1][x+1]=='.')check=1;
    }
 
	   return check;
}

void place_word_up(char board[SIZE][SIZE], char list[WORDMAX][LETTERMAX], int word, int y, int x)
{ int string_length=strlen(list[word]), i;
    for(i=string_length-1;i>=0;i--,y--){
        board[y][x]=list[word][i];
    }
}

void place_word_down(char board[SIZE][SIZE], char list[WORDMAX][LETTERMAX], int word, int y, int x)
{ int string_length=strlen(list[word]), i;
    for(i=0;i<string_length;i++,y++){
        board[y][x]=list[word][i];
    }
}

void place_word_left(char board[SIZE][SIZE], char list[WORDMAX][LETTERMAX], int word, int y, int x)
{ int string_length=strlen(list[word]), i;
    for(i=string_length-1;i>=0;i--,x--){
        board[y][x]=list[word][i];
    }
}

void place_word_right(char board[SIZE][SIZE], char list[WORDMAX][LETTERMAX], int word, int y, int x){
    int string_length=strlen(list[word]);
    int i;
    for(i=0;i<string_length;i++,x++){
        board[y][x]=list[word][i];
        }
}
 
int letter_check(char board[SIZE][SIZE], char list[WORDMAX][LETTERMAX], int list_pos, int word_pos[], int word_dir[])
{ int i, j, string_length=strlen(list[list_pos]);
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){//double loop checks entire board
            if(list[list_pos][string_length-1]==board[i][j]){//for placing words up and left checks to see if the last letter is the same as the current position
                if(1==check_vertical(board,i,j)){//if the vertical check is passed keep going
                    if(1==check_up(board,i,j)){//if the up check is passed keep going
                        place_word_up(board,list,list_pos,i,j);//place word backwords and up
                        word_pos[list_pos*2]=j;//save x position of placed word for later
                        word_pos[list_pos*2+1]=i-string_length;//y position
                        word_dir[list_pos]=1;//1 is for the direction (vertical)
                        return 1;
                        }
                    }
                if(1==check_horizontal(board,i,j)){//if the horizontal check is passed keep going
                    if(1==check_left(board,i,j)){//if the left check is passed keep going
                        place_word_left(board,list,list_pos,i,j);//place word to the left of character and backwords
                        word_pos[list_pos*2]=j-string_length;//save x position of placed word
                        word_pos[list_pos*2+1]=i;//y position
                        word_dir[list_pos]=2;//save direction (horizontal)
                        return 1;
                        }
                    }
                }
            if(list[list_pos][0]==board[i][j]){//for placing words down and right, checks to see if the first letter matches up to the character on the board
                if(1==check_vertical(board,i,j)){//vertical check
                    if(1==check_down(board,i,j)){//down check
                        place_word_down(board,list,list_pos,i,j);//place word
                        word_pos[list_pos*2]=j;//save x position
                        word_pos[list_pos*2+1]=i;//save y position
                        word_dir[list_pos]=1;//save direction
                        return 1;
                        }
                    }
                if(1==check_horizontal(board,i,j)){
                    if(1==check_right(board,i,j)){
                        place_word_right(board,list,list_pos,i,j);
                        word_pos[list_pos*2]=j;
                        word_pos[list_pos*2+1]=i;
                        word_dir[list_pos]=2;
                        return 1;
                        }
                    }
                }
            }
        }
    word_pos[list_pos*2]=-1;//if word could not be placed save the x position as a negative number
    word_pos[list_pos*2+1]=-1;//same but for y
    word_dir[list_pos]=-1;//if word could not be placed save the direction as a negative number
    return 0;//if word could not be placed return a 0
}

void list_board(char board[SIZE][SIZE], char list[WORDMAX][LETTERMAX], int word_tot, int word_pos[], int word_dir[])
{ int i, check;
    for(i=1;i<word_tot;i++){//loops through list
        check=letter_check(board,list,i,word_pos,word_dir);//sets check to 1 if word is placed 0 if it is not
        if(check==0)printf("\n%s Error: Word could not be placed",list[i]);//if word is not placed error message pops up
        }
}
 
void upper(char list[WORDMAX][LETTERMAX], int word_tot)
{ int i, j, string_length;
    for(i=0;i<word_tot;i++){//loops through word list
        string_length=strlen(list[i]);//string length of each word is saved
        for(j=0;j<string_length;j++){//loops through each character in each word
            list[i][j]=toupper(list[i][j]);//converts to upper case
         }
    }
}
 
void print_puzzle(char board[SIZE][SIZE])
{  int i, j;
    printf("\n\nCrossword puzzle:\n");
    for(i=0;i<SIZE;i++){
        printf("\n");
        for(j=0;j<SIZE;j++){
            printf("%c",board[i][j]);
            }
        }
    }
 
void make_puzzle(char board[SIZE][SIZE])
{ int i, j;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            if(board[i][j]=='.')board[i][j]='#';
            else board[i][j]=' ';//turns all non-empty spaces to a space
         }
     }
    print_puzzle(board);
}
 
void print_clue(char list[WORDMAX][LETTERMAX], int word_pos[], int word_direction[], int word_tot)
{ int i;
    printf("\n\nClues:\n\n");
    for(i=0;i<word_tot;i++){//loops through the word list
        if(word_direction[i]>0){//if the word was not placed word_dir will be less then 0 and clue the clue will not be created
            printf("%d, %d ",word_pos[i*2],word_pos[i*2+1]);//prints the x and y position that were saved for every word
            if(word_direction[i]==1)printf("down ");//prints the direction saved 1 is vertical
            else printf("across ");//if its not 1 and not negative then it has to be 2 which was horizontal
            strfry(list[i]);//creates an anagram for the current word
            printf("%s\n",list[i]);//prints the new scrambled word
        }
    }
}
