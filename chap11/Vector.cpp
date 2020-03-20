#include <cmath>
#include "Vector.h"

using std::sqrt;
using std::cos;
using std::sin;
using std::atan;
using std::atan2;
using std::cout;
using std::endl;

namespace VECTOR
{
const double rad_to_reg = 45.0/atan(1.0);
void Vector::set_x()
{x = mag*cos(ang);}

void Vector::set_y()
{x = mag*sin(ang);}

void Vector::set_mag()
{mag = sqrt(x*x + y*y);}

void Vector::set_ang()
{
if((x==0.0)&&(y==0.0))
ang =0.0;
else
ang = atan2(y, x);
}

Vector::Vector()
{
x=y=mag=ang=0.0;
mode = RECT;
}

Vector::Vector(double a, double b, Mode form)
{
mode = form;
if(form == RECT)
{
x = a;
y = b;
set_mag();
set_ang();
}
else if(form == POL)
{
mag = a;
ang = b/rad_to_reg;
set_x();
set_y();
}
else
{
cout << "The mode isn't explicite. Set vector to 0.\n";
x=y=mag = ang = 0.0;
mode = RECT;
}
}

Vector::~Vector()
{

}

void Vector::reset(double a, double b, Mode form)
{
mode = form;
if(form == RECT)
{
x = a;
y = b;
set_mag();
set_ang();
}
else if(form == POL)
{
mag = a;
ang = b/rad_to_reg;
set_x();
set_y();
}
else
{
cout << "The mode isn't explicite. Set vector to 0.\n";
x=y=mag = ang = 0.0;
mode = RECT;
}
}

void Vector::polar_mode()
{mode = POL;}

void Vector::rect_mode()
{mode = RECT;}

Vector Vector::operator+(const Vector & b) const
{
return Vector(x+b.x, y+b.y);
}

Vector Vector::operator-(const Vector & b) const
{
return Vector(x-b.x, y-b.y);
}

Vector Vector::operator-() const
{
return Vector(-x, -y);
}

Vector Vector::operator*(double n) const
{
return Vector(x*n, y*n);
}

Vector operator*(double n, const Vector & a)
{
return a*n;
}

std::ostream & operator<<(std::ostream & os, const Vector & v)
{
if(v.mode == Vector::RECT)
{os<< "x, y: " << v.x << ", " << v.y << endl;}
else if(v.mode == Vector::POL)
{os << "mag, ang: " << v.mag << ", " << v.ang*rad_to_reg << endl;}
else
{os << "Vector mode is invalid.\n";}
return os;
}

 };

