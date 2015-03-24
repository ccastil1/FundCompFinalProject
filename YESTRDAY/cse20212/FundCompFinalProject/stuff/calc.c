#include <stdio.h>
int main ()
{
	double principle;
	double rate;
	double interest;
	double payment;
	int month = 1;

	printf("Enter the principal amount of the loan:\n");
	scanf("%lf", &principle);

	printf("Enter the interest rate:\n");
	scanf("%lf, &rate");

	printf("Enter the desired monthly payment:\n");
	scanf("%lf", &payment);

	while (principle > 0){
		interest = principle * rate;
		principle = principle + interest - payment;
		printf("%d%5.2f%6.2f%5.2f\n", month, interest, payment, principle);
		month ++;

	if (payment >= principle){
	interest = principle * rate;
	payment = principle + interest;
	principle = payment - payment;
	
	printf("%d%5.2f%6.2f%6.2f", month, interest, payment, payment);
	}
}
}

