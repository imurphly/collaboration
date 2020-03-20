#include "StringBad.h"
using std::cout;
using std::cin;
using std::endl;

void callme1(StringBad& rsb);
void callme2(StringBad sb);

int main()
{

{
Stack st(3); // create a stack of po numbers
unsigned long temp;
char c;
cout << "Please enter A to add a PO,\n"
<< "P to process a PO, and Q to quit.\n";
while (cin >> c && (c = toupper(c)) != 'Q')
{
while (cin.get() != '\n')
continue;
if (c != 'A' && c != 'P')
{
cout << "Please respond with A, P, or Q: ";
continue;
}
switch (c)
{
case 'A': if (st.isfull())
cout << "stack already full\n";
else
{
cout << "Enter PO number: ";
cin >> temp;
st.push(temp);
}
break;
case 'P': if (st.isempty())
cout << "stack already empty\n";
else {
st.pop(temp);
cout << "Processing PO " << temp << '\n';
}
break;
default: cout << "Whoops! Programming error!\n";
}
cout << "Please enter A to add a customer,\n"
<< "P to process a customer, and Q to quit.\n";
}
cout << "Done!\n";
//cin.get();
//cin.get();
}

/*
{
const int STKS = 4;
using std::ios_base;
// create an array of initialized objects
Stock stocks[STKS] = {
Stock("NanoSmart", 12, 20.0),
Stock("Boffo Objects", 200, 2.0),
Stock("Monolithic Obelisks", 130, 3.25),
Stock("Fleep Enterprises", 60, 6.5)
};
cout.precision(2); // #.## format
cout.setf(ios_base::fixed, ios_base::floatfield); // #.## format
cout.setf(ios_base::showpoint); // #.## format
cout << "Stock holdings:\n";
int st;
for (st = 0; st < STKS; st++)
cout << stocks[st];
Stock top = stocks[0];
for (st = 1; st < STKS; st++)
top = top.topval(stocks[st]);
cout << "\nMost valuable holding:\n";
cout << top;
//std::cin.get();
}



{
StringBad headline1("Celery ");
StringBad headline2("stack");
StringBad sports = headline1 + headline2;
cout << "headline1: " << headline1<< endl;
cout << "headline2: " << headline2 << endl;
cout << "sports: " << sports << endl;

headline1.Stringlower();
headline2.Stringupper();
cout << "sports have " << sports.CharSearch('a') << " a.\n";
cout << "headline1: " << headline1<< endl;
cout << "headline2: " << headline2 << endl;
cout << "sports: " << sports << endl;

}


{
Cow c1("Liu yan", "ice cream", 46.8);
Cow c2;
Cow c3(c1);
Cow c4 = c2;
c3.show();
c4.show();
}


{
cout << "Starting an inner block.\n";
StringBad headline1("Celery stack");
StringBad headline2("Celery stack");
StringBad sports("Celesy stack");
StringBad sport1 = "Celesy";

cout << "Plese input sports: ";
cin >> sports;

cout << "headline1: " << headline1<< endl;
cout << "headline2: " << headline2 << endl;
cout << "sports: " << sports << endl;
cout << "sport1: " << sport1 << endl;
callme1(headline1);
cout << "headline1: " << headline1 << endl;

//使用new和delete来管理类成员时，函数值传递类对象，用类对象初始化另一个对象都会出现问题。
//解决方法是深拷贝
callme2(headline2);
cout << "headline2: " << headline2 << endl;
cout << "Initialize one object to another: \n";
StringBad sailor = sports;
cout << "sailor: " << sailor << endl;
cout << "Assign one object to another.\n";

//默认复制运算重载也带来了问题
StringBad knot;
knot = headline1;
cout << "knot: " << knot << endl;

cout << (headline1==headline2);
cout << endl;
cout <<  (headline2<sports);
cout << endl;
cout << (sports > sport1);
cout << endl;
cout << "headline1[2]: " << headline1[2] << endl;
cout << "Creat " << StringBad::HowMany() << " object total.\n";
 
}
*/

return 0;
}

void callme1(StringBad& rsb)
{
cout << "String passed by reference: \n";
cout << "        \"" << rsb << "\" \n";
}


void callme2(StringBad sb)
{
cout << "String passed by value: \n";
cout << "        \"" << sb << "\" \n";
}
