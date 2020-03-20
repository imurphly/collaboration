#include <iostream>
#include <utility>
#include "Useless.h"

using std::cout;
using std::endl;
int Useless::ct = 0;

void Useless::ShowObject() const
{
cout << "Number of element: " << n << endl;
cout << "Object address: " << (void*)pc << endl;
}


Useless::Useless()
{
++ct;
n = 0;
pc = nullptr;
cout << "Default constrctor.\n";
}

Useless::Useless(int k): n(k)
{
++ct;
pc = new char[n];
cout << "explicit constructor.\n";
}

Useless::Useless(int k, char ch):n(k)
{
++ct;
pc = new char[n];
for(int i = 0; i < n; ++i)
pc[i] = ch;
cout << "constructor.\n";
}

Useless::Useless(const Useless& f): n(f.n)
{
++ct;
pc = new char[n];
for(int i = 0; i < n; ++i)
pc[i] = f.pc[i];
cout << "copy constructor.\n";
}


Useless::Useless(Useless&& f): n(f.n)
{
++ct;
f.n = 0;
pc = f.pc;
f.pc = nullptr;
cout << "move constructor.\n";
}


Useless::~Useless()
{
delete [] pc;
cout << "destroy the object.\n";
}

Useless Useless::operator+(const Useless& f) const
{
cout << "Now enter the operator+: \n";
Useless temp = Useless(n + f.n);
for(int i = 0; i< n; ++i)
temp.pc[i] = pc[i];
for(int i=n; i<temp.n; ++i)
temp.pc[i] = f.pc[i-n];
cout << "Leaving operator+. "  << endl;
return temp;
}


Useless Useless::operator=(const Useless& f)
{
if(this==&f)
return *this;
delete []pc;
n = f.n;
pc = new char[n];
for(int i = 0; i< n; ++i)
pc[i] = f.pc[i];
cout << "assignment.\n";
return *this;
}


Useless Useless::operator=(Useless&& f)
{
if(this == &f)
return *this;
delete []pc;
n = f.n;
f.n = 0;
pc = f.pc;
f.pc = nullptr;
cout << "Move assignment.\n";
return *this;
}


void Useless::ShowData() const
{
if(n==0)
cout << "This is empty object.\n";
else
for(int i=0; i< n;++i)
cout << pc[i] << " ";
cout << "\n";
}
