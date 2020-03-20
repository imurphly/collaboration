#include "StringBad.h"
#include <cstring>
#include <cctype>


using std::cout;
using std::strlen;
using std::strcpy;
using std::endl;

//class Stack
/*
Stack::Stack(const Stack& st): size(st.size), top(st.top)
{
pitems = new Item(size);
for(int i = 0; i<top; ++i)
{
pitems[i] = st.pitems[i];
}
}
*/

Stack::Stack(int n):size(n), top(0) // create an empty stack
{
pitems = new Item[size];
}

Stack::~Stack()
{
delete []pitems;
}

bool Stack::isempty() const
{
return top == 0;
}
bool Stack::isfull() const
{
return top == size;
}
bool Stack::push(const Item & item)
{
if (top < size)
{
pitems[top++] = item;
return true;
}
else
return false;
}

bool Stack::pop(Item & item)
{
if (top > 0)
{
item = pitems[--top];
return true;
}
else
return false;
}



//class Stock
Stock::Stock():shares(0), share_val(0.0), total_val(0.0)
{
company = new char[1];
company[0] = '\0';
}

Stock::Stock(const char* co, long n , double pr):shares(n), share_val(pr)
{
company = new char[strlen(co)+1];
strcpy(company, co);
set_tot();
}

Stock::Stock(const Stock& stk):shares(stk.shares),share_val(stk.share_val)
{
company = new char[strlen(stk.company)+1];
strcpy(company, stk.company);
set_tot();
}

Stock& Stock::operator=(const Stock& stk)
{
shares = stk.shares;
share_val = stk.share_val;
company = new char[strlen(stk.company)+1];
strcpy(company, stk.company);
set_tot();
return *this;
}

Stock::~Stock()
{
delete [] company;
}

void Stock::buy(long num, double price)
{
shares +=num;
share_val = price;
set_tot();
}

void Stock::sell(long num, double price)
{
shares -=num;
share_val = price;
set_tot();
}

void Stock::update(double price)
{
share_val = price;
set_tot();
}

std::ostream& operator<<(std::ostream& os, const Stock& stk)
{
os << stk.company << ": " << stk.shares << "stocks, " <<  stk.share_val << " yuan every stock, total: " << stk.total_val << " yuan.\n";
return os;
}

const Stock& Stock::topval(const Stock& s) const
{
if(s.total_val > total_val)
return s;
else
return *this;
}


//class Cow
Cow::Cow()
{
name[0] = '\0';
hobby = new char[1];
hobby[0] = '\0';
weight = 0;
}

Cow::Cow(const char* nm, const char* ho, double wt):weight(wt)
{
strcpy(name, nm);
hobby = new char[strlen(ho)+1];
strcpy(hobby, ho);
}

Cow::~Cow()
{
delete []hobby;
}

Cow::Cow(const Cow& c):weight(c.weight)
{
strcpy(name, c.name);
hobby = new char[strlen(c.hobby)+1];
strcpy(hobby, c.hobby);
}

Cow& Cow::operator=(const Cow& c)
{
strcpy(name, c.name);
hobby = new char[strlen(c.hobby)+1];
strcpy(hobby, c.hobby);
weight = c.weight;
return *this;
}

void Cow::show() const
{
cout << "name, hobby, weight: " << name << " " << hobby << " " << weight << endl;
}


//class StringBad
int StringBad::num_str = 0;

/*
StringBad::StringBad()
{
len = 4;
str = new char[len+1];
std::strcpy(str, (char*)"C++");
num_str++;
cout << num_str << ":\"" << str << "\" default object created.\n";
}
*/


StringBad::StringBad(const char* s)
{
len = std::strlen(s);
str = new char[len+1];
std::strcpy(str, s);
num_str++;
//cout << num_str << ":\"" << str << "\" object created.\n";
}


StringBad::StringBad()
{
/*
len = std::strlen("C++");
str = new char[len+1];
std::strcpy(str, (char*)"C++");
*/
len = 0;
str = new char[1];
str[0] = '\0';
num_str++;
//cout << num_str << ":\"" << str << "\" default object created.\n";
}

StringBad::StringBad(const StringBad& s)
{
++num_str;
len = s.len;
str = new char[len+1];
strcpy(str, s.str);
cout << num_str << ":\"" << str << "\" object copied.\n";
}

StringBad& StringBad::operator=(const StringBad& s)
{
if(this == &s)
return *this;
delete [] str;
len = s.len;
str = new char[len+1];
strcpy(str, s.str);
cout <<  "\"" << str << "\" object copied by object.\n";
return *this;
}

StringBad& StringBad::operator=(const char* s)
{
delete [] str;
len = std::strlen(s);
str = new char[len+1];
strcpy(str, s);
cout << "\"" << str << "\" object copied by string.\n";
return *this;
}

StringBad::~StringBad()
{
cout << "\"" << str << "\" object deleted. ";
--num_str;
cout << num_str << " lefted. \n";
delete []str;
}

std::ostream& operator<<(std::ostream& os, const StringBad& st)
{
os << st.str;
return os;
}


//这里可以使用std::strcmp函数比较大小，哎我就是个大傻逼
bool operator<(const StringBad& s1, const StringBad& s2)
{
int l = (s1.length() <= s2.length())? s1.length():s2.length();
int i = 0;
while(i++ < l)
{
if(s1.str[i] < s2.str[i])
return true;
else if(s1.str[i] > s2.str[i])
return false;
}
if(s1.len < s2.len)
return true;
else
return false;
}

bool operator>(const StringBad& s1, const StringBad& s2)
{
if((!(s1 < s2))&&(!(s1 == s2)))
return true;
else
return false;
}

bool operator==(const StringBad& s1, const StringBad& s2)
{
if(s1.len == s2.len)
{
int i = 0, l = s1.len;
while(i++ < l)
{if((s1.str[i]) != (s2.str[i]))
 { --i; break;}
 }
if(i = l)
return true;
}
return false;
}

std::istream&  operator>>(std::istream& is, StringBad& s)
{
char temp[StringBad::CINLIM];
is.get(temp, StringBad::CINLIM);
if(is)
s = temp;
while(is && is.get() != '\n')
continue;
return is;
}

char& StringBad::operator[](int i)
{
char& c = str[i];
return c;
}

const char& StringBad::operator[](int i) const
{
const char& c = str[i];
return c;
}

StringBad operator+(const StringBad& s1, const StringBad& s2)
{
char *stemp = new char[strlen(s1.str)+strlen(s2.str)+1];
strcpy(stemp,s1.str);
strcat(stemp,s2.str);
StringBad sb(stemp);
delete [] stemp;
return sb;
}

void StringBad::Stringupper()
{
for(int i = 0; str[i]!='\0'; ++i)
 {
if(std::islower(str[i]))
 str[i] = std::toupper(str[i]);
  }
}

void StringBad::Stringlower()
{
for(int i = 0; str[i]!='\0'; ++i)
 {
if(std::isupper(str[i]))
 str[i] = std::tolower(str[i]);
  }
}

int StringBad::CharSearch(const char& c) const
{
int count = 0;
for(int i = 0; str[i]!='\0'; ++i)
{
if(str[i]==c)
++count;
}
return count;
}

