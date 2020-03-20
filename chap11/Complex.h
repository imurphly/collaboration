#ifndef _COMPLEX_H
#define _COMPLEX_H
#include <iostream>
class Complex
{
private:
double real;
double imag;
public:
Complex(double a =0, double b = 0);
~Complex();
Complex operator+(const Complex & c) const;
Complex operator-(const Complex & c) const;
Complex operator*(const Complex & c) const;
Complex operator~() const;
friend Complex operator*(double x, const Complex & c);
friend std::ostream& operator<<(std::ostream& os, const Complex & c);
friend std::istream& operator>>(std::istream& is, Complex & c);
};
#endif
