#include <iostream>
using namespace std;


double estimate(double i);


int main()
{
    long int n=0;
    double sum=0;
    cout << "Please enter the number of terms in the series: ";
    cin >> n;
    
    while(n<2)
    {
        cout << "Error! Number of terms must be greater than or equal to 2.\n";
        cout << "Please enter the number of terms in the series: ";
        cin >> n;
    }
    
    for(long int i=1; i<=n; i++)
    {
        sum = sum + estimate(static_cast<double>(i));
    }
    cout << "Estimate after " << n << " terms is " << sum << ".\n" << endl;
    
}

double estimate(double i)
{
    double initial = 1/(2*i-1);
    
    if(static_cast<long int>(i)%2 == 0)
    {
        return -4*initial;
        cout << "even";
    }
    
    else
    {
        return 4*initial;
    }
    
}

