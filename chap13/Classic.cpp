#include "Classic.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::strcpy;
using std::strlen;

//DMA
DMA::DMA(const char* l, int r):rating(r)
{
label = new char[strlen(l)+1];
strcpy(label, l);
}

DMA::DMA(const DMA& da):rating(da.rating)
{
label = new char[strlen(da.label)+1];
strcpy(label, da.label);
}

DMA& DMA::operator=(const DMA& da)
{
if(this == &da)
return *this;
delete [] label;
label = new char[strlen(da.label)+1];
strcpy(label, da.label);
rating = da.rating;
}

DMA::~DMA()
{
delete [] label;
}

void DMA::View() const
{
cout << label << ", " << rating; 
}

std::ostream& operator<<(std::ostream& os, const DMA& da)
{
os << da.label << ", " << da.rating;
return os;
}

//baseDMA
baseDMA::baseDMA(const char* l, int r):DMA(l, r) {}

//lacksDMA
lacksDMA::lacksDMA(const char *cr, const char* l, int r):DMA(l,r)
{
strcpy(color, cr);
}

lacksDMA::lacksDMA(const char *cr, const DMA& da):DMA(da)
{
strcpy(color, cr);
}

lacksDMA& lacksDMA::operator=(const lacksDMA& la)
{
if(this ==&la)
return *this;
DMA::operator=(la);
strcpy(color, la.color);
return *this;
}

void lacksDMA::View() const
{
DMA::View();
cout << " color: " << color; 
}

std::ostream& operator<<(std::ostream& os, const lacksDMA& da)
{
os << (DMA&)da;
os <<" color: " << da.color;
return os;
}


hasDMA::hasDMA(const char *sty, const char* l, int r):DMA(l,r)
{
style = new char[strlen(sty)+1];
strcpy(style, sty);
}

hasDMA::hasDMA(const char *sty, const DMA& da):DMA(da)
{
style = new char[strlen(sty)+1];
strcpy(style, sty);
}

hasDMA& hasDMA::operator=(const hasDMA& ha)
{
if(this == &ha)
return *this;
DMA::operator=(ha);
delete []style;
style = new char[strlen(ha.style)+1];
strcpy(style, ha.style);
}

void hasDMA::View() const
{
DMA::View();
cout << " style: " << style;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& da)
{
os<< (DMA&)da;
os << " style: " << da.style;
return os;
}



//Cd
Cd::Cd(char *s1, char* s2, int n, double x): selections(n), playtime(x)
{
performance = new char[strlen(s1)+1];
strcpy(performance, s1);
strcpy(label, s2);
}

Cd::Cd(const Cd& d):selections(d.selections), playtime(d.playtime)
{
performance = new char[strlen(d.performance)+1];
strcpy(performance, d.performance);
strcpy(label, d.label);
}

void Cd::Report() const
{
cout << performance << ", " << label << ", " << selections << " selections, can play" << playtime << " minutes.\n";
}

Cd& Cd::operator=(const Cd& d)
{
if(this == &d)
return *this;
performance = new char[strlen(d.performance)+1];
strcpy(performance, d.performance);
strcpy(label, d.label);
selections = d.selections;
playtime = d.playtime;
return *this;
}

//Classic
Classic::Classic(char *s, char *s1, char* s2, int n, double x):Cd(s1, s2,n,x)
{
str = new char[strlen(s)+1];
strcpy(str, s);
}

Classic::Classic(const Cd& d, char *s): Cd(d)
{
str = new char[strlen(s)+1];
strcpy(str, s);
}

Classic::Classic(const Classic& c): Cd(c)
{
str = new char[strlen(c.str)+1];
strcpy(str, c.str);
}

void Classic::Report() const
{
Cd::Report();
cout << "It has popular string: " << str << endl;
}

Classic& Classic::operator=(const Classic& c)
{
if(this == &c)
return *this;
Cd::operator=(c);
str = new char[strlen(c.str)+1];
strcpy(str, c.str);
return *this;
}

