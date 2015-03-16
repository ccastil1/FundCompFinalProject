#include <stdio.h>
int main()
{

	int touchdowns;
	int extra;
	int field;
	int safeties;
	int score;

	printf("Enter the number of touchdowns: \n");
	scanf("%d", &touchdowns);

        printf("Enter the number of extra points: \n");
        scanf("%d", &extra);

        printf("Enter the number of field goals: \n");
        scanf("%d", &field);

        printf("Enter the number of safeties: \n");
        scanf("%d", &safeties);

	score = (touchdowns * 6 + extra + field * 3 + 2 * safeties);
	printf("Score is %d\n", score);
}

