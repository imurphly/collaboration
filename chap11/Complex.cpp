#include "Complex.h"

Complex::Complex(double a, double b)
{
real = a;
imag = b;
}

Complex::~Complex() {}

Complex Complex::operator+(const Complex & c) const
{
Complex temp;
temp.real = real + c.real;
temp.imag = imag + c.imag;
return temp;
}

Complex Complex::operator-(const Complex & c) const
{
Complex temp;
temp.real = real - c.real;
temp.imag = imag - c.imag;
return temp;
}


Complex Complex::operator*(const Complex & c) const
{
Complex temp;
temp.real = real*c.real - imag*c.imag;
temp.imag = real*c.imag + imag*c.real;
return temp;
}

Complex Complex::operator~() const
{
Complex temp;
temp.real = real;
temp.imag = -imag;
return temp;
}

Complex operator*(double x, const Complex & c)
{
Complex temp;
temp.real = x*c.real;
temp.imag = x*c.imag;
return temp;
}

std::ostream& operator<<(std::ostream& os, const Complex & c)
{
os << "a = (A, Bi) = (" << c.real << ", " << c.imag << "i)" <<std::endl; 
return os;
}

std::istream& operator>>(std::istream& is, Complex & c)
{
is >> c.real >> c.imag;
return is;
}

