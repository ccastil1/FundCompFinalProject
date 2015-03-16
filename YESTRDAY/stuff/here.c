#include <stdio.h>
int main ()
{
double principle;                                                                           
    double annual_rate;                                         
    double monthly_rate;                                        
    double interest;                                    
    double payment;                                             
    int month = 1;                                              
 
    printf("Enter principle amount of the loan:\n");             
    scanf("%lf", &principle);                                    
    printf("Enter annual interest rate (in decimal form):\n");   
    scanf("%lf", &annual_rate);                                  
    printf("Enter the payment to be paid monthly:\n");           
    scanf("%lf", &payment);                                      
     
    printf("\nPayment schedule for $%0.2f loan\nat %0.4f annual interest rate\nand monthly payment of $%0.2f\n",principle, annual_rate, payment);
    printf("\nMonth\tPayment\t\tInterest\tBalance\n");
 
    monthly_rate = annual_rate / 12;                
 
 
    while (principle > 0)                                        
    {
        interest = principle * monthly_rate;            
        principle = principle + interest - payment;     
             
        printf("%d\t%6.2f\t\t%6.2f\t\t%6.2f\n", month, payment, interest, principle);
        month++;                                                
 
 
        if (payment >= principle )                               
        {
        interest = principle * monthly_rate;            
        payment = principle + interest;                 
        principle = payment - payment;                          
 
 
        printf("%d\t%6.2f\t\t%6.2f\t\t%6.2f", month, payment, interest, principle); 
        }
         
    }
 
}
