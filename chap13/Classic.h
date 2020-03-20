#ifndef _CLASSIC_H
#define _CLASSIC_H
#include <iostream>

class Cd
{
private:
char *performance;
char label[20];
int selections;
double playtime;
public:
Cd(char *s1 = "none per", char* s2="none label", int n=0, double x=0.0);
Cd(const Cd& d);
virtual void Report() const;
Cd& operator=(const Cd& d);
virtual ~Cd() {delete [] performance;}
};

class Classic: public Cd
{
private:
char *str;
public:
Classic(char *s = "none str", char *s1 = "none per", char* s2="none label", int n=0, double x=0.0);
Classic(const Cd& d, char *s);
Classic(const Classic& c);
~Classic() {delete [] str;}
virtual void Report() const override;
Classic& operator=(const Classic& c);
};

class DMA
{
private:
char *label;
int rating;
public:
DMA(const char* l="null", int r = 0);
DMA(const DMA& da);
DMA& operator=(const DMA& da);
virtual ~DMA()=0;
virtual void View() const;
friend std::ostream& operator<<(std::ostream& os, const DMA& da);
};

class baseDMA: public DMA
{
public:
baseDMA(const char* l="null", int r = 0);
};

class lacksDMA: public DMA
{
private:
enum {COLOR_LEN = 40};
char color[COLOR_LEN];
public:
lacksDMA(const char *cr = "blank", const char* l="null", int r = 0);
lacksDMA(const char *cr, const DMA& da);
lacksDMA& operator=(const lacksDMA& la);
virtual void View() const;
friend std::ostream& operator<<(std::ostream& os, const lacksDMA& da);
};

class hasDMA: public DMA
{
private:
char * style;
public:
hasDMA(const char *sty = "none", const char* l="null", int r = 0);
hasDMA(const char *sty, const DMA& da);
hasDMA& operator=(const hasDMA& ha);
virtual void View() const;
friend std::ostream& operator<<(std::ostream& os, const hasDMA& da);
};
#endif
