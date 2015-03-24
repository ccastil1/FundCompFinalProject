#include "rational.h"
#include <iostream>
using namespace std;
using namespace ostream;

int main(){

	cout << "Enter the first numerator: " << endl;
	cin << firstNum;
	
	cout << "Enter the first denominator: " << endl;
	cin << firstDen;

	cout << "Enter the second numerator: " << endl;
	cin << secondNum;
	
	cout << "Enter the second denominator: " << endl;
	cin << secondDen;

	Rational a(firstNum, firstDen);
	Rational b(secondNum, secondDen);

	cout << "Enter the operation(addition, subtraction, multiplication, division, all) would you like to perform on these fractions: " << endl;
	cin << operation;

	if(operation == "addition")
	{
		cout << "The sum of these two rationals is: " << a+=b << endl;
	}
	else if(operation == "subtration")
	{
		cout << "The difference between these two rationals is: " << a-=b << endl;
	}	
	else if(operation == "multiplication")
	{
		cout << "The product of these two rationals is: " << a*=b << endl;
	}	
	else if(operation == "division")
	{	
		cout << "The quotient of these two rationals is: " << a/=b << endl;
	}
	else if(operation == "all")
	{
		cout << "The sum of these two rationals is: " << a+=b << endl;
		cout << "The difference between these two rationals is: " << a-=b << endl;
		cout << "The product of these two rationals is: " << a*=b << endl;
		cout << "The quotient of these two rationals is: " << a/=b << endl;
	}
}
