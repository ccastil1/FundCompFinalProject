#include <iostream>
using namespace std;

int main()
{
    int n;
    double pi=4.0;
    
    cout << "Enter the number of terms in the series: ";
    cin >> n;
    
    while (n<2)
    {
        cout << "Error! Number of terms must be greater than or equal to 2.\n";
        cout << "Please enter the number of terms in the series: "<< endl;
        cin >> n;
    }

    for(int i=1; i<=n; i++)
    {
       // double pi;
 /*       if (n == 1)
        {
            pi = ;
        }
   */
        if (i%2 == 0)
        {
            pi = 4 - (4.0/(2*i-1));
     //       cout << "Estimate after "<< n << " terms is " << pi << ".\n" << endl;

        }
        
        else
        {
            pi = 4 + (4.0/(2*i-1));
    //        cout << "Estimate after "<< n << " terms is " << pi << ".\n" << endl;

        }
    }
            cout << "Estimate after "<< n << " terms is " << pi << ".\n" << endl;

    return 0;
}
