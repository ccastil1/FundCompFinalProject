#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
int i;
char word[] = "kookaburra";

char *p = &word[5];

printf("%s\n", p);

	for (i=0; i<5; i++) {
		p[i] = word [i];
	}
printf("%s\n", word);
}
