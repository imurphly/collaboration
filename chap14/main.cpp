#include "Student.h"
#include <cstdlib>
#include <ctime>

using namespace std;

void Set(Student& s, int n);

int main()
{

{
const int SIZE = 4;
Person * lolas[SIZE];
int ct;
for(ct = 0; ct < SIZE; ++ct)
{
char choice;
cin >> choice;
if(choice == 'q')
break;
switch(choice)
{
case 'p': lolas[ct] = new Person;break;
case 'g': lolas[ct] = new Gunslinger; break;
case 'y': lolas[ct] = new Pokerplayer; break;
case 'b': lolas[ct] = new BadDude; break;
default: exit(EXIT_FAILURE);
  }
cin.get();
lolas[ct]->Set();
 }
cout << "\n\n";
for(int i =0; i< ct; ++i)
{
cout << "\n";
lolas[i]->Show();
}
for(int i =0; i< ct; ++i)
{
delete lolas[i];
}

}


/*
{
using std::cin;
using std::cout;
using std::endl;
cout << "Enter name of wine: ";
char lab[50];
cin.getline(lab, 50);
cout << "Enter number of years: ";
int yrs;
cin >> yrs;
Wine holding(lab, yrs); // store label, years, give arrays yrs elements
holding.GetBottles(); // solicit input for year, bottle count
holding.Show(); // display object contents
const int YRS = 3;
int y[YRS] = {1993, 1995, 1998};
int b[YRS] = { 48, 60, 72};
// create new object, initialize using data in arrays y and b
Wine more("Gushing Grape Red",YRS, y, b);
more.Show();
cout << "Total bottles for " << more.Label() // use Label() method
<< ": " << more.Sum() << endl; // use sum() method
cout << "Bye\n";
}


{
counts<int> ();
HasFriendT<int> hfi1(10);
HasFriendT<int> hfi2(20);
HasFriendT<double> hfdb(10.5);
report(hfi1);
report(hfi2);
report(hfdb);
counts<int> ();
counts<double> ();
}


{
int n;
double be;
Crab<Stack> ne;
cout << "Enterm int doublr pairs, such as 4 3.5 (0 0 to end):\n";

while(cin >> n >> be && n > 0 && be > 0)
{
if(!ne.push(n, be))
break;
}
while(ne.pop(n, be))
{
cout << n << ", " << be << endl;}
cout << "Done.\n";
}


{
beta<double> guy(3.5, 3);
guy.Show();
cout << guy.blab(10, 2.3) << endl;
cout << guy.blab(10.0, 2.3) << endl;
}


{
const int SIZE = 3;
Worker * lolas[SIZE];
int ct;
for(ct = 0; ct < SIZE; ++ct)
{
char choice;
cin >> choice;
if(choice == 'q')
break;
switch(choice)
{
case 'w': lolas[ct] = new Waiter;break;
case 's': lolas[ct] = new Singer; break;
case 't': lolas[ct] = new SingerWaiter; break;
  }
cin.get();
lolas[ct]->Set();
 }
cout << "\n\n";
for(int i =0; i< ct; ++i)
{
cout << "\n";
lolas[i]->Show();
}
for(int i =0; i< ct; ++i)
{
delete lolas[i];
}

}


{
const int LIM = 4;
Waiter bob("bob", 314L, 5);
Singer bev("bevery", 522L, 3);
Waiter w1;
Singer s1;
Worker *pw[LIM] = {&bob, &bev, &w1, &s1};
int i;
for(i = 0; i <LIM; ++i)
{
pw[i]->Set();
}
for(i = 0; i <LIM; ++i)
{
pw[i]->Show();
}
cout << endl;
}


{
const int NUM = 10;
std::srand(std::time(0));
cout << "Please enter stack size: ";
int stacksize;
cin >> stacksize;
PStack<const char*> st(stacksize);

const char* in[NUM] = {
   "1: Hank gilgamesh", "2: kiki ishtar", "3: betty rocket", "4: ivan flag", "5: wolfgang kible",
   "6: portia koop", "7: joy almodo", "8: xavarie paprika", "9: juan moore", "10: misha mache"              
   };
const char* out[NUM];
int processed = 0;
int nextin = 0;
while(processed < NUM)
{
if(st.isempty())
st.push(in[nextin++]);
else if(st.isfull())
st.pop(out[processed++]);
else if(std::rand() %2 && nextin < NUM)
st.push(in[nextin++]);
else
st.pop(out[processed++]);
}
for(int i = 0; i < NUM; ++i)
std::cout << out[i] << endl;
cout << "Bye.\n";
}


{
int temp = 0;
int total = 0;
Stack<int> s;
for(int i=0; i< 4;++i)
{s.push(i);}
for(int i=0; i < 4; ++i)
{
s.pop(temp);
total += temp;
}
cout << "total: " << total << endl;
}




{
Stack<customer> s;
double total = 0.0;
customer temp {"temp", 0.0};
customer c[4] {{"liu", 10.0},{"yan", 20.0},{"yuan", 30.0},{"hang", 40.0}};
for(int i=0; i < 4; ++i)
{
cout << c[i].fullname << " " << c[i].payment << endl;
s.push(c[i]);
}
cout << "\n\n";
for(int i=0; i < 4; ++i)
{
s.pop(temp);
cout << temp.fullname << " " << temp.payment << endl;
total += temp.payment;
}
cout << "total: " << total << endl;
}


{
const int STU_LEN = 3;
const int SCORE_LEN = 5;
Student stu[STU_LEN] = {Student(SCORE_LEN), Student(SCORE_LEN), Student(SCORE_LEN)};
for(int i = 0; i < STU_LEN; ++i)
 {
Set(stu[i], SCORE_LEN);
 }
cout << "\n\n";
for(int i = 0; i < STU_LEN; ++i)
{cout << stu[i].Name() << endl;}
cout << "\nResults:\n";
for(int i = 0; i < STU_LEN; ++i)
{ cout << endl << stu[i];
   cout << "average: " << stu[i].Average() << endl;}
cout << "Done.\n";
}


{
double score[5] = {45, 56, 67, 78, 79};
const Student stu("Liu yan", score, 5);
cout << stu[2] << endl;
}
*/

return 0;
}

void Set(Student& s, int n)
{
cout << "Please enter the student's name: ";
getline(cin, s);
cout << "Please enter " << n << "quiz scores: \n";
int i;
for(i = 0; i< n; ++i)
cin >> s[i];
while(cin.get()!= '\n')
continue;
}
