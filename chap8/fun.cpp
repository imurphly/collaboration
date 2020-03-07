/*---------------------------------------------------
 * Date    : 2020-03-04
 * Author  : LiuYan
 * Function: 第８章程序清单
 *
 *----------------------------------------------------*/

#include <iostream>
#include <climits>
#include <cstdio>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct job
{
char name[40];
double salary;
int floor;
};

void ShowArray(const double arr[], int n);
//声明函数时可以省略形参名，但不能省略类型名

//通用模板
template <typename T>
void Swap(T& , T& );
//通用模板
template <typename T>
void Swap(T a[], T b[], int n);
//显式具体化
template <>
void Swap<job>(job& a, job& b);
//优先级：非模板函数 >　显示具体化 >　通用模板

int main()
{

{
double a = 0.9, b = 0.08;
cout << a  << ", " << b <<endl;
Swap(a, b);
cout << a  << ", " << b <<endl;
int x = 2, y =7;
cout << x << ", " << y << endl;
Swap(x, y);
cout << x << ", " << y << endl;
double m[3]{15.0, 63.99, 85.32};
double n[3]{17.8, 54.21, 79.56};
ShowArray(m, 3);
ShowArray(n, 3);
Swap(m, n, 3);
ShowArray(m, 3);
ShowArray(n, 3);
job t1 {"Liu yan", 15.0,1};
job t2 {"Yuan hang", 17.8, 2};
Swap(t1, t2);
cout << t1.name << " " << t1.salary << " " << t1.floor << endl;
cout << t2.name << " " << t2.salary << " " << t2.floor << endl;
}

return 0;
}

void ShowArray(const double arr[], int n)
{
int i;
for(i = 0; i < n; ++i)
 {
cout << arr[i] << ", ";
 }
cout << endl;
}


template <typename T>
void Swap(T& a, T& b)
{
T temp;
temp = a;
a = b;
b = temp;
}


template <typename T>
void Swap(T a[], T b[], int n)
{
T temp;
for(int i = 0; i < n; ++i)
{
temp = a[i];
a[i] = b[i];
b[i] = temp;
}
}

template <>
void Swap<job>(job& a, job& b)
{
double d_temp;
int i_temp;
d_temp = a.salary;
a.salary = b.salary;
b.salary = d_temp;
i_temp = a.floor;
a.floor = b.floor;
b.floor = i_temp;
}
