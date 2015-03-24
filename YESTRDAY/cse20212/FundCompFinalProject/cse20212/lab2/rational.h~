#ifndef Rational_H
#define Rational_H
#include <iostream>
using namespace std;

class Rational{
   public:
	Rational(int = 0, int = 1);
	Rational& operator+=(const Rational&);
	Rational& operator-=(const Rational&);
	Rational& operator*=(const Rational&);
	Rational& operator/=(const Rational&);
	void Rational& operator!(const Rational&);
	void reduce();
	void print();
	
   private:
	int num;
	int den;
	int gcd(int a, int b);
};
#endif
