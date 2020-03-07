/*---------------------------------------------------
 * Date    : 2020-03-05
 * Author  : LiuYan
 * Function: 第８章practice
 *
 *----------------------------------------------------*/

#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct CandyBar
{
char name[40];
double weight;
int calories;
};

struct stringy
{
char *str;
int ct;
};

struct debts
{
char name[50];
double amount;
};

void Silly(const char *str, int n =0);
void SetMember(CandyBar& c1, char *name =(char*) "Millennuium Munch", double weight = 2.85, int calories = 350);
void ShowCandyBar(const CandyBar& c1);
void Toupper(string& str);
void set(stringy& s1, char * s2);
void show(const stringy& s, int n =1);
void show(const char *str, int n=1);
template <typename T>
T max5(T a[]);
template <typename T>
T maxn(T a[], int n)
{
T max = a[0];
cout << "call the template.\n";
for(int i = 0; i < n; ++i)
{
max = (a[i] > max? a[i] : max);
}
return max;
}

template < >
const char * maxn(const char *a[], int n);
template <typename T>
T SumArray(T a[], int n);
template <typename T>
T SumArray(T* a[], int n);

int main()
{

{
int things[6] = {13, 31, 103, 301, 310, 130};
struct debts mr_E[3] =
{
{"Ima Wolfe", 2400.0},
{"Ura Foxe", 1300.0},
{"Iby Stout", 1800.0}
};
double * pd[3];
for (int i = 0; i < 3; i++)
pd[i] = &mr_E[i].amount;
cout << "Total of Mr. E's things:\n";
cout << SumArray(things, 6) << endl;
cout << "Sum of Mr. E's debts:\n";
cout << SumArray(pd, 3) << endl;
//cin.get();
}

/*
{
const char *a[5] = {"Liu Yan", "Wang", "Yuan hang", "Ling", "Jof"};
const char *str = maxn(a, 5);
cout << str << endl;
}

{
int a[5] = {1, 2, 3, 4,5};
cout << max5(a) << endl;
double b[5] = {17.8, 54.21, 79.56, 15.0, 63.99};
cout << max5(b) << endl;
int c[6] = {1, 2, 3, 4, 5, 6};
cout << maxn(c, 6) << endl;
double d[4] = {13.2, 60.67, 32.80, 0.0};
cout << maxn(d, 4) << endl;
}


{
stringy beany;
char testing[] = "Reality isn't what it used to be.";
set(beany, testing); // first argument is a reference,
// allocates space to hold copy of testing,
// sets str member of beany to point to the
// new block, copies testing to new block,
// and sets ct member of beany
show(beany); // prints member string once
show(beany, 2); // prints member string twice
testing[0] = 'D';
testing[1] = 'u';
show(testing); // prints testing string once
show(testing, 3); // prints testing string thrice
show("Done!");
//std::cin.get();
}


{
string str;
cout << "Enter a string(q to quit): ";
while(getline(cin, str) && (str != "q"))
{
//getline(cin, str);
Toupper(str);
cout << str << endl << "Next string(q to quit): ";
}
cout << "Bye.\n";
}


{
CandyBar c;
SetMember(c);
ShowCandyBar(c);
SetMember(c,(char*)"Liu Yan");
ShowCandyBar(c);
}


{
char *str = "Why me?\n";
Silly(str);
for(int i =1; i <= 3; ++i)
{
cout << i << "th use: \n";
Silly(str, i);
}
}
*/

return 0;
}

void Silly(const char *str, int n)
{
static int uses = 0;
int limits = ++uses;
if(n == 0)
limits = 1;
for(int i = 0; i < limits; ++i)
cout << str;
}

void SetMember(CandyBar& c1, char *name, double weight, int calories)
{
strcpy(c1.name, name);
c1.weight = weight;
c1.calories = calories;
}
void ShowCandyBar(const CandyBar& c1)
{
cout << "name: " << c1.name << endl <<  "weight: " << c1.weight << endl << "calories: " << c1.calories << endl;
}

void Toupper(string& str)
{
for(int i = 0; str[i] != '\0'; ++i)
{
if(islower(str[i]))
str[i] = toupper(str[i]);
}
}

void set(stringy& s1, char * s2)
{
s1.ct = strlen(s2);
s1.str = new char[s1.ct+1];
strcpy(s1.str, s2);
}

void show(const stringy& s, int n)
{
int i;
for(i = 0; i < n; ++i)
{cout << i << "th print: " << endl <<"str: " << s.str << endl << "length of str: " << s.ct << endl;}
}

void show(const char *str, int n)
{
int i;
for(i = 0; i < n; ++i)
{cout << i << "th print: " << endl <<"str: " << str << endl;}
}

template <typename T>
T max5(T a[])
{
T max = a[0];
for(int i = 0; i < 5; ++i)
{
max = (a[i] > max? a[i] : max);
}
return max;
}

/*
template <typename T>
T maxn(T a[], int n)
{
T max = a[0];
for(int i = 0; i < n; ++i)
{
max = (a[i] > max? a[i] : max);
}
return max;
}*/

template < > const char * maxn(const char *a[], int n)
{
int i;
cout << "yes\n";
const char *max = a[0];
cout << "strlen(a[0]): " << strlen(a[0]) << endl;

for(i = 0; i < n; ++i)
{
cout << "strlen(a[" <<i << "]): " << strlen(a[i]) << endl;
if(strlen(a[i]) > strlen(max))
max = a[i];
}

return max;
}

template <typename T>
T SumArray(T a[], int n)
{
cout << "template A.\n";
T total = a[0];
for(int i = 1; i< n; ++i)
{
total += a[i];
}
return total;
}

template <typename T>
T SumArray(T* a[], int n)
{
cout << "template A.\n";
T total = *a[0];
for(int i = 1; i< n; ++i)
{
total += *a[i];
}
return total;

}
