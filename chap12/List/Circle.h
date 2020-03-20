
//利用Point结构体创建圆库
//成员：圆心center，　半径radius
struct CIRCLE;
typedef struct CIRCLE* PCIRCLE;

PCIRCLE CeCreat(int x, int y, int r);
void CeDestroy(PCIRCLE c);

void CeGetValue(PCIRCLE c, int* x, int* y, int* r);
void CeSetVaule(PCIRCLE c, int x, int y, int r);
void CePrint(PCIRCLE c);
char* CeTransformToString(PCIRCLE c, const char* format);

//思考：　我能联系点库和圆库之间的关系吗，如何用圆库创建点库？
