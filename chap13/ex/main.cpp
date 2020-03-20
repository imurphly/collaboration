#include "TableTennisPlayer.h"
#include <iostream>

using namespace std;

int main()
{

{
Brass piggy("Port", 381299, 4000.00);
BrassPlus hoggy("Hogg", 382288, 3000.00);
Brass *h = &hoggy;
cout << piggy ;
cout<< hoggy;
hoggy.Deposite(1000.00);
cout << piggy << hoggy;
piggy.Withdraw(4200.0);
cout << piggy << hoggy;
hoggy.Withdraw(4200.00);
cout << piggy << hoggy;
h->Withdraw(200.00);
cout << *h;

}

/*
{
TableTennisPlayer tp1("Yan", "Liu", true);
RatedPlayer rp1(67,"Yuanhang", "Wang", true);
RatedPlayer rp2(1212, tp1);
cout << tp1 << rp1 << rp2;
rp1.ResetTable(false);
cout << rp1;
TableTennisPlayer& rt=rp1;
TableTennisPlayer* pt=&rp2;
rt.Name();
pt->Name();
}
*/

return 0;
}
