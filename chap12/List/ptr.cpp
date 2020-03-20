//指针作为函数参数，指针指向数组，通过访问指针随机生成一个数组
#include <cstdlib>
#include <iostream>
#include "ptr.h"
#include <cstring>
#include "Random.h"

using namespace std;
int lower;
int upper;

void GenerateIntegers(int* p, unsigned int n)
{
unsigned int i;
Randomize();
for(i = 0; i < n; i++)
*p++ = GenerateRealNumber(lower, upper);
}

//定义函数DuplicateString, 复制字符串
char* DuplicateString(char* s)
{
char* t;
unsigned int n,i;
if(!s)
{cout << "DuplicateString: Parameter Illegal.";
exit(1);
}
n = strlen(s);
//strlen()函数只有c标准库里有， c++没有。
t = (char*)malloc(n+1);
//这里分配的内存啥时候会被释放呢？？？该指针将所有权通过返回值转移给了主调函数
//在main函数结束时，操作系统会自动销毁它。
for(i = 0; i < n; i++)
{
t[i] = s[i];
}
t[n] = '\0';
return t;
}
