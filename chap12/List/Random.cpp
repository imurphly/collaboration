/*
*基于随机数的范围为[0,RAND_MAX];
*生成指定范围的整数
*生成指定范围的实数
*
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
void Randomize()
{
srand((int)time(0));
}

int GenerateInt(int lowest, int highest)
{
double _d;
if(lowest > highest)
{
cout << "GenerateInt: Make sure lowest < highest.\n";
exit(1);
}
_d = (double)rand()/((double)RAND_MAX + 1);
return (lowest + (int)(_d*(highest - lowest + 1)));
}

double GenerateRealNumber(double lowest, double highest)
{
double _d;
if(lowest > highest)
{
cout << "GenerateRealNumber: Make sure lowest < highest.\n";
exit(2);
}
_d = (double)rand()/(double)RAND_MAX;
return (lowest + _d*(highest - lowest));
}
