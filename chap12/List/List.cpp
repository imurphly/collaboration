#include "List.h"
#include <cstdlib>
#include <iostream>
using namespace std;

	struct NODE{
	 //PPOINT data;
         ADT data;
	 PNODE  next;
	};

	struct LIST{
	unsigned int count;
        const int qsize = 40;
	PNODE head;
	PNODE tail;
	};

	/*
	 *创建，销毁，清空，追加，插入，删除，遍历，搜索，判断非空
	 */

	PLIST LsCreat()
	{
	PLIST list = new LIST;
	list->count = 0;
	list->head = NULL;
	list->tail = NULL;
	}

void LsDestroy(PLIST list, DESTROY_OBJECT destroy)
{
		LsClear(list, destroy);
		delete list;
	}

void LsClear(PLIST list, DESTROY_OBJECT destroy)
{
if(!list)
		{
			cout << "LsClear: Parameter Illegal!";
			exit(1);
		}
		while(list->head)
		{
			PNODE t = list->head;
			list->head = t->next;
                        (*destroy)((ADT)(t->data));
			//PtDestroy(t->data);
                        delete t;
			list->count--;
		}
		list->tail = NULL;
}
/*
	void LsDestroy(PLIST list)
	{
		LsClear(list);
		delete list;
	}

	void LsClear(PLIST list)
	{
		if(!list)
		{
			cout << "LsClear: Parameter Illegal!";
			exit(1);
		}
		while(list->head)
		{
			PNODE t = list->head;
			list->head = t->next;
			PtDestroy(t->data);
                        delete t;
			list->count--;
		}
		list->tail = NULL;
	}
*/

void LsAppend(PLIST list, ADT obj)
{
		if(!list || !obj)
		{
			cout << "LsAppend: Parameter illegal!";
			exit(1);
		}
                PNODE t = new NODE;
		t->data = obj;
		t->next = NULL;
		if(!list->head)
	{
		list->head = t;
		list->tail = t;
	}
	else
	{
		list->tail->next = t;
		list->tail = t;
	}
	list->count++;
}

/*
	void LsAppend(PLIST list, PPOINT point)
{
		if(!list || !point)
		{
			cout << "LsAppend: Parameter illegal!";
			exit(1);
		}
                PNODE t = new NODE;
		t->data = point;
		t->next = NULL;
		if(!list->head)
	{
		list->head = t;
		list->tail = t;
	}
	else
	{
		list->tail->next = t;
		list->tail = t;
	}
	list->count++;
}
*/

void LsInsert(PLIST list, ADT obj, unsigned int pos)
{
	if(!list || !obj)
	{
		cout << "LsInsert: Parameter illegal!";
		exit(1);
	}
	if(pos < list->count)
	{
		PNODE t = new NODE;
		t->data = obj;
		t->next = NULL;
		if(pos == 0)
		{
			t->next = list->head;
			list->head = t;
		}
		else
		{ 
PNODE u = list->head;
			unsigned int i;
			for(i = 0; i < pos - 1; i++)
			{
				u = u->next;
			}
			t->next = u->next;
			u->next = t;
		}
list->count++;
	}
	else

		//LsAppend(list, point);
                  LsAppend(list, obj);
}

/*
void LsInsert(PLIST list, PPOINT point, unsigned int pos)
{
	if(!list || !point)
	{
		cout << "LsInsert: Parameter illegal!";
		exit(1);
	}
	if(pos < list->count)
	{
		PNODE t = new NODE;
		t->data = point;
		t->next = NULL;
		if(pos == 0)
		{
			t->next = list->head;
			list->head = t;
		}
		else
		{ 
PNODE u = list->head;
			unsigned int i;
			for(i = 0; i < pos - 1; i++)
			{
				u = u->next;
			}
			t->next = u->next;
			u->next = t;
		}
list->count++;
	}
	else

		LsAppend(list, point);
}
*/

