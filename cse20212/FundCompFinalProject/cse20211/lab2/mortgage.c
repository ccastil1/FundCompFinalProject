#include <stdio.h>
int main ()
{	//Celeste Castillo CSE 20211 Lab 2
    double principle, time, monthtime,  annual_rate, monthly_rate, interest, payment, totalpay;
    int month = 0; //initialize month counter at 0

	printf("Enter principle amount of the loan:\n"); //ask the user the principle loan amount
	scanf("%lf", &principle); //assign that amount to the variable "principle"
   
 	printf("Enter yearly interest rate (in decimal form):\n"); //ask the user the interest rate
	scanf("%lf", &annual_rate); 			//assign the value to "annual_rate"
		if(annual_rate <= 0)  		//if user enters invalid interest, error message, then restart
	   	       {printf("User error. Please try again.\n");
	   		printf("Enter the annual interest rate:\n");
	   		scanf("%lf", &annual_rate);
		       }
		else
	  		annual_rate=annual_rate;
    
	printf("Enter the payment to be paid monthly:\n");
	scanf("%lf", &payment);

	printf("\nMonth\tPayment\t\tInterest\tBalance\n"); //setting up the format of the table; \t for tab
 
	monthly_rate = annual_rate / 12;

	totalpay=0; //initializing total payment at 0 before calculation

     while (principle > 0) 	//while loop to calculate continual interest, payment, and balance
      {
     	interest = principle * monthly_rate;  //if payment is too small, error, quit program
		if(payment< interest)
		  {printf("User error. Please try again");
		   break; 
		  }      

        if (payment >= principle )
           {
	    interest = principle * monthly_rate;
       	    payment = principle + interest;
	   }
	        principle = principle + interest - payment;

	totalpay+=payment;
	
	month++;
        
	printf("%d\t%5.2f\t\t%6.2f\t\t%6.2f\n", month, payment, interest, principle); //displaying numbers in table
  
      }

	time = month/12; //calculates number of years to pay off loan
	monthtime = month%12; //number of months to pay off loan
	printf("You paid a total of $%.2f over %.f years and %.f months.", totalpay, time, monthtime); //total amount paid 
													//and time taken to pay it off
}
