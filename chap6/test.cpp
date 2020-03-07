/*---------------------------------------------------
 * Date    : 2020-02-24
 * Author  : LiuYan
 * Function: 前六章程序清单。
 *
 ----------------------------------------------------*/

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;

union one4all
{
int int_val;
long long_val;
double double_val;
};

struct inflable
{
char name[20];
float volum;
double price;
};

int main()
{


/*
 *第六章清单
 */

/*
//6.16 读取文本文件
{
const int size = 60;
char filename[size];
cout << "Enter name of data file: ";
cin.getline(filename, size);
ifstream infile;
infile.open(filename);
if(!infile.is_open())
{
cout << "meet error when opening file.\n";
exit(EXIT_FAILURE);
}
double value;
double sum;
int count = 0;
infile >> value;
while(infile.good())
{
++count;
sum +=value;
infile >> value;
}
if(infile.eof())
cout << "End of the file.\n";
else if(infile.fail())
cout << "input terminated by data mismatch.\n";
else 
cout << "Input termiated by unknow reason.\n ";

if(count == 0)
cout << "No data got.\n";
else
{
cout << "Item read: " << count << endl;
cout << "sum = " << sum << endl;
cout << "average = " << sum/count << endl;
}
infile.close();
}
*/

//6.14 要求用户输入５个高尔球得分，计算平均成绩。如果输入非数字输入，程序讲拒绝，并要求用户继续输入数组
{
const int size = 5;
int golf[size];
cout << "Please enter your golf scores.\n You must enter " << size << " rounds.\n";
int i;
for(i = 0; i < size; ++i)
 {
 cout << "round #" << i+1 << ": ";
 while(!(cin >> golf[i]))
 {
cin.clear();
while(cin.get() != '\n')
continue;
cout << "Please input a number: ";}
 }
double total = 0.0;
for(int j = 0; j < size; ++j)
 total += golf[j];
cout << total/size << " = average score of " << size << " rounds\n";
}


/*
//6.13 计算每天捕鱼的重量，每天最多５条鱼，因此一个包括５个元素的数组将足以存储所有数据，但是也可能没有捕到这么多的鱼。如果数组被填满或者非数字输入，则循环将结束
{
const int size = 5;
double weight[size];
cout << "Please enter the weights of your fish.\n You may enter up to 5 fish <q to terminate>.\n";
cout << "fish #1: ";
int i = 0;
while(i < size && cin>> weight[i])
 {
 if(++i < size)
  {cout << "fish #" << i+1 << ": ";}
 }
double total = 0.0;
for(int j = 0; j < i; ++j)
total += weight[j];
if(i == 0)
cout << "No fish!\n";
else
cout << total/i << " = average weight of " << i << " fishs\n";
}


//6.12 break 和continue, 输入文本
{
const int size = 60;
char line[size];
cin.getline(line, size);
int i, space = 0;
for(i = 0;  i < size; ++i)
{
cout << line[i];
if(line[i] == '.')
break;
if(line[i] != ' ')
continue;
++space;
}
cout << space << " space total.\n";
}


	//6.5 测试&&, 一个while循环将值读取到数组
	{
		const int size = 6;
		cout << "Enter the NAAQs your neighbors. Program terminates when you make \n or enter a negative value.\n";
		float temp;
		float arr[size];
		cout << "First value: ";
		cin >> temp;
		int i;
		while((i < size) && (temp >= 0))
		{
			arr[i] = temp;
			++i;
			if(i < size)
			{
				cout << "Next value: ";
				cin >> temp;
			}
                 }
			if(i == 0)
				cout << "No data, bye.\n";
			else
			{
				cout << "Enter your NAAQ: ";
				float you;
				cin >> you;
				int j, count = 0;
				for(j =0; j < i; ++j)
				if(arr[j] > you)
					++count;
				cout << count << " numbers are large than NAAQ.\n";
			}
		}
	



//6.1 使用句点.来确定句子的结尾 if
{
char ch;
int total=0, space=0;
cin.get(ch);
while(ch != '.')
{
if(ch == ' ')
++space;
++total;
cin.get(ch);
}
cout << space << " space, " << total << " characters total in sentence.\n";
}


//6.2 对字母加密来修改输入的文本（换行符不变）if else
{
char ch;
cin.get(ch);
while(ch != '.')
 {
 if(ch == '\n')
 cout << ch;
 else
 cout << ++ch;
cin.get(ch);
 }
cout << "Please excuse the slight confusion.\n";
}


//6.3 测试if else if
{
const int answer = 27;
cout << "Enter a number in the range 1-100 to find my favorate number: ";
int num;
cin >> num;
do
{
if(num > answer){
cout << "Too high -- guess again: ";
}
else if(num < answer){
cout << "Too high -- guess again: ";
}
cin >> num;
}
while(num != answer);
cout << num << " is right.\n"; 
}


//6.4 
{
cout << "This program may reformat your hard disk\n and destroy all your data.\n Do you wish to continue? <y/n>\n";
char ch;
cin.get(ch);
if(ch == 'y' || ch == 'Y')
cout << "You were warned!\n";
else if(ch == 'n' || ch == 'N')
cout << "A wise choice .. bye\n";
else 
cout << "stupid.\n";
}
*/


/*
{
//for循环
int i;
cout << "i++, \n";
for(i = 0; i < 5; i++)
cout << "print " << i << "th times\n";
cout << "when i = " << i << ", end\n";
}

{
int i;
cout << "++i, \n";
for(i = 0; i < 5; ++i)
cout << "print " << i << "th times\n";
cout << "when i = " << i << ", end\n";
}

//对于for循环来说，前缀递增和后缀递增的最终效果是一样的，但是后缀版本会产生一个i的副本，因此对于类而言前缀比后缀版本的效率要高，所以建议使用前缀版本。

//探索++运算符在完整表达式中的情况
{
int guest = 9;
while(guest++ < 10)
cout << guest << endl;
}


//i++ i--的优先级最高，他们从左到右结合。++i, --i,和*的优先级相等，他们均是从右到左结合
{
double arr[6] {15.9, 66.85, 52.53, 13.1, 81.35, 80.79};
double *pt = arr;
cout << "*pt = " << pt[0] << ", pt at " << pt << endl;
cout << "*++pt = " << *++pt  << ", pt at " << pt << endl;
cout << "++*pt = " << ++*pt  << ", pt at " << pt << endl;
cout << "*pt++ = " << *pt++ << ", pt at " << pt << endl; 
cout << "*pt = " << *pt  << ", pt at " << pt << endl;
}


//基于范围的for循环
{
double arr[6] {15.9, 66.85, 52.53, 13.1, 81.35, 80.79};
for(double &x : arr)
cout << ++x << endl;
}


{
	char ch;
	int count;
	cout << "Please a character, enter # to quit: \n";
	cin >> ch;
	//while(ch != '#')
 // while(cin.fail() == false)
while(cin)
	{
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << "\nend!\n";
}
*/


//复习第四章的程序清单
//指针
/*
{
//结构体，指针，数组的组合

//结构体指针
inflable s01, s02, s03;
s01.price = 60.67;
cout << "s01.price = " << s01.price << endl;
inflable *ps = &s02;
ps->price = 32.80;

//结构体数组
inflable s[3];
s[0].price = 13.2;
(s+ 1)->price = 60.67;

//指针数组
const inflable * pa[3] {&s01, &s02, &s03};
cout << "s01.price = " << pa[0]->price << endl;

const inflable **ppa = pa;
cout << "s01.price = " << (*ppa)->price << endl;
cout << "s02.price = " << ((*ppa)+1)->price << endl;
cout << "s02.price = " << (*(ppa+1))->price << endl;
}
*/

/*
//结构体指针怎样访问成员
{
inflable *ps = new inflable;
cout << "Enter the price: ";
cin >> (*ps).price;
cin.get();
cout << "Enter the name of inflable item: ";
cin.getline(ps->name, 20);
cout << "Enter the volume of feet: ";
cin >> ps->volum;
delete ps;
}
*/

/*
//strcpy()
//当数组存储的是字符串时，数组的名字就是字符串的名字
//但是当存储int或double,数组的名字竟然可以当做地址来用
{
char animal[20] = "bird";
const char *bend = "wren";
char * pw = animal;
cout << animal << " and " << bend << endl;
//pw = animal;
cout << "before strcpy: \n";
cout << "animal at " << (int*)animal << endl;
cout << "pw at " << (int *)pw << endl;

char *ps = new char[strlen(animal) + 1];
strcpy(ps, animal);
cout << "after strcpy: \n";
cout << "animal at " << (int*)animal << endl;
cout << "ps at " << (int *)ps << endl;
}
*/

/*
{
//指针和数组名在有些时候是可以互换的
double stack[3] {1000.2, 200.5, 100.0};
double *pw = stack;
cout << "pw = " << pw << ", *pw= " << *pw << endl;
cout << "pw[0] = " << pw[0] << ", pw[1] = " << pw[1] << endl;
pw = pw + 1;
cout << "add one to the pointer pw.\n";
cout << "pw = " << pw << ", *pw= " << *pw << endl;
cout << "access element by array name: stack = " <<  stack << ", *stack = " << *stack << endl;
cout << "access element by array name: stack + 1 = " <<  stack+1 << ", *(stack+1) = " << *(stack+1) << endl;
}
*/



/*
//指针的加减
{
//double *p = new double(3);
//这条语句把p指向了一个double变量，并初始化值为3;
//cout << "p[0] = " << p[0] << ", address = " << p;

double *p = new double[3];
p[0] = 6.0;
p[1] = 7.0;
p[2] = 3.28;
cout << "p[0] = " << p[0] << ", address = " << p << endl;
p = p + 1;
cout << "p[0] = " << p[0] << ", address = " << p << endl;
p = p - 1;
cout << "p[0] = " << p[0] << ", address = " << p << endl;
delete [] p;
}
*/

/*
//取地址符
{
double cups = 3.5;
int donuts = 6;
//double cups = 3.5;
cout << "cups value: " << cups << ", address value: " << &cups << endl;
cout << "donuts value: " << donuts << ", address value: " << &donuts << endl;
}

//让指针指向一个地址，并改变地址存储的值
{
int update = 6;
int * p_update = &update;
cout << "update = " << update << ", *p_update = " << *p_update << endl;
cout << "Address: &update = " << &update << ", p_update = " << p_update << endl;
*p_update = 16;
cout << "now, update = " << update << endl; 
}

//new int 和 new double
{
int night = 1001;
int * p_int = new int;
*p_int = 1001;

double day = 60.67;
double *p_double =new double;
*p_double = day;

cout << "night = " << night << ", address = " << &night << endl;
cout << "p_int = " << *p_int << ", address = " << p_int << endl;
delete p_int;
delete p_double;
}
*/


//复习第四章的程序清单
/*
//数组的声明，赋值和初始化，数组元素的访问和四则运算
{
int yams[3];
yams[0] = 1;
yams[1] = 2;
yams[2] = 3;

int yamcost[3] {20, 5, 3};

cout << "total yams = " << yams[0]+yams[1]+yams[2] << endl;
cout << "the package with " << yams[0] << " cost " << yamcost[0] << " cents each yam.\n";
int total = yams[0]*yamcost[0] + yams[1]*yamcost[1] + yams[2]*yamcost[2];
cout << "total cost = " << total << endl;
cout << "The yams has " <<  sizeof(yams) << " bytes.\n";
cout << "The element of yams has " << sizeof(yams[0]) << " bytes.\n";
}

{
//字符串存储在数组中的两种方式：１．初始化，　２．通过键盘或者文件输入
//看看存储字符串的数组，打印时遇到空字符会不会结束打印，以及strlen, sizeof
const int size = 15;
char name[size] = {"C++obbey"};
char name1[size];
cout << "What is your name: ";
cin.getline(name1, size);
cout << "Oh, my name is C++obbey, nice to meet you, " << name1 << endl;
cout << "The array is of " << sizeof(name) << " bytes\n";
cout << name << "is long of " << strlen(name)  << " bytes.\n";
name[3] = '\0';
cout << name << " is long of " << strlen(name)  << " bytes.\n";
}
*/

/*
{
//改进字符串数组的输入
//问题１：　cin输入时，遇见空格就会结束。
//问题２：改用cin.getline(),不能和数字混合输入，解决方法是get();
const int arsize = 20;
char name[arsize], dessert[arsize];
int year;
cout << "This year is: ";
cin >> year;
cin.get();
cout << "Please tell me your name: ";
//cin >> name;
cin.getline(name, arsize);
cout << "And your favorate dessert is: ";
//cin >> dessert;
cin.getline(dessert, arsize);
cout << "I have some delicious " << dessert << " for you, " << name << endl;
}
*/

/*
{
//用C++类string表示字符串
string str1;
cout << "PLease input your name: ";
getline(cin, str1);
}
*/

/*
{
//共用体union, 特性：每次只存储一个类型的成员
one4all pail;
pail.int_val = 15;
cout << "pail.int_val = " << pail.int_val << endl;
pail.double_val = 13.8;
cout << "pail.double_val = " << pail.double_val << " pail.int_val = " << pail.int_val<< endl;
}
*/

/*
{
//枚举类型
//enum spectrum {red, orange, yellow, green, blue, black, white, purple};
enum {red, orange, yellow, green, blue, black, white, purple};
//spectrum band = red;
//int color = band;
int color = red;
cout << color << endl;
color = yellow + orange;
cout << color << endl;
}
*/

return 0;
}
