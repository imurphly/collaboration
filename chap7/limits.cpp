/*---------------------------------------------------
 * Date    : 2020-02-24
 * Author  : LiuYan
 * Function: print some integer limits and bytes.
 *
 *----------------------------------------------------*/

#include <iostream>
#include <climits>
#include <cstdio>
#include <string>

#define ZERO 0

using std::cout;
using std::cin;
using std::endl;
using std::string;

void ShowArray(const double arr[], int n);
typedef void (*pf)(const double [], int n);
int FillArray(double arr[], int limits);
void ReValue(double r, double arr[], int n);
char * BuildStr(char ch, int n);
void Recurs(int n);
void SubDivide(char ar[], int lower, int higher, int level);

int main()
{


/*
{
int lower =0;
int higher = 66;
int level = 6;
char ar[higher+2];
ar[0] = ar[higher] = '|';
ar[higher+1] = '\0';
for(int i = 1; i < higher; ++i)
{ar[i] = ' ';}
cout << ar << endl;
for(int i = 1; i <= level; ++i)
{
SubDivide(ar, lower, higher, i);
cout << ar << endl;
for(int j = 1; j < higher; ++j)
{ar[j] = ' ';}
}
}


//递归工作原理
{
int n;
cout << "Enter the iter: ";
cin >>n;
Recurs(n);
}


//getline(cin, str)
{
string str1, str2;
cout << "Enter 2 string:\n";
cin >> str1;
cin >>str2;
}


//数组不能直接打印，用字符指针表示的字符串却可以直接打印。
{
char ch;
int n;
cout << "Creat a char array by a char and a n, Enter them: \n";
cin.get(ch).get();
cin >> n;
char * str = BuildStr(ch, n);
cout << str << endl;
delete []str;
}


 {
int age =10;
int age_1 = 11;
const int year =2020;
const int *pt = &age;   //a pointer to const int
int * const pw = &age;  //a const point to int
const int * const ps = &age;
int *arr[2] {&age, &age_1};
cout << "declare a const point \"int * const pw\" at" << pw <<" , *pw = " << *pw<<endl;
*pw = 100;
cout << "change the value, *pw = " << age << endl;
cout << "declare a pointer \"const int* pt\" at " << pt << endl;
pt = &year;
cout << "now, pt point to year, at " << pt << endl;
cout << "So, pt can change direction, const just mean can't modify (*pt).\n ";
}


{
pf p1 = ShowArray;
double factor;
const int max = 5;
double arr[max];
int size = FillArray(arr, max);
p1(arr, size);
//ShowArray(arr, size);
cout << "Enter revaluation factor: ";
while(!(cin >> factor))
{
cin.clear();
while(cin.get() != '\n')
continue;
cout << "Please input a  double factor: ";
}
ReValue(factor, arr, size);
ShowArray(arr, size);
cout << "Done!\n";
}


//当输入数字时，检测输入错误
{
double temp;
cout << "Enter the double variable: ";
while(!(cin >> temp))
{
cin.clear();
while(cin.get() != '\n')
continue;
cout << "Please input a  double: ";
}
}


//第七章清单
//当函数形参为数组时，可以使用const int arr[]表明在该函数中不可以改变该数组的内容，但这不意味着该数组是const量.
{
double a[5] {1.0, 3.0, 4.0, 5.4, 6.7};
ShowArray(a, 5);
}


//各种数据类型的范围
int n_int;
short n_short;
long n_long;
long long n_llong;
unsigned int u_n_int;
char n_char;
cout << "int is " << sizeof(n_int) << " bytes" << endl;
cout << "short is "<< sizeof(n_short) << " bytes" << endl;
cout << "long is " << sizeof(n_long) << " bytes" << endl;
cout << "long long is "<< sizeof(n_llong) << " bytes" << endl;
cout << "unsigned int is "<< sizeof(u_n_int) << " bytes" << endl << endl;

cout << "Limited value of types: " << endl;
cout << "int: ";
printf("(%d, %d)\n", INT_MIN, INT_MAX);
cout << "short: ";
printf("(%d, %d)\n", SHRT_MIN, SHRT_MAX);
cout << "long: ";
printf("(%ld, %ld)\n", LONG_MIN, LONG_MAX);
cout << "long long: ";
printf("(%lld, %lld)\n", LLONG_MIN, LLONG_MAX);
cout << "unsigned int: (" << ZERO << ", " << UINT_MAX << ")" << endl<< endl;

cout << "char is "<< sizeof(n_char) << " bytes, " << CHAR_BIT << " bits" << endl;
cout << "char: ("<< CHAR_MIN << ", " << CHAR_MAX  << ")"<< endl;
*/

return 0;
}

//当函数形参为数组时，可以使用const int arr[]表明在该函数中不可以改变该数组的内容，但这不意味着该数组是const量.
void ShowArray(const double arr[], int n)
{
int i;
for(i = 0; i < n; ++i)
 {
cout << "Property #" << (i+1) << ": $";
cout << arr[i] << ", " << endl;
 }
}

int FillArray(double arr[], int limits)
{
int count=0, i=0;
while((i < limits))
 {
cout << "Property #" << i+1 << ": ";
while(!(cin >> arr[i]))
 {
cin.clear();
while(cin.get() != '\n')
continue;
cout << "Please Enter a double number: ";
 }
if(arr[i] > 0)
{++count;
 ++i;}
else if(arr[i] <= 0)
break;
 }
return count; 
}

void ReValue(double r, double arr[], int n)
{
for(int i = 0; i < n; ++i)
    arr[i] *= r;
}

char * BuildStr(char ch, int n)
{
char *str = new char[n+1];
int i;
for(i = 0; i < n; ++i)
{
str[i] = ch;
}
str[n] = '\0';
return str;
}

void Recurs(int n)
{
cout << "Counting downing-------------" << n << endl;
if(n >0)
Recurs(n-1);
cout << n << "Kaboom!\n";
}

void SubDivide(char ar[], int lower, int higher, int level)
{
if(level == 0)
return;
int mid = (higher + lower)/2;
ar[mid] = '|';
SubDivide(ar, lower, mid, level-1);
SubDivide(ar, mid, higher, level-1);
}
