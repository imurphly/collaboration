#include <iostream>
#include "Circle.h"
#include "ptr.h"
#include <cstdio>
#include <cstdlib>

using namespace std;
struct POINT{int x, y;};
typedef struct POINT* PPOINT;

struct CIRCLE{
PPOINT p;
int r;};

PCIRCLE CeCreat(int x, int y, int r)
{
PCIRCLE c = new CIRCLE;

POINT* p = new POINT;
p->x = x;
p->y = y;

c->p = p;
c->r =r;
return c;
}

void CeDestroy(PCIRCLE c)
{
if(c)
{
if(c->p)
{delete c->p;
c->p = NULL;}
delete c;
c = NULL;
}
}

void CeGetValue(PCIRCLE c, int* x, int* y, int* r)
{
if(c->p)
{if(x) *x = c->p->x;
 if(y) *y = c->p->y;}
*r = c->r;
}

void CeSetVaule(PCIRCLE c, int x, int y, int r)
{
if(c->p)
{
c->p->x = x;
c->p->y = y;
}
c->r = r;
}

void CePrint(PCIRCLE c)
{
/*
if(c->p)
{
cout << "center: " << "(" << c->p->x << ", " << c->p->y << ")" << endl;
cout << "radius: " << c->r << endl;
}
*/
cout << CeTransformToString(c,"center=(%d, %d), radius=%d") << endl;
}

char* CeTransformToString(PCIRCLE c, const char* format)
{
//BUFSIZE 的长度等于８１９２，一般用来定义数组的长度
char buf[BUFSIZ];
if(c->p)
{
sprintf(buf, format, c->p->x, c->p->y, c->r);
return DuplicateString(buf);
}
else return NULL;
}
