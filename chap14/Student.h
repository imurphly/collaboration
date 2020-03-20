#ifndef _STUDENT_H
#define _STUDENT_H
#include <iostream>
#include <string>
#include <valarray>
#include <cstdlib>
#include <ctime>

int GenerateInt(int lowest, int highest);

//ex4
//Person
class Person
{
private:
std::string firstname;
std::string lastname;
protected:
virtual void Data() const {std::cout << firstname << " " << lastname << "\n";}
virtual void Get();
public:
Person(): firstname("none fname"), lastname("none lname") {}
Person(const char* fn, const char* ln): firstname(fn), lastname(ln) {} 
virtual void Show() const;
virtual ~Person();
virtual void Set();
};

class Gunslinger: virtual public Person
{
protected:
void Data() const {std::cout << "records: " << record << std::endl;}
void Get();
private:
double drawtime;
int record;
public:
Gunslinger(const char* fn = "none fname", const char* ln = "none lname", double dt= 0.0, int rd=0): Person(fn, ln), drawtime(dt), record(rd) {}
Gunslinger(const Person& p, double dt, int rd): Person(p), drawtime(dt), record(rd) {}
double Draw() {return drawtime;}
void Show() const;
void Set();
};

class Pokerplayer: virtual public Person
{
private:
int nextcard;
public:
Pokerplayer(): Person() {}
Pokerplayer(const char* fn, const char* ln): Person(fn, ln) {}
int Draw() {return GenerateInt(1, 52);}
};

class BadDude: public Gunslinger, public Pokerplayer
{
public:
BadDude(const char* fn= "none fname", const char* ln="none lname", double dt=0.0, int rd=0): Person(fn, ln), Gunslinger(fn, ln, dt, rd), Pokerplayer(fn, ln) {}
double GDraw() {Gunslinger::Draw();}
int CDraw() {Pokerplayer::Draw();}
void Show() const;
void Set();
};


template<typename T1, typename T2>
class Pair
{
private:
T1 a;
T2 b;
public:
T1& first() {return a;}
T2& second() {return b;}
T1 first() const {return a;}
T2 second() const {return b;}
Pair(const T1& aval, const T2& bval): a(aval), b(bval) {}
Pair() {}
};

typedef std::valarray<int> ArrayInt;
typedef Pair<std::valarray<int>, std::valarray<int> > PairArray;
//ex2
class Wine: private std::string, private PairArray
{
private:
int year;
public:
Wine(): std::string("no name"), year(0), PairArray(ArrayInt(), ArrayInt()) {}
Wine(const char* l, int y, const int yr[], const int bot[]);
Wine(const char* l, int y);
void GetBottles();
const std::string& Label() const {return (const std::string&)(*this);}
int Sum() const {return PairArray::second().sum();}
void Show() const;
};


/*
//ex1
class Wine
{
private:
typedef std::valarray<int> ArrayInt;
typedef Pair<std::valarray<int>, std::valarray<int> > PairArray;
std::string name;
int year;
PairArray data;
public:
Wine() {}
Wine(const char* l, int y, const int yr[], const int bot[]);
Wine(const char* l, int y);
void GetBottles();
const std::string& Label() const {return name;}
int Sum() const {return data.second().sum();}
void Show() const;
};
*/

//14.23 友元模板
template <typename T> void counts();
template <typename T> void report(T& );

template <typename TT>
class HasFriendT
{
private:
TT item;
static int ct;
public:
HasFriendT(const TT & i): item(i) {++ct;}
~HasFriendT() {--ct;}
friend void counts<TT>();
friend void report<>(HasFriendT<TT>&);
};

template <typename TT>
int HasFriendT<TT>::ct = 0;

template <typename TT>
void counts()
{
std::cout << HasFriendT<TT>::ct << std::endl;
}

template <typename T>
 void report(T& hf)
//template <typename TT>
//void report(HasFriendT<TT>& hf)
{
std::cout << hf.item << std::endl;
}



//14.21 模板参数
template <template <typename T> class Thing >
class Crab
{
private:
Thing<int> s1;
Thing<double> s2;
public:
Crab() {}
bool push(int& a, double& b) {return s1.push(a) && s2.push(b);}
bool pop(int& a, double& b) {return s1.pop(a)&& s2.pop(b);}
};

//Beta 14.19
template <typename T>
class beta
{
private:
template <typename V>
class hold
{
private:
V val;
public:
hold(V v=0): val(v) {}
void Show() const {std::cout << val << std::endl;}
V Value() const {return val;}
 };
hold<T> q;
hold<int> n;
public:
beta(T t, int i): q(t), n(i) {}
template<typename U>
U blab(U u, T t) {return (n.Value() + q.Value())*u/t;}
void Show() const {q.Show(); n.Show();}
};

//使用模板参数来提供常规数组的大小，14.17
template <typename T, int n>
class ArrayTP
{
private:
T ar[n];
public:
ArrayTP() {}
explicit ArrayTP(const T& v);
virtual T& operator[](int i);
virtual const T& operator[](int i) const;
};

template <typename T, int n>
ArrayTP<T,n>::ArrayTP(const T& v)
{
for(int i = 0; i < n; ++i)
ar[i] = v;
}

template <typename T, int n>
T& ArrayTP<T, n>::operator[](int i)
{
if(i < 0 || i >= n)
{std::cerr << "Error in array limits: " << i << " is out of range.\n";
exit(EXIT_FAILURE);}
return ar[i];
}

template <typename T, int n>
const T& ArrayTP<T, n>::operator[](int i) const
{
if(i < 0 || i >= n)
{std::cerr << "Error in array limits: " << i << " is out of range.\n";
exit(EXIT_FAILURE);}
return ar[i];
}

