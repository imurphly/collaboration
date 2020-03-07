const int len = 40;
struct golf
{
char fullname[40];
int handicap;
};

void setgolf(golf& g, const char * name, int hc);
int setgolf(golf& g);
void handicap(golf& g, int hc);
void showgolf(const golf& g);

struct chaff
{
char dross[20];
int slag;
};
