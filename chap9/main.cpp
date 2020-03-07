#include <iostream>
#include "golf.h"
#include <string>
#include <cstring>
#include "sales.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void strcount(const string& str);


const int BUF = 52;
const int N =  2;

int main()
{

{
const int n = 4;
double a[n] {13.2, 60.67, 32.80, 0.0};
using namespace SALES;
Sales s1, s2;
setSales(s1);
setSales(s2, a, n);
showSales(s1);
showSales(s2);
}

/*
{
chaff buffer[BUF];
cout << "buffer address at " << &buffer << endl;
chaff *pd1 = new chaff[N];
chaff *pd2 = new (buffer) chaff[N];
char * temp;
int slag;
for(int i = 0; i < N; ++i)
{
cout << "Enter the dross: ";
cin.getline(temp, 20);
strcpy(pd1[i].dross, temp);
strcpy(pd2[i].dross, temp);
cout << "Enter the slag: ";
cin >> slag;
cin.get();
pd1[i].slag = pd2[i].slag = slag;
}
for(int i = 0; i < N; ++i)
{
cout << pd1[i].dross << " at " << &pd1[i] << ", " << pd2[i].dross << " at " << &pd2[i] << endl;
}

}


{
string str;
cout << "Enter a line\n";
getline(cin, str);
while((cin) && (str != "\0"))
{
strcount(str);
cout << "Enter next line: \n";
getline(cin, str);
}
cout << "Bye.\n";
}


{
int hc = 5;
golf ann;
setgolf(ann, "Ann Birdfree", 24);
showgolf(ann);
golf andy[3];
for(int i = 0; i< 3; ++i)
 {
int flag = setgolf(andy[i]);
cout << "flag: " << flag << endl;
showgolf(andy[i]);
if(flag==0)
break;
 }
//showgolf(andy);
//handicap(andy, hc);
//showgolf(andy);
}
*/

return 0;
}

void strcount(const string& str)
{
static int total = 0;
int count = str.size();
total +=count;
cout << count << " characters\n";
cout << total << " characters total\n";
}
