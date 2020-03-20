//#include "Point.h"

//哑型指针
typedef void* ADT;
typedef const void* CADT;

//声明节点
struct NODE; 
typedef struct NODE* PNODE;

//声明链表
struct LIST;
typedef struct LIST* PLIST;

//一个函数参数
//typedef void(*MANIPULATE_OBJECT)(void* e);

//两个函数参数
typedef void(*MANIPULATE_OBJECT)(void* e, const void* tag);
typedef bool(*COMPARE_OBJECT)(CADT e1, CADT e2);
typedef void(*DESTROY_OBJECT)(ADT e);
/*
 *创建，销毁，清空，追加，插入，删除，遍历，搜索，判断非空
 */

PLIST LsCreat();//3
//void LsDestroy(PLIST list);
//void LsClear(PLIST list);
void LsDestroy(PLIST list, DESTROY_OBJECT destroy);
void LsClear(PLIST list, DESTROY_OBJECT destroy);

//void LsAppend(PLIST list, PPOINT point);
void LsAppend(PLIST list, ADT obj); //6

//void LsInsert(PLIST list, PPOINT point, unsigned int pos);
void LsInsert(PLIST list, ADT obj, unsigned int pos);

//void LsDelete(PLIST list, unsigned int pos);
void LsDelete(PLIST list, unsigned int pos, DESTROY_OBJECT destroy); //7
//void LsTraverse(PLIST list);
//void LsTraverse(PLIST list, MANIPULATE_OBJECT manipulate);

//两个函数参数S
void LsTraverse(PLIST list, MANIPULATE_OBJECT manipulate, const void* tag);


//bool LsSearch(PLIST list, PPOINT point);
bool LsSearch(PLIST List, CADT object, COMPARE_OBJECT compare);

unsigned int LsGetCount(PLIST list);//8
bool LsIsEmpty(PLIST list);  //4
bool LsIsFull(PLIST list); //5
