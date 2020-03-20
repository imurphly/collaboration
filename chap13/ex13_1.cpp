#include <iostream>
#include "Classic.h" // which will contain #include cd.h
void Bravo(const Cd & disk);

using namespace std;
int main()
{

/*
{
baseDMA shirt("Portabelly", 8);
lacksDMA balloon("red", "Blimpo", 4);
hasDMA map("Mercator", "Buffalo Keys", 5);
cout << shirt << endl;
cout << balloon << endl;
cout << map << endl;
lacksDMA balloon2(balloon);
hasDMA map2;
map2 = map;
cout << balloon2 << endl;
cout << map2 << endl;
DMA * pts[3];
pts[0] = &shirt;
pts[1] = &balloon;
pts[2] = &map;
for (int i = 0; i < 3; i++)
cout << *pts[i] << endl;
for (int i = 0; i < 3; i++)
{
pts[i]->View();
cout << endl;
}
//std::cin.get();
}
*/

{
using std::cout;
Cd c1("Beatles", "Capitol", 14, 35.5);
Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
"Alfred Brendel", "Philips", 2, 57.17);
Cd *pcd = &c1;
cout << "Using object directly:\n";
c1.Report(); // use Cd method
c2.Report(); // use Classic method
cout << "Using type cd * pointer to objects:\n";
pcd->Report(); // use Cd method for cd object
pcd = &c2;
pcd->Report(); // use Classic method for classic object
cout << "Calling a function with a Cd reference argument:\n";
Bravo(c1);
Bravo(c2);
cout << "Testing assignment: ";
//Classic copy;
Cd copy;
copy = c2;
copy.Report();
//std::cin.get();
}



return 0;
}
void Bravo(const Cd & disk)
{
disk.Report();
}
