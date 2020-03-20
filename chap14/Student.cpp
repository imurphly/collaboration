#include "Student.h"
#include <cstring>
#include <cstdlib>
#include <ctime>

using std::srand;
using std::rand;
using std::time;
using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::strcpy;

int GenerateInt(int lowest, int highest)
{
double _d;
if(lowest > highest)
{
cout << "GenerateInt: Make sure lowest < highest.\n";
exit(1);
}
_d = (double)rand()/((double)RAND_MAX + 1);
return (lowest + (int)(_d*(highest - lowest + 1)));
}

//Person
Person::~Person() {}
void Person::Get()
{
cout << "Enter the firstname: ";
cin >> firstname;
cout << "Enter the lastname: ";
cin >> lastname;
}

void Person::Set()
{
cout << "Please Set the person.\n";
Get();
}

void Person::Show() const
{
cout << "Category: Person.\n";
Data();
}

//Gunslinger
void Gunslinger::Get()
{
cout << "Enter drawtime: ";
cin >> drawtime;
cout << "Enter record: ";
cin >> record;
}

void Gunslinger::Set()
{
cout << "Please Set the Gunslinger.\n";
Person::Get();
Get();
}

void Gunslinger::Show() const
{
cout << "Category: Gunslinger.\n";
Person::Data();
Data();
}

void BadDude::Show() const
{
cout << "Category: BadDude.\n";
Person::Data();
Gunslinger::Data();
}

void BadDude::Set()
{
cout << "Please set the BadDude.\n";
Person::Get();
Gunslinger::Get();
}


//ex2
Wine::Wine(const char* l, int y, const int yr[], const int bot[]): string(l), year(y), PairArray(ArrayInt(yr, y), ArrayInt(bot, y))
{}

Wine::Wine(const char* l, int y): string(l), year(y), PairArray(ArrayInt(y), ArrayInt(y))
{
}

void Wine::GetBottles()
{
if(year < 1)
{
cout << "no space;";
return;
}
cout << Label() <<" has " << year << " kinds of different year.\n";
for(int i = 0; i < year; ++i)
{cout << "Enter the year: ";
 cin >> PairArray::first()[i];
 cout << "Enter the bottles: ";
 cin >> PairArray::second()[i];
 cout << "\n"; }
}

void Wine::Show() const
{
cout << "Wine: " << Label() << "\n";
cout << "\tYear\tBottles\n";
for(int i = 0; i < year; ++i)
{cout << "\t" << PairArray::first()[i] << "\t" << PairArray::second()[i] << "\n";}
cout << "Total bottles for " << Label() << ": " << Sum() << endl;
}


/*
//Wine ex1
Wine::Wine(const char* l, int y, const int yr[], const int bot[]): name(l), year(y), data(std::valarray<int>(yr, y), std::valarray<int>(bot, y))
{}

Wine::Wine(const char* l, int y): name(l), year(y), data(ArrayInt(y), ArrayInt(y))
{
}

void Wine::GetBottles()
{
if(year < 1)
{
cout << "no space;";
return;
}

cout << Label() <<" has " << year << " kinds of different year.\n";
for(int i = 0; i < year; ++i)
{cout << "Enter the year: ";
 cin >> data.first()[i];
 cout << "Enter the bottles: ";
 cin >> data.second()[i];
 cout << "\n"; }
}

void Wine::Show() const
{
cout << "Wine: " << Label() << "\n";
cout << "\tYear\tBottles\n";
for(int i = 0; i < year; ++i)
{cout << "\t" << data.first()[i] << "\t" << data.second()[i] << "\n";}
cout << "Total bottles for " << Label() << ": " << Sum() << endl;
}
*/

//Student
std::ostream& Student::arr_out(std::ostream& os) const
{
int i;
int lim = ArrayDb::size();
if(lim > 0)
{
for(i = 0; i <lim; ++i)
{os << ArrayDb::operator[](i) << " ";
 if(i%5 == 4)
 cout << endl;}
if(i%5 !=0)
cout << endl;
}
else
os << "empty array.";
return os;
}

double Student::Average() const
{
if(ArrayDb::size() > 0)
return ArrayDb::sum()/ArrayDb::size();
else
return 0;
}

const std::string& Student::Name() const
{
return (const std::string&)*this;
}

/*
double & Student::operator[](int i)
{
return ArrayDb::operator[](i);
}

const double & Student::operator[](int i) const
{
return ArrayDb::operator[](i);
}
*/


std::istream& operator>>(std::istream& is, Student& s)
{
is >> (std::string&)s;
return is;
}

std::istream& getline(std::istream& is, Student& s)
{
is >> (std::string&)s;
return is;
}

std::ostream& operator<<(std::ostream& os, const Student& s)
{
os << "Scores for " << (const std::string&)s << endl;
s.arr_out(os);
return os;
}

//Worker
Worker::~Worker() {}

void Worker::Set()
{
cout << "Enter worker's  name: ";
getline(cin, fullname);
cout << "Enter worker's ID: ";
cin >> id;
while(cin.get() != '\n')
continue;
}

void Worker::Show() const
{
cout << "Name: " << fullname << " \n";
cout << "Employee ID: " << id << "\n";
}

//Singer
void Singer::Set()
{
Worker::Set();
Get();
}

char *Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};
void Singer::Get()
{
cout << "Enter the number of singer's voice range: \n ";
int i;
for(i = 0; i < Vtypes; ++i)
{
cout << i << ": " << pv[i] << "  ";
if(i%4==0)
cout << endl;
}
if(i%4 != 0)
cout << endl;
while(cin >> voice && (voice <0 || voice >= Vtypes))
cout << "Please enter a voice > 0 and <" << Vtypes << endl;
while(cin.get() != '\n')
continue;
}

void Singer::Show() const
{
Worker::Show();
Data();
}

void Singer::Data() const
{
cout << "Vocal range: " << pv[voice] << endl;
}

//Waiter
void Waiter::Set()
{
Worker::Set();
Get();
}

void Waiter::Get()
{
cout << "Enter waiter's panache rating: ";
cin >> panache;
while(cin.get() != '\n')
continue;
}

void Waiter::Show() const
{
Worker::Show();
Data();
}

void Waiter::Data() const
{
cout << "panache rating: " << panache << endl;
}

//SingerWaiter
void SingerWaiter::Set()
{
cout << "Enter singing waiter's name: ";
Worker::Set();
Waiter::Get();
Singer::Get();
}

void SingerWaiter::Show() const
{
cout << "Category: sing waiter\n";
Worker::Show();
Waiter::Data();
Singer::Data();
}

