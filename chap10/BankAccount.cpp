#include <iostream>
#include <cstring>
#include <string>
#include "BankAccount.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;

//7. Plorg
Plorg::Plorg(const char* name, int ic)
{
strcpy(_name, name);
_ci = ic;
}

void Plorg::FixCi(int ci)
{
_ci = ci;
}

void Plorg::Show() const
{
cout << _name << ", " << _ci << endl;  
}


//Move
Move::Move(double a, double b)
{
x = a;
y = b;
}

//void Move::ShowMove() const
ostream & operator<<(ostream& os, const Move& m)
{
os << "x, y: " << m.x  << ", " <<m.y << endl;
return os;
}

/*
Move Move::add(const Move& m)
{
x += m.x;
y +=m.y;
return *this;
}
*/

Move operator+(const Move& m1, const Move& m2)
{
Move m;
m.x = m1.x + m2.x;
m.y = m1.y + m2.y;
return m;
}

void Move::Reset(double a, double b)
{
x = a;
y = b;
}


//BankAccount
BankAccount::BankAccount() 
{
_name[0] = '\0';
_account[0] = '\0';
_balance = 0.0;
}

BankAccount::BankAccount(const char* name, const char * account, double balance)
{
strcpy(_name, name);
strcpy(_account, account);
_balance = balance;
}

BankAccount::~BankAccount() {}

void BankAccount::Show() const
{
cout << "name: " << _name << endl << "account: " << _account << endl << "balance: " << _balance << endl;
}

void BankAccount::Deposite(double cash)
{
_balance += cash;
}

void BankAccount::Withdraw(double cash)
{
_balance -= cash;
}


//Person
Person::Person(const string& ln, const char* fn)
{
lname = ln;
strcpy(fname, fn);
}

void Person::Show() const
{
cout << fname << " " << lname << endl;
}

void Person::FormalShow() const
{
cout << lname << ", " << fname << endl;
}

//Golf
Golf::Golf(const char * name, int hc)
{
strcpy(fullname, name);
handicap = hc;
}

Golf::Golf()
{
cout << "Please input fullname: ";
cin.getline(fullname, len);
cout << "handicap: ";
cin >> handicap;
cin.get();
}

void Golf::Handicap(int hc)
{
handicap = hc;
}

void Golf::Show() const
{
cout << "fullname: " << fullname << endl << "handicap: " << handicap << endl;
}


//Sales
namespace SALES
{
	Sales::Sales(const double ar[], int n)
	{
		if(n < QUARTERS)
		{
			for(int i=0; i<n ; ++i)
				sales[i] = ar[i];
			for(int i=n; i<QUARTERS;++i)
				sales[i] = 0;
		}
		else
		{
			for(int i=0; i< QUARTERS; ++i)
				sales[i] = ar[i];
		}

		//double max = min = total =s.sales[0];
		double temp, _max, _min, total;
_max = _min = total =sales[0];
		for(int i=1; i< QUARTERS; ++i)
		{
			temp = sales[i];
			_max = (temp >_max?temp: _max);
			_min = (temp < _min? temp: _min);
			total += temp;
		}
		average = total/QUARTERS;
		max = _max;
		min = _min;
	}

	Sales::Sales()
	{
		cout << "Enter double items: ";
                cin >> sales[0];
		//double max = min = total =s.sales[0];
		double temp, _max, _min, total;
                _max = _min = total =sales[0];
               cout << _max << " " << _min  << " "<< total << " " <<endl;
		for(int i=1; i< QUARTERS; ++i)
		{
			cin >> sales[i];
			temp = sales[i];
			_max = (temp >_max?temp: _max);
			_min = (temp < _min? temp: _min);
			total += temp;
		}
		average = total/QUARTERS;
		max = _max;
               
		min = _min;
	}

	void Sales::ShowSales() const
	{
		for(int i=0; i< QUARTERS; ++i)
		{cout << i << "th item: " << sales[i] << endl;}
		cout << "average: " << average << endl;
		cout << "max: " << max << endl;
		cout << "min: " << min << endl;
	}

}


//Stack
Stack::Stack() // create an empty stack
{
top = 0;
}
bool Stack::isempty() const
{
return top == 0;
}
bool Stack::isfull() const
{
return top == MAX;
}
bool Stack::push(const Item & item)
{
if (top < MAX)
{
items[top++] = item;
return true;
}
else
return false;
}
bool Stack::pop(Item & item)
{
if (top > 0)
{
item = items[--top];
return true;
}
else
return false;
}

//8. List
List::List() // create an empty stack
{
top = 0;
}
bool List::isempty() const
{
return top == 0;
}
bool List::isfull() const
{
return top == MAX;
}
bool List::push(const Item & item)
{
if (top < MAX)
{
items[top++] = item;
return true;
}
else
return false;
}

void List::visit(int i, void (*pf)(Item& ite))
{
if((i < MAX) &&(i >=0))
(*pf)(items[i]);
else
{
cout << "index not more than 10!" << endl;
exit(EXIT_FAILURE);
}
}

void PrintCus(customer & c)
{
cout << c.fullname << ", " << c.payment << endl;
}

