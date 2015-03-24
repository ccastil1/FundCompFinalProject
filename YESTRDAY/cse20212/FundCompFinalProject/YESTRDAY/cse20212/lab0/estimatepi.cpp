#include <iostream>
using namespace std;

double estimate(double i);

int main()
{
    int n=0;		//initial declarations and initializations of the variables used for the number of terms in the series and the estimation for the value of pi
    double sum=0;

    cout << "Please enter the number of terms in the series: ";		//asking the user to input their desired number of terms
    cin >> n;								//assigning the desired number of terms to the variable n
    
    while(n<2)								//the while loop is established to alert the user of an error if their desired number of terms is not within the appropriate range and prompts them to re-enter another value
    {
        cout << "Error! Number of terms must be greater than or equal to 2.\n";
        cout << "Please enter the number of terms in the series: ";
        cin >> n;
    }
    
    for(int i=1; i<=n; i++)					//the for loop uses the int values between 1 and n to calculate the estimated value of pi for the given n
    {
        sum = sum + estimate(static_cast<double>(i));		//static cast is used because in the function "estimate", i is used as a double, but in order to calculate the modulus, used to determine if the term is even or odd, the value of i needs to be int
    }
    cout << "Estimate after " << n << " terms is " << sum << ".\n" << endl;		//prints the value of the pi estimation to the user
}

double estimate(double i)				//this function declares the pattern for estimating pi(1/(2*i-1)) and uses if/else statements to determine whether or not to multiply by -1, which allow the summation to alternate between positive and negative elements
{
    double initial = 4/(2*i-1);
    
    if(static_cast<long int>(i)%2 == 0)
    {
        return -1*initial;
    }
    
    else
    {
        return initial;
    }
}