//Student
class Student: private std::string , private std::valarray<double>
{
private:
typedef std::valarray<double> ArrayDb;
std::ostream& arr_out(std::ostream& os) const;
public:
Student(): std::string("Null Student"), ArrayDb() {}
explicit Student(const std::string& s) : std::string(s), ArrayDb() {}
explicit Student(int n): std::string("Nully"), ArrayDb(n) {}
Student(const std::string& s, int n): std::string(s), ArrayDb(n) {}
Student(const std::string& s, const ArrayDb& a): std::string(s), ArrayDb(a) {}
Student(const std::string& s, const double* pd, int n): std::string(s), ArrayDb(pd, n) {}
~Student() {}
double Average() const;
const std::string& Name() const;
//double & operator[](int i);
//const double & operator[](int i) const;
friend std::istream& operator>>(std::istream& is, Student& s);
friend std::istream& getline(std::istream& is, Student& s);
friend std::ostream& operator<<(std::ostream& os, const Student& s);

using std::valarray<double>::operator[];
};

//程序清单14.7
class Worker
{
private:
std::string fullname;
long id;
public:
Worker() : fullname("no one"), id(0) {}
Worker(const std::string& s, long n): fullname(s), id(n) {}
virtual ~Worker()=0;
virtual void Set() = 0;
virtual void Show() const=0;
};

class Singer: virtual public Worker
{
protected:
enum {other, alto, contralto, soprano, bass, baritone, tenor};
enum {Vtypes = 7};
private:
static char* pv[Vtypes];
int voice;
public:
Singer(): Worker(), voice(0) {}
Singer(const std::string& s, long n, int v=other): Worker(s, n), voice(v) {}
Singer(const Worker& wk, int v= other): Worker(wk), voice(v) {}
void Set();
void Get();
void Show() const;
void Data() const;
};

class Waiter: virtual public Worker
{
private:
int panache;
public:
Waiter(): Worker(), panache(0) {}
Waiter(const std::string& s, long n, int p =0): Worker(s, n), panache(p) {}
Waiter(const Worker& wk, int p=0): Worker(wk), panache(p) {}
void Set();
void Get();
void Show() const;
void Data() const;
};

class SingerWaiter: public Singer, public Waiter
{
public:
SingerWaiter() {}
SingerWaiter(const std::string& s, long n, int p=0, int v = other): Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
SingerWaiter(const Worker& wk, int p = 0, int v = other): Worker(wk), Waiter(wk, p), Singer(wk, v) {}
//SingerWaiter(const Worker& wk, int p = 0): Worker(wk), Waiter(wk, p), Singer(wk) {}
//SingerWaiter(const Worker& wk, int v = other): Worker(wk), Waiter(wk), Singer(wk, v) {}
void Set();
void Show() const;
};


//指针栈
template <typename Type>
class PStack
{
private:
enum {SIZE = 10}; // constant specific to class
int stacksize;
int top; // index for top stack item
Type *items;
public:
explicit PStack(int ss=SIZE);
PStack(const PStack& s);
~PStack() {delete [] items;}
PStack& operator=(const PStack& s);
bool isempty() const {return top==0;}
bool isfull() const {return top == stacksize;}
// push() returns false if stack already is full, true otherwise
bool push(const Type & item); // add item to stack
// pop() returns false if stack already is empty, true otherwise
bool pop(Type & item); // pop top into item
};

template <typename Type>
PStack<Type>::PStack(int ss): stacksize(ss), top(0)
{
items = new Type[stacksize];
}

template <typename Type>
PStack<Type>::PStack(const PStack<Type>& s):stacksize(s.stacksize), top(s.top)
{
items = new Type[stacksize];
for(int i = 0; i < top; ++i)
items[i] = s.items[i];
}

template <typename Type>
PStack<Type>& PStack<Type>::operator=(const PStack<Type>& s)
{
if(this = &s)
return *this;
stacksize = s.stacksize;
top = s.top;
delete [] items;
items = new Type[stacksize];
for(int i = 0; i < top; ++i)
items[i] = s.items[i];
}

template <typename Type>
bool PStack<Type>::push(const Type & item)
{
if (top < stacksize)
{
items[top++] = item;
return true;
}
else
return false;
}

template <typename Type>
bool PStack<Type>::pop(Type & item)
{
if (top > 0)
{
item = items[--top];
return true;
}
else
return false;
}




//栈
struct customer {
char fullname[35];
double payment;
};
template <typename Type>
class Stack
{
private:
enum {MAX = 10}; // constant specific to class
//Item items[MAX]; // holds stack items
Type items[MAX];
int top; // index for top stack item
public:
Stack();
bool isempty() const;
bool isfull() const;
// push() returns false if stack already is full, true otherwise
bool push(const Type & item); // add item to stack
// pop() returns false if stack already is empty, true otherwise
bool pop(Type & item); // pop top into item
};

//Stack template
template <typename Type>
Stack<Type>::Stack() // create an empty stack
{
top = 0;
}

template <typename Type>
bool Stack<Type>::isempty() const
{
return top == 0;
}

template <typename Type>
bool Stack<Type>::isfull() const
{
return top == MAX;
}

template <typename Type>
bool Stack<Type>::push(const Type & item)
{
if (top < MAX)
{
items[top++] = item;
return true;
}
else
return false;
}

template <typename Type>
bool Stack<Type>::pop(Type & item)
{
if (top > 0)
{
item = items[--top];
return true;
}
else
return false;
}

#endif