void LsDelete(PLIST list, unsigned int pos, DESTROY_OBJECT destroy)
{
	if(!list)
	{
		cout << "LsDelete: Parameter Illegal!";
		exit(1);
	}
	if(list->count == 0)
		return;
	if(pos == 0)
	{
		PNODE t = list->head;
		list->head = t->next;
		if(!t->next)
			list->tail = NULL;
               (*destroy)((ADT)(t->data));
		//PtDestroy(t->data);
		delete t;
	}
	if(pos < list->count)
	{
		PNODE u = list->head, t = NULL;
		unsigned int i;
		for(i = 0; i < pos - 1; i++)
		{
			u = u->next;
		}
		t = u->next;
		u->next = t->next;
		if(!t->next)
			list->tail = u;
(*destroy)((ADT)(t->data));
		//PtDestroy(t->data);
		delete t;
	}
	list->count--;
}

/*
void LsDelete(PLIST list, unsigned int pos)
{
	if(!list)
	{
		cout << "LsDelete: Parameter Illegal!";
		exit(1);
	}
	if(list->count == 0)
		return;
	if(pos == 0)
	{
		PNODE t = list->head;
		list->head = t->next;
		if(!t->next)
			list->tail = NULL;
		PtDestroy(t->data);
		delete t;
	}
	if(pos < list->count)
	{
		PNODE u = list->head, t = NULL;
		unsigned int i;
		for(i = 0; i < pos - 1; i++)
		{
			u = u->next;
		}
		t = u->next;
		u->next = t->next;
		if(!t->next)
			list->tail = u;
		PtDestroy(t->data);
		delete t;
	}
	list->count--;
}
*/

//遍历链表
/*
void LsTraverse(PLIST list)
{
	if(!list)
	{
		cout << "LsTraverse: Parameter Illegal!";
		exit(1);
	}
	PNODE u = list->head;
	unsigned int i;
	for(i = 0; i < (list->count); i ++)
	{
               cout << i << "th element: "<< PtTransformToString(u->data) << endl;
		u = u ->next;
		//cout << i << "th element: "<< PtTransformToString(u->data) << endl;
	}
cout << "NULL" << endl;
}
*/

//遍历链表，数据节点的具体操作方法目前未知
//需要用到函数指针
//typedef void (*MANIPULATE_OBJECT)(void* e);
/*
void LsTraverse(PLIST list, MANIPULATE_OBJECT manipulate)
{
	if(!list)
	{
		cout << "LsTraverse: Parameter Illegal!";
		exit(1);
	}
	PNODE t = list->head;
	while(t)
	{
		if(manipulate)
			(*manipulate)((void*)t->data);
		t = t->next;
	}
}
*/


//当回调函数具有多个参数
void LsTraverse(PLIST list, MANIPULATE_OBJECT manipulate, const void* tag)
{
        if(!list)
        {
                cout << "LsTraverse: Parameter Illegal!";
                exit(1);
        }
        PNODE t = list->head;
        while(t)
        {
                if(manipulate)
                        (*manipulate)((void*)t->data, tag);
                t = t->next;
        }
}

/*
bool LsSearch(PLIST list, PPOINT point)
{
        if(!list)
        {
                cout << "LsSearch: Parameter Illegal!";
                exit(1);
        }
        PNODE u = list->head;
        unsigned int i;
        for(i = 1; i < (list->count + 1); i++)
        {
               if(PtCompare(u->data, point))
               {cout << "Found at " << i << "th element." << endl;
                 return true;}
                u = u ->next;
        }
return false;
}
*/

bool LsSearch(PLIST list, CADT object, COMPARE_OBJECT compare)
{
        if(!list)
        {
                cout << "LsSearch: Parameter Illegal!";
                exit(1);
        }
        PNODE u = list->head;
        unsigned int i;
        for(i = 1; i < (list->count + 1); i++)
        {
               if(compare)
{
if((*compare)(u->data, object))
               {cout << "Found at " << i << "th element." << endl;
                 return true;}
}
                u = u ->next;
        }
return false;
}

unsigned int LsGetCount(PLIST list)
{
return list->count;
}
bool LsIsEmpty(PLIST list)
{
return (list->count == 0);
}

bool LsIsFull(PLIST list)
{
return (list->count == list->qsize);
}

