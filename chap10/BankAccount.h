#ifndef _BANK_ACCOUNT_H
#define _BANK_ACCOUNT_H

#include <string>

class BankAccount
{
private:
enum {SIZE_1 = 25, SIZE_2 = 40};
char _name[SIZE_1];
char _account[SIZE_2];
double _balance;
public:
BankAccount();
BankAccount(const char* name, const char * account, double balance = 0.0);
~BankAccount();
void Show() const;
void Deposite(double cash);
void Withdraw(double cash);
};

class Person
{
private:
static const int LIMIT = 25;
std::string lname;
char fname[LIMIT];
public:
Person() {lname = ""; fname[0] = '\0';}
Person(const std::string& ln, const char* fn = "Heyyou");
void Show() const;
void FormalShow() const;
};


class Golf
{
enum {len = 40};
char fullname[len];
int handicap;
public:
Golf(const char * name, int hc);
Golf();
~Golf() {}
void Handicap(int hc);
void Show() const;
};


namespace SALES
{
class Sales
 {
static const int QUARTERS = 4;
double sales[QUARTERS];
double average;
double max;
double min;
public:
Sales(const double ar[], int n);
Sales();
void ShowSales() const;
 };
}


//5.Stack 
struct customer {
char fullname[35];
double payment;
};
typedef customer Item;
class Stack
{
private:
enum {MAX = 10}; // constant specific to class
Item items[MAX]; // holds stack items
int top; // index for top stack item
public:
Stack();
bool isempty() const;
bool isfull() const;
// push() returns false if stack already is full, true otherwise
bool push(const Item & item); // add item to stack
// pop() returns false if stack already is empty, true otherwise
bool pop(Item & item); // pop top into item
};


//8. List
class List
{
private:
enum {MAX = 10}; // constant specific to class
Item items[MAX]; // holds stack items
int top;
public:
List();
bool isempty() const;
bool isfull() const;
// push() returns false if stack already is full, true otherwise
bool push(const Item & item); // add item to stack
void visit(int i, void (*pf)(Item&));
};
void PrintCus(customer & c);


class Move
{
private:
double x;
double y;
public:
Move(double a = 0, double b =0);
//void ShowMove() const;
friend std::ostream & operator<<(std::ostream& os, const Move& m);
friend Move operator+(const Move& m1, const Move& m2);
//Move add(const Move& m);
void Reset(double a = 0, double b = 0);
};

class Plorg
{
enum {size = 19};
private:
char _name[size];
int _ci;
public:
Plorg(const char* name = "Plorga", int ic = 50);
void FixCi(int ci);
void Show() const;
};


#endif
