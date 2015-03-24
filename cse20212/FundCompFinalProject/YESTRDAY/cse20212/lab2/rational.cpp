#include <iostream>
#include "rational.h"
using namespace std;
using namespace ostream;

Rational::Rational(int n, int d)
{
	if(d == 0)
	{
		cout << "Error! Invalid denominator!" << endl;
	//	exit(0);
	}
	else
	{
		num = n;
		den = d;
	}
}

void Rational::print()
{
	cout << num << "/" << den << endl;
}

void Rational::reduce()
{
	int factor = gcd(num, den);
	num = num/factor;
	den = den/factor;
}

Rational& Rational::operator+=(const Rational& f)
{
	num = num*f.den+den*f.num;
	den = den*f.den;
	return *this;
}

Rational& Rational::operator-=(const Rational& f)
{
	*this += (-f)l
	return *this;
}

Rational& Rational::operator*=(const Rational& f)
{
	num = num*f.num;
	den = den*f.den;
	return *this;
}

Rational& Rational::operator/=(const Rational& f)
{
	*this *= (*f);
	return *this;
}

Rational& Rational::operator!(const Rational& f)
{
	return Rational(den, num);
}
