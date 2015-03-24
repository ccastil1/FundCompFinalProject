//Celeste Castillo

#include <iostream>
#include "mortgage.h"
using namespace std;

int main(){
    Mortgage first(10000, 5.0, 500);        //non-default constructor initialization
    Mortgage second;                        //constuctor
        
    second.credit(10000);                   //sets value of the credit deduction to $10,000
    cout << "Current balance after crediting second mortgage 10K: " << second.getPrincipal() <<endl;    //displays the balance after the credit
    
    cout << "Amortization schedule for first mortgage: "<<endl;     //displays the amortization schedule
    
    first.amortize();                                               //call to the amortize function
}

