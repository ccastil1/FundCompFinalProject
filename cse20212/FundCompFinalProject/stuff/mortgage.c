#include <stdio.h>
#include <math.h> 
int main ()
{
	double payment;
	double rate;
	double interest;
	double balance;
	double principal;
	unsigned int month;

	printf("Enter the principal amount:\n");
	scanf("%s", principal);
	
	printf("Enter the interest rate:\n");
	scanf("%s", rate);	

	printf("Enter your desired monthly payment:\n");
	scanf("%s", payment);
	printf("%5s%8s%9s%9s\n", "Month", "Payment", "Interest", "Balance");
	
	for ( month = 1; month <= 10; ++month) {

	    interest = balance * (rate/1200);
	    balance = (principal + interest) - payment;
	    printf("%2u%9u%12u%9u\n", month, payment, interest, balance);
	}
}
