#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <initializer_list>
#include <utility>
#include <list>
#include <iterator>
using namespace std;
void Show() {}

template<typename T>
void Show(const T& value)
{
cout << value << "\n";
}

template<typename T, typename... Args>
void Show(T value, const Args&... args)
{
cout << value << ", ";
Show(args...);
}

//ex1
template <typename T>
T average_list(const initializer_list<T>& li)
{
T total=0.0;
int n = li.size();
if(n> 0)
{
for(auto p = li.begin(); p!=li.end(); ++p)
{
total +=*p;
 }
return total/n;
 }
else
return 0.0;
}

//ex2
class Cpmv
{
public:
struct Info
{
std::string qcode;
std::string zcode;
 };
private:
Info *pi;
public:
Cpmv();
Cpmv(std::string q, std::string z);
Cpmv(Cpmv& cp);
Cpmv(Cpmv&& mv);
~Cpmv();
Cpmv& operator=(const Cpmv& cp);
Cpmv& operator=(Cpmv && mv);
Cpmv  operator+(const Cpmv& obj) const;
void Display() const;
};

Cpmv::Cpmv()
{
pi = new Info;
pi->qcode = "Q";
pi->zcode = "Z";
cout << "default constructor: " << endl;
}

Cpmv::Cpmv(std::string q, std::string z)
{
pi = new Info;
pi->qcode = q;
pi->zcode = z;
cout << "Constructor: " << endl;
}


Cpmv::Cpmv( Cpmv& cp)
{
pi = new Info;
pi->qcode = (cp.pi)->qcode;
pi->zcode = (cp.pi)->zcode;
cout << "Copy constructor: " << endl;
}


Cpmv::Cpmv(Cpmv&& mv)
{
pi = mv.pi;
mv.pi = nullptr;
cout << "Move Constructor: " << endl;
}

Cpmv::~Cpmv()
{
delete pi;
cout << "Destroy object." << endl;
}

Cpmv& Cpmv::operator=(const Cpmv& cp)
{
if(this == &cp)
return *this;
delete pi;
pi = new Info;
pi->qcode = (cp.pi)->qcode;
pi->zcode = (cp.pi)->zcode;
cout << "assignment: " << endl;
return *this;
}

Cpmv& Cpmv::operator=(Cpmv && mv)
{
if(this == &mv)
return *this;
delete pi;
pi = mv.pi;
mv.pi = nullptr;
cout << "Move assignment: " << endl;
return *this;
}

Cpmv Cpmv::operator+(const Cpmv& obj) const
{
string _qcode = pi->qcode + (obj.pi)->qcode;
string _zcode = pi->zcode + (obj.pi)->zcode;
Cpmv temp(_qcode, _zcode);
return temp;
}

void Cpmv::Display() const
{
cout << pi->qcode << " " << pi->zcode << endl;
}

//ex3
long double sum_value() {return 0.0;}
template<typename T>
long double sum_value(T value)
{return (long double)value;}

template <typename T, typename... Args>
long double sum_value(T value, Args... args)
{return (long double)(value + sum_value(args...));}


int main()
{


{
auto outin = [](int x){cout << x << " ";};
int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
list<int> yad(vals, vals+10);
list<int> etc(vals, vals+10);
cout << "Origin: " << endl;
for_each(yad.begin(), yad.end(), outin);
cout << endl;
for_each(etc.begin(), etc.end(), outin);
cout << endl;
yad.remove_if([](int x){return x<100;});
etc.remove_if([](int x){return x< 200;});
cout << "Trimited list: " << endl;
for_each(yad.begin(), yad.end(), outin);
cout << endl;
for_each(etc.begin(), etc.end(), outin);
cout << endl;
}

/*
//ex3
{
cout << sum_value(3) << endl;
cout << sum_value(3, 4.0, 6.5) << endl;
}


//ex2
{
Cpmv m1("qx56", "z370");
m1.Display();
Cpmv m2 = Cpmv("qogahog", "zatabat");
m2.Display();
Cpmv m3(m2);
m3.Display();
m1 = m2;
m1.Display();
m1 = Cpmv("qu22uq", "za88az");
m1.Display();
m1 = m2 + m1;
m1.Display();
Cpmv m4(m2 + m3);
m4.Display();
}

//ex1
{
using namespace std;
auto q = average_list( {15.4, 10.7, 9.0});
cout << q << endl;
cout << average_list( {20, 30, 19, 17, 45, 38} ) << endl;
}


{
Show(5);
Show(6, 'c', 10.0);
}


//lambda
{
const int size = 1000;
vector<int> num(size);
generate(num.begin(), num.end(), rand);
cout << "Sample size: " << num.size() << "\n";
int count3 =0,count13 = 0;
for_each(num.begin(), num.end(), [&](int x){count3 += x%3==0; count13 += x%13==0;});
cout << "3: " << count3 << "\n";
cout << "13: " << count13 << "\n";
}
*/
return 0;
}
