#include <iostream>
#include <cmath>
#include <string>
#include "Tv.h"
#include <stdexcept>

using namespace std;

//ex2
//throw-try-catch
class demo
{
private:
string word;
public:
demo( const std::string& str) { word = str; cout << "demo " << word << " created.\n";}
void Show() const {cout << "demo " << word << " lives.\n";}
~demo() {cout << "demo " << word << " destroyed.\n";}
};

class bad_hmseg: public logic_error
{
private:
double a;
double b;
public:
bad_hmseg(double x, double y): logic_error("logic hmean error\n"), a(x), b(y) {}
void report() {cout<< "a = -b, please input two number again: \n";}
};

double hmean(double x, double y)
{
if(x + y == 0)
//发出异常，相当与发特定信号弹
throw bad_hmseg(x, y);
return 2*x*y/(x+y);
//cout << "2*x*y/(x+y) = " << 2*x*y/(x+y) << endl;
}

class bad_gmesg: public logic_error
{
private:
double a;
double b;
public:
bad_gmesg(double x, double y): logic_error("logic gmean error\n"), a(x), b(y) {}
void report() {cout << "the number can't be less than 0. You can't compute any more.\n";}
//virtual const char* what() { return s;}
};

double gmean(double x, double y)
{
if(x < 0 || y < 0)
throw bad_gmesg(x, y);
return sqrt(x*y);
//cout << "sqrt(x*y) = " << sqrt(x*y) << endl;
}

double means(double x, double y)
{
double mn, hn, gn;
mn = (x + y)/2.0;
hn = hmean(x, y);
gn = gmean(x, y);
return (mn + hn + gn)/3.0;
}

int main()
{
demo d1("found in block in main");
double x, y;
while(cin >> x >> y)
try
{
//可能出现异常的代码块
double z = means(x, y);
cout << "means(x, y) = " << z << "\n";
}
catch(bad_hmseg& hg) //接收特定信号
{
//处理异常的部分
hg.report();
continue;
}
catch(bad_gmesg& bg)
{
bg.report();
cout << bg.what();
break;
}
d1.Show();
return 0;
}

/*
//ex1
int main()
{
Tv s42;
std::cout << "Initial settings for 42\" TV:\n";
s42.settings();
s42.onoff();
s42.channelup();
std::cout << "\nAdjusted settings for 42\" TV:\n";
s42.settings();
Remote grey;
grey.set_chan(s42, 10);
grey.volup(s42);
grey.volup(s42);
std::cout << "\n42\" settings after using remote\n";
s42.settings();
Tv s58(On);
s58.set_mode();
grey.set_chan(s58,28);
std::cout << "\n58\" settings:\n";
s58.settings();
//grey.show_style(); // check mode
//s58.rmode(grey); // change mode
//grey.show_style(); // recheck mode
s58.onoff(); // turn set off
//s58.rmode(grey); // try changing mode again
//grey.show_style(); // check result
//std::cin.get();
return 0;
}


//const_cast
void change(const int* pi, int n)
{
int *pc;
pc = const_cast<int *>(pi);
*pc -= n;
}

int main()
{
int pap1 = 38383;
const int pap2 = 2000;
cout << "pap1, pap2: " << pap1 << ", " << pap2 << endl;
change(&pap1, -103);
change(&pap2, -103);
cout << "pap1, pap2: " << pap1 << ", " << pap2 << endl;
return 0;
}

//throw-try-catch
class demo
{
private:
string word;
public:
demo( const std::string& str) { word = str; cout << "demo " << word << " created.\n";}
void Show() const {cout << "demo " << word << " lives.\n";}
~demo() {cout << "demo " << word << " destroyed.\n";}
};

class bad_hmseg
{
private:
double a;
double b;
public:
bad_hmseg(double x, double y): a(x), b(y) {}
void report() {cout<< "a = -b, please input two number again: \n";}
};

double hmean(double x, double y)
{
if(x + y == 0)
//发出异常，相当与发特定信号弹
throw bad_hmseg(x, y);
return 2*x*y/(x+y);
//cout << "2*x*y/(x+y) = " << 2*x*y/(x+y) << endl;
}

class bad_gmesg
{
private:
double a;
double b;
public:
bad_gmesg(double x, double y): a(x), b(y) {}
void report() {cout << "the number can't be less than 0. You can't compute any more.\n";}
};

double gmean(double x, double y)
{
if(x < 0 || y < 0)
throw bad_gmesg(x, y);
return sqrt(x*y);
//cout << "sqrt(x*y) = " << sqrt(x*y) << endl;
}

double means(double x, double y)
{
double mn, hn, gn;
mn = (x + y)/2.0;
hn = hmean(x, y);
gn = gmean(x, y);
return (mn + hn + gn)/3.0;
}

int main()
{
demo d1("found in block in main");
double x, y;
while(cin >> x >> y)
try
{
//可能出现异常的代码块
double z = means(x, y);
cout << "means(x, y) = " << z << "\n";
}
catch(bad_hmseg& hg) //接收特定信号
{
//处理异常的部分
hg.report();
continue;
}
catch(bad_gmesg& bg)
{
bg.report();
break;
}
d1.Show();
return 0;
}
*/

