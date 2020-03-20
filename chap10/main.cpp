#include <iostream>
#include "BankAccount.h"

using namespace std;

int main()
{
/*
{
BankAccount bank1;
bank1.Show();
BankAccount bank2((char*)"Liu Yan", (char*)"Murphly", 20000.0);
bank2.Show();
double cash = 1314.520;
bank1.Deposite(cash);
bank1.Show();
bank2.Withdraw(cash);
bank2.Show();
}

{
Person one;
Person two("Smythecraft");
Person three("Monnet", "Dominique");
one.Show();
one.FormalShow();
two.Show();
two.FormalShow();
three.Show();
three.FormalShow();
}

{
int hc = 5;
Golf ann("Ann Birdfree", 24);
ann.Show();
Golf andy;
andy.Show();
andy.Handicap(hc);
andy.Show();
}


{
using namespace SALES;
{
const int n = 4;
double a[n] {13.2, 60.67, 32.80, 0.0};
Sales s1;
Sales s2(a, n);
s1.ShowSales();
s2.ShowSales();
}
}


{
Stack s;
double total = 0.0;
customer temp {"temp", 0.0};
customer c[4] {{"liu", 10.0},{"yan", 20.0},{"yuan", 30.0},{"hang", 40.0}};
for(int i=0; i < 4; ++i)
{
s.push(c[i]);
}
for(int i=0; i < 4; ++i)
{
s.pop(temp);
total += temp.payment;
}
cout << "total: " << total << endl;
}
*/


{
Move m1(2, 3);
//m1.ShowMove();
cout << m1;
Move m2(3,4);
Move m = m1 + m2;
//m.ShowMove();
//m2.ShowMove();
cout << m << m2;
m2.Reset(10,10);
//m2.ShowMove();
cout << m2;
}

/*
{
int ci =60;
Plorg pl1("pl1");
pl1.Show();
pl1.FixCi(ci);
pl1.Show();
}


{
List l1;
customer temp {"temp", 0.0};
customer c[4] {{"liu", 10.0},{"yan", 20.0},{"yuan", 30.0},{"hang", 40.0}};
cout << "is l1 empty? " << boolalpha << l1.isempty() << endl;
for(int i=0; i < 4; ++i)
{
l1.push(c[i]);
}
cout << "is l1 full? " << boolalpha << l1.isfull() << endl;
l1.visit(2, PrintCus);
}
*/

return 0;
}
