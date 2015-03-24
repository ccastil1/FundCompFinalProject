#include <stdio.h>

int main()
{
	int a, b, sum, product, difference, quotient;

	printf("Enter two numbers: ");
	scanf("%d%d", &a, &b);

	sum = a + b;

	difference = a - b;

	product = a * b;
	
	quotient = a/b;

	printf("The sum is %d\n", sum);
	printf("The difference is %d\n", difference);
	printf("The product is %d\n", product);
	printf("The quotient is %d\n", quotient);
}
