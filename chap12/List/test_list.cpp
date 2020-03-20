//往链表中装Circle(圆)数据
//g++ test_list.cpp List.cpp Circle.cpp ptrStruct.cpp
#include <iostream>
#include "Circle.h"
#include "List.h"

using namespace std;

void DoManipulateObject(void* e, const void* tag)
{
cout << CeTransformToString((PCIRCLE)e, (const char*)tag) << endl;
}
MANIPULATE_OBJECT manipulate = DoManipulateObject;


void DoDestroy(ADT e)
{
CeDestroy((PCIRCLE)e);
}
DESTROY_OBJECT destroy = DoDestroy;

int x =10, y =100, r =1;
int x1=10, y1= 100, r1 =2;
int x2 =1, y2 = 1, r2 =1;
int x3 =1, y3 =1, r3 =10;
int main()
{
PCIRCLE t = CeCreat(x, y, r);
PCIRCLE t1 = CeCreat(x1, y1, r1);
PCIRCLE t2 = CeCreat(x2, y2, r2);
PCIRCLE t3 = CeCreat(x3, y3, r3);
CePrint(t);
CePrint(t1);
CePrint(t2);
CePrint(t3);

 PLIST list =  LsCreat();
#ifndef NDEBUG
cout << "Creat ok!"  << endl;
#endif


       LsAppend(list, (ADT)t);
#ifndef NDEBUG
cout << "Append ok!"  << endl;
#endif
cout << "five Traverse." << endl;
cout << "Traverse 1: "  << endl;



 //      LsTraverse(list);
//LsTraverse(list, manipulate);
LsTraverse(list, DoManipulateObject,"center=(%d, %d), radius=%d");

       LsAppend(list, (ADT)t2);

cout << "Traverse 2:"<< endl;
//LsTraverse(list);
//LsTraverse(list, manipulate);
LsTraverse(list, DoManipulateObject,"center=(%d, %d), radius=%d");

      LsInsert(list, (ADT)t1, 1);

cout << "Traverse 3:"<< endl;
//LsTraverse(list);
//LsTraverse(list, manipulate);
LsTraverse(list, DoManipulateObject,"center=(%d, %d), radius=%d");

       LsInsert(list, (ADT)t3,3);

cout << "Traverse 4:"<< endl;
//LsTraverse(list);
//LsTraverse(list, manipulate);
LsTraverse(list, DoManipulateObject,"center=(%d, %d), radius=%d");


LsDelete(list, 2, DoDestroy);
cout << "Traverse 5:"<< endl;
//LsTraverse(list);
//LsTraverse(list, manipulate);
LsTraverse(list, DoManipulateObject,"center=(%d, %d), radius=%d");


//bool search_result = LsSearch(list, t1);
//bool search_result = LsSearch(list, (ADT)t1, DoCompare);
//cout << "Search  t1: " << boolalpha << search_result<< endl;
cout << "The list have " << LsGetCount(list) << " elements" << endl;
cout << "It's" << (LsIsEmpty(list)? " ": " not") << " empty" << endl;
       //LsDestroy(list);

LsDestroy(list, DoDestroy);
#ifndef NDEBUG
cout << "Destroy ok!" << endl;
#endif
	return 0;
}

/*
// 链表相当于是一个容器，往链表中装Point（点）数据。
//g++ test_list.cpp List.cpp Point.cpp ptrStruct.cpp
#include "Point.h"

#include "List.h"
#include <cstdlib>
#include <iostream>
using namespace std;

//typedef void (*MANIPULATE_OBJECT)(void* e);
void DoManipulateObject(void* e, const void* tag)
{
cout << PtTransformToString((PPOINT)e, (const char*)tag) << endl;
}
MANIPULATE_OBJECT manipulate = DoManipulateObject;



bool DoCompare(CADT e1, CADT e2)
{
 return PtCompare((PPOINT)e1, (PPOINT)e2);
}
COMPARE_OBJECT compare = DoCompare;

void DoDestroy(ADT e)
{
PtDestroy((PPOINT)e);
}
DESTROY_OBJECT destroy = DoDestroy;
//LsTraverse(list, manipulate);



//#define NDEBUG

//测试
//g++ List.cpp Point.cpp ptrStruct.cpp

#ifndef DEBUG

#include <iostream>
using namespace std;
int main()
{

	int m =3, n = 4;
	int x = 10, y = 20;
	cout << "x: " << x << ", y: " << y << endl;
	int a = 1, b = 2;
	cout << "a: " << a << ", b: " << b << endl;
	PPOINT t =PtCreat(x,y);
        PPOINT t1=PtCreat(++x, --y);
	PPOINT t2 = PtCreat(a,b);
        PPOINT t3 = PtCreat(m,n);
       

//	cout << "t: " << PtTransformToString(t) << endl;
  //      cout << "t1: " << PtTransformToString(t1) << endl;
	//cout << "t2: "<< PtTransformToString(t2) << endl;
        //cout << "t3: "<< PtTransformToString(t3) << endl;

        PLIST list =  LsCreat();
#ifndef NDEBUG
cout << "Creat ok!"  << endl;
#endif


       LsAppend(list, (ADT)t);
#ifndef NDEBUG
cout << "Append ok!"  << endl;
#endif
cout << "five Traverse." << endl;
cout << "Traverse 1: "  << endl;



 //      LsTraverse(list);
//LsTraverse(list, manipulate);
LsTraverse(list, DoManipulateObject,"(%d,%d)");

       LsAppend(list, (ADT)t2);

cout << "Traverse 2:"<< endl;
//LsTraverse(list);
//LsTraverse(list, manipulate);
LsTraverse(list, DoManipulateObject,"(%d,%d)");

      LsInsert(list, (ADT)t1, 1);

cout << "Traverse 3:"<< endl;
//LsTraverse(list);
//LsTraverse(list, manipulate);
LsTraverse(list, DoManipulateObject,"(%d,%d)");

       LsInsert(list, (ADT)t3,3);

cout << "Traverse 4:"<< endl;
//LsTraverse(list);
//LsTraverse(list, manipulate);
LsTraverse(list, DoManipulateObject,"(%d,%d)");


LsDelete(list, 2, DoDestroy);
cout << "Traverse 5:"<< endl;
//LsTraverse(list);
//LsTraverse(list, manipulate);
LsTraverse(list, DoManipulateObject,"(%d,%d)");


//bool search_result = LsSearch(list, t1);
bool search_result = LsSearch(list, (ADT)t1, DoCompare);
cout << "Search  t1: " << boolalpha << search_result<< endl;
cout << "The list have " << LsGetCount(list) << " elements" << endl;
cout << "It's" << (LsIsEmpty(list)? " ": " not") << " empty" << endl;
       //LsDestroy(list);

LsDestroy(list, DoDestroy);
#ifndef NDEBUG
cout << "Destroy ok!" << endl;
#endif
	return 0;
}
#endif
*/
