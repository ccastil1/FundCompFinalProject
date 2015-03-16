#include <stdio.h>
#define HEIGHT 40
#define WIDTH 40
#define LIFE_YES 1
#define LIFE_NO 0

// make the rest of the function calls easier to read
typedef int TableType[HEIGHT][WIDTH];

void printTable(TableType table) {
	int height, width;

	for (height = 0; height < HEIGHT; height++) {
		for (width = 0; width < WIDTH; width++) {
			if (table[height][width] == LIFE_YES) {
				printf("X");
			} else {
				printf("-");
			}
		}
		printf("\n");
	}
	printf("\n");
}


// you already have a printTable, no need for this
// clear was a better name
void clearTable(TableType table) {
	int height, width;
	for (height = 0; height < HEIGHT; height++) {
		for (width = 0; width < WIDTH; width++) {
			table[height][width] = LIFE_NO;
		}
	}
}

void askUser(TableType tableA) {
	int i;
	int n;
	int height, width;

	printf("Enter the amount of initial organisms: ");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("Enter dimensions (x y) where organism %d will live: ", i + 1);
		scanf("%d %d", &height, &width);
		tableA[height][width] = LIFE_YES;
	}
	
	printTable(tableA);
	printf("Generation 0");
}


int getNeighborValue(TableType table, int row, int col) {
	if (row < 0 || row >= HEIGHT 
		|| col < 0 || col >= WIDTH
		|| table[row][col] != LIFE_YES )
	{ 
		return 0;
	} else {
		return 1;
	}
}


int getNeighborCount(TableType table, int row, int col) {
	int neighbor = 0;

	neighbor += getNeighborValue(table, row - 1, col - 1);
	neighbor += getNeighborValue(table, row - 1, col);
	neighbor += getNeighborValue(table, row - 1, col + 1);
	neighbor += getNeighborValue(table, row, col - 1);
	neighbor += getNeighborValue(table, row, col + 1);
	neighbor += getNeighborValue(table, row + 1, col - 1);
	neighbor += getNeighborValue(table, row + 1, col);
	neighbor += getNeighborValue(table, row + 1, col + 1);
	
	return neighbor;
}

void calculate(TableType tableA) {
	TableType tableB;
	int neighbor, height, width;

	for (height = 0; height < HEIGHT; height++) {
		for (width = 0; width < WIDTH; width++) {
			neighbor = getNeighborCount(tableA, height, width);
			// change this arund to remove the ? : notation
			if (neighbor==3) {
				tableB[height][width] = LIFE_YES;
			} else if (neighbor == 2 && tableA[height][width] == LIFE_YES) {
				tableB[height][width] = LIFE_YES;
			} else {
				tableB[height][width] = LIFE_NO;
			}
		}
	}
	// used to be swap
	for (height = 0; height < HEIGHT; height++) {
		for (width = 0; width < WIDTH; width++) {
			tableA[height][width] = tableB[height][width];
		}
	}
}

// user entry is a pain for testing
// here's some code to load test data
void loadTestData(TableType table) {
	// toggle
	table[3][4] = LIFE_YES;
	table[3][5] = LIFE_YES;
	table[3][6] = LIFE_YES;
	
	// glider
	table[10][4] = LIFE_YES;
	table[10][5] = LIFE_YES;
	table[10][6] = LIFE_YES;
	table[11][6] = LIFE_YES;
	table[12][5] = LIFE_YES;
}

int main(void) {
	TableType table;
	char end;
	int generation = 0;

	clearTable(table);
	// askUser(table);
	loadTestData(table);
	printTable(table);

	do {
		calculate(table);
		printTable(table);
		printf("Generation %d\n", ++generation);
		printf("Press q to quit or 1 to continue: ");
		scanf(" %c", &end);
	} while (end != 'q') ;
	return 0;
}


