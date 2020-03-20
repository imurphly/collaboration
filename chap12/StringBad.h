#include <iostream>
#ifndef _STRING_BAD_H
#define _STRING_BAD_H

typedef unsigned long Item;
class StringBad
{
private:
char* str;
int len;
static int num_str;
static const int CINLIM = 80;
public:
StringBad(const char* s);
StringBad();
//复制构造函数
StringBad(const StringBad& s);
//重载赋值运算符
StringBad& operator=(const StringBad& s);
StringBad& operator=(const char* s);
~StringBad();
friend std::ostream& operator<<(std::ostream& os, const StringBad& st);
int length() const {return len;}
friend bool operator<(const StringBad& s1, const StringBad& s2);
friend bool operator>(const StringBad& s1, const StringBad& s2);
friend bool operator==(const StringBad& s1, const StringBad& s2);
friend std::istream&  operator>>(std::istream& os, StringBad& s);
char& operator[](int i);
const char& operator[](int i) const;
static int HowMany() {return num_str;}
friend StringBad operator+(const StringBad& s1, const StringBad& s2);
void Stringlower();
void Stringupper();
int CharSearch(const char& c) const;
};

class Cow
{
char name[20];
char* hobby;
double weight;
public:
Cow();
Cow(const char* nm, const char* ho, double wt);
~Cow();
Cow(const Cow& c);
Cow& operator=(const Cow& c);
void show() const;
};

class Stock
{
private:
char* company;
int shares;
double share_val;
double total_val;
void set_tot() {total_val = shares*share_val;}
public:
Stock();
Stock(const char* co, long n = 0, double pr = 0.0);
Stock(const Stock& stk);
Stock& operator=(const Stock& stk);
~Stock();
void buy(long num, double price);
void sell(long num, double price);
void update(double price);
friend std::ostream& operator<<(std::ostream& os, const Stock& stk);
const Stock& topval(const Stock& s) const;
};

class Stack
{
private:
enum {MAX = 10}; // constant specific to class
Item *pitems; // holds stack items
int size;
int top; // index for top stack item
Stack(const Stack& st) {}
Stack& operator=(const Stack& st) {return *this;}
public:
Stack(int n = MAX);
//Stack(const Stack& st);
~Stack();
bool isempty() const;
bool isfull() const;
// push() returns false if stack already is full, true otherwise
bool push(const Item & item); // add item to stack
// pop() returns false if stack already is empty, true otherwise
bool pop(Item & item); // pop top into item
//Stack& operator=(const Stack& st);
};

#endif
