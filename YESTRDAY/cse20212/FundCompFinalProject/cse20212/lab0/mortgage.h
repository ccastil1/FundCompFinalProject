//Celeste Castillo

#include <iostream>
using namespace std;

class Mortgage{             //establishes the class Mortgage
public:
    Mortgage(float newPrincipal = 100000, float newRate = 5.0, float newPayment = 500);      //default constructor with fall-back values
    void credit(double value);                  //credit function deducts the value from the remanining principal
    double getPrincipal();                      //getPrincipal function returns the current remaining principal because the Principal value is in the private part of the class
    void amortize();                            //amortize function calculates and displays an amortization table
    
private:
    float Principal;                            //remaining principal value owed
    float Rate;                                 //annual interest rate
    float Payment;                              //desired monthly payment
};

Mortgage::Mortgage(float newPrincipal, float newRate, float newPayment){        //constructor
    
    Principal = newPrincipal;                                                   //since the Principal is in the private part of the class, it is hidden so the newPayment returns the value; the same goes for Rate and Payment.
    Rate = newRate/100;
    Payment = newPayment;

    double amount = (newRate/12 * newPrincipal) - newPayment;           //error handling- if the payment/rate produces an invalid(negative) amount, an error message will display
    if(amount < 0)
    {
        cout << "Error! This is an invalid payment plan." << endl;
        while(1){}
    }
}

void Mortgage::credit(double value){                //credit function deducts value from Principal
    Principal -= value;
}

double Mortgage::getPrincipal(){                    //getPrincipal function returns value of Principal
    return(Principal);
}

void Mortgage::amortize(){                          //amortize function creates amortization table
    int month = 0;
    double interest;
    cout << "Month\tInterest\tPayment\tBalance" << endl;        //format the heading of the amortization table
    
    while(Principal > 0)                              //while loop uses the interest rate, principal, and payment to calculate the values for each month
    {
	month++;

        interest = Rate/12 * Principal;
        
        Principal += interest - Payment;
        
        if(Principal < 0)
        {
            Principal = 0;
        }
        
        cout << month << "\t" << Rate << "\t" "\t" << Payment << "\t" << Principal << endl;
        
     }
    cout << "You will pay off the mortgage in " << month << " months." <<endl;
}


