#include <iostream>
#include "test.h"

using std::cout;
using std::cin;
using std::endl;


int Get(int a)
{
extern const int fingers;
cout << "The value of fingers: " << fingers << endl;
cout << "Enter the value of a: ";
cin >> a;
return a;
}
