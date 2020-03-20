#include <iostream>
#include <fstream>
#include <cstdlib> // rand(), srand() prototypes
#include <ctime> // time() prototype
#include "Vector.h"
#include "Complex.h"
int main()
{
/*
{
using namespace std;
using VECTOR::Vector;
srand(time(0)); // seed random-number generator
double direction;
Vector step;
Vector result(0.0, 0.0);
unsigned long steps = 0;
double target;
double dstep;
cout << "Enter target distance (q to quit): ";
while (cin >> target)
{
cout << "Enter step length: ";
if (!(cin >> dstep))
break;
while (result.magval() < target)
{
direction = rand() % 360;
step.reset(dstep, direction, Vector::POL);
result = result + step;
steps++;
}
cout << "After " << steps << " steps, the subject "
"has the following location:\n";
cout << result << endl;
result.polar_mode();
cout << " or\n" << result << endl;
cout << "Average outward distance per step = "
<< result.magval()/steps << endl;
steps = 0;
result.reset(0.0, 0.0);
cout << "Enter target distance (q to quit): ";
}
cout << "Bye!\n";
cin.clear();
while (cin.get() != '\n')
continue;
}
*/

{
using namespace std;
Complex a(3.0, 4.0); // initialize to (3,4i)
Complex c;

cout << "Enter a complex number (q to quit):\n";
while (cin >> c)
{
cout << "c is " << c << endl;
cout << "complex conjugate is " << ~c << endl;
cout << "a is " << a << endl;
cout << "a + c is " << a + c << endl;
cout << "a - c is " << a - c << endl;
cout << "a * c is " << a * c << endl;
cout << "2 * c is " << 2 * c << endl;
cout << "Enter a complex number (q to quit):\n";
}
cout << "Done!\n";

}

return 0;
}
