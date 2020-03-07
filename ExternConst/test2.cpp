#include <iostream>
#include "test.h"

using std::cout;
using std::cin;
using std::endl;

extern const int fingers = 10;

void Show(int *a)
{
//extern const int fingers;
for(int i = 0; i < fingers; ++i)
{
cout << *a << endl;
}
}

