#include <iostream>
#include <cstring>
#include "golf.h"

using std::cout;
using std::cin;
using std::endl;

void setgolf(golf& g, const char * name, int hc)
{
strcpy(g.fullname, name);
g.handicap = hc;
}

int setgolf(golf& g)
{
cout << "Please input fullname: ";
cin.getline(g.fullname, len);
cout << "handicap: ";
cin >> g.handicap;
cin.get();
if(strlen(g.fullname)==0)
return 0;
else
return 1;
}

void handicap(golf& g, int hc)
{
g.handicap = hc;
}

void showgolf(const golf& g)
{
cout << "fullname: " << g.fullname << endl << "handicap: " << g.handicap << endl;
}
