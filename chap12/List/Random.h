#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;


//随机数发生器，设置随机数种子。
void Randomize();
//生成指定范围内的整数
int GenerateInt(int lowest, int highest);
//生成指定范围内的实数
double GenerateRealNumber(double lowest, double highest);



void Welcome();

void RandomFiftyTwo();

//随机生成n个位于[lower, upper]区间的整数并保存到数组中。
void GenerateArray(int a[], unsigned int n, int lower, int upper);

//给一个一维度的数组元素按照从小到大排列，1.选择排序,2.冒泡排序
void SortSelect(int a[], unsigned int n);
void SortBubble(int a[], unsigned int n);

//打印一个数组
void PrintArray(int a[], unsigned int n);

//把一个引用常量b加到a上
int & Inc(int & a, const int & b);

//定义结构体为有理数库，包括分子和分母，实现加减乘除和化简
struct Rational
{
int num;
int den;
};

Rational ope_plus(Rational r1, Rational r2);
Rational ope_minus(Rational r1, Rational r2);
Rational ope_multiple(Rational r1, Rational r2);
Rational ope_division(Rational r1, Rational r2);

void ope(Rational & r);

//定义gcd,求两个数的最大公约数 gratest common divisor，辗转相除法
int gcd(int x, int y);

//定义lcm,求两个数的最小公倍数 leatest common multiple, 两个整数的乘积除以最小公倍数
int lcm(int x, int y);

/*
//声明在DynamicArray.h
//定义动态数组库和接口函数
struct DynamicArray;
unsigned int GetCount(DynamicArray * a);
*/

/*
//声明在Point.h
//定义一个点库和在点上的操作集：数据的创造，销毁，存，取，比较，转化成字符串，打印
struct Point;
typedef struct Point* PPoint;

PPoint PtCreat(int x, int y);
void PtDestroy(PPoint p);
void PtGetValue(PPoint p, int * x, int * y);
void PtSetValue(PPoint p, int x, int y);
bool PtCompare(PPoint p1, PPoint p2);
char * PtTransformToString(PPoint point);
void PtPrint(PPoint p);

struct POINT;
POINT GeneratePoint();

*/

//排序算法
void PrintArray(int a[], unsigned int n);
void GenerateArray(int a[], unsigned int n, int lower, int upper);
void SortSelect(int a[], unsigned int n);
void SortBubble(int a[], unsigned int n);
//


