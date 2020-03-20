#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <cctype>
#include <cstring>
#include <fstream>
#include <set>
#include <cmath>
#include <cstdlib>
#include <list>
#include <memory>
#include "Useless.h"
#include <utility>

using namespace std;
void show(string& str) {cout << str << " ";}

void model()
{
unique_ptr<double> pt(new double);
*pt = 2.5;
}
/*
bool HuiWen(string& str)
{
string s(str);
reverse(str.begin(), str.end());
ostream_iterator<char, char> out(cout, "");
copy(str.begin(), str.end(), out);
if(s==str)
return true;
else
return false;
}

template <class T>
int reduce(T ar[], int n)
{
sort(ar, ar+n);
T* pen = unique(ar, ar+n);
return pen-ar;
}


template<> int reduce(long ar[], int n)
{
sort(ar, ar+n);
long* pen = unique(ar, ar+n);
return pen-ar;
}

vector<int> lotto(int a, int b)
{
vector<int> r, temp;
for(int i =0; i< a; ++i)
r.push_back(i+1);
for(int i=0; i < b; ++i)
{
random_shuffle(r.begin(), r.end());
temp.push_back(r[0]);
}
return temp;
}

set<string> guest()
{
set<string> lists;
string temp;
cout << "Enter names of your friend(quit to stop): "<< endl;
while(getline(cin, temp)&& (temp!="quit"))
lists.insert(temp);
return lists;
}
*/

int main(void)
{

{

Useless one = Useless(10, 'x');

Useless two;
two = std::move(one);
Useless three(20, 'o');
Useless four(std::move(three));

Useless five(one + one);

}

/*
//Useless.h
{
Useless one(10, 'x');
one.ShowData();
Useless two = std::move(one + one);
two.ShowData();
Useless three, four;
three = one;
three.ShowData();
four = one + two;
four.ShowData();
four = std::move(two);
four.ShowData();
two.ShowData();
}


//ex9
{
//clock_t start =clock();
const long int size = 100000;
vector<int> ob1;
int i;
srand(time(0));
for(i=0; i< size; ++i)
{
ob1.push_back(rand()%10000);
}

//for(auto& x:ob1)
//cout << x << " ";
//cout << "\n";

vector<int> vi(ob1);
//for(auto& x:vi)
//cout << x << " ";
//cout << "\n";


list<int> li(vi.size());
copy(ob1.begin(), ob1.end(), li.begin());
ostream_iterator<int, char> out(cout, " ");
//copy(li.begin(), li.end(),out);
//for(auto it=li.begin(); it!=li.end(); ++it)
//cout << *it << " ";
//cout << "\n";
clock_t start_vi =clock();
sort(vi.begin(), vi.end());
clock_t end_vi = clock();
li.sort();
clock_t end_li = clock();
li.erase(li.begin(), li.end());
li.resize(ob1.size());
copy(ob1.begin(), ob1.end(), li.begin());
//copy(li.begin(), li.end(),out);
//cout << endl;
clock_t end_d = clock();
copy(li.begin(), li.end(), vi.begin());
//copy(vi.begin(), vi.end(),out);
//cout << endl;

sort(vi.begin(), vi.end());
//copy(vi.begin(), vi.end(),out);
//cout << endl;

copy(vi.begin(), vi.end(), li.begin());
//copy(li.begin(), li.end(),out);
//cout << endl;

clock_t end =clock();

cout <<"vector sort: " << (double)(end_vi-start_vi)/CLOCKS_PER_SEC << endl;
cout <<"list sort: " << (double)(end_li-end_vi)/CLOCKS_PER_SEC << endl;
cout <<"vector sort+ list storage: " << (double)(end-end_d)/CLOCKS_PER_SEC << endl;
}


//ex8
{
set<string> s1=guest();
set<string> s2=guest();
ostream_iterator<string, char> out(cout, ", ");
copy(s1.begin(), s1.end(), out);
cout << "\n";
copy(s2.begin(), s2.end(), out);
cout << "\n";
set<string> s3(s1);
s3.insert(s2.begin(), s2.end());
copy(s3.begin(), s3.end(), out);
cout << "\n";

}


//ex7
{
vector<int> winners;
winners = lotto(51, 6);
for(auto& x:winners)
cout << x << " ";
cout << "\n";
}


//ex5
{
long ar[6] = {5, 8, 7, 5, 4, 8};
cout << reduce(ar, 6) << endl;
string arr[4] = {"you", "love", "you", "me"};
cout << reduce(arr, 4) << endl;
}


//ex4
{
long ar[6] = {5, 8, 7, 5, 4, 8};
cout << reduce(ar, 6) << endl;
}

//ex3
{
vector<string> sen;
ifstream file;
file.open("new.txt");
if(file.is_open() == false)
{
std::cerr << "Failed to open word file; bye\n";
cin.get();
std::exit(EXIT_FAILURE);
}
string temp;
while(file >> temp)
sen.push_back(temp);
for_each(sen.begin(), sen.end(), show);
cout << endl;
}


//ex2
 {
                string str, temp;
                cout << "Enter the string(\"quit\" to stop): ";
                while((getline(cin, str))&& (str!="quit"))
                {
                     for(auto it=str.begin(); it!=str.end(); ++it)
                       {
                        if(isalpha(*it))
                          temp.push_back(tolower(*it));
                        }
                        bool alpha= HuiWen(temp);
                        cout << endl<< boolalpha << alpha << endl;
                        temp.clear();
                }
        }

	//ex1
	{
		string str;
		cout << "Enter the string(\"quit\" to stop): ";
		while((cin >> str)&& (str!="quit"))
		{
			bool alpha= HuiWen(str);
			cout << endl<< boolalpha << alpha << endl;
		}
	}


{
vector<int> foo, bar;
for(int i = 0; i < 5; ++i)
{
foo.push_back(i);
bar.push_back(i*10);
}

for(int& x: foo)
cout << " " << x;
cout << "\n";

for(int& x: bar)
cout <<" " << x;
cout << "\n";

//vector<int>::iterator it = foo.end();
//advance(it, -3);
//insert_iterator<vector<int> > insert(foo, it);
//copy(bar.begin(), bar.end(), insert);


//back_insert_iterator<vector<int> > insert(foo);
//copy(bar.begin(), bar.end(), insert);


deque<int> q(3, 10);
deque<int> ba(2, 5);
front_insert_iterator<deque<int> > insert(q);
copy(ba.begin(), ba.end(), insert);

for(int& x: q)
cout <<  " " <<x;
cout << "\n";


for(int& x: foo)
cout <<  " " <<x;
cout << "\n";

for(int& x: bar)
cout << " "<< x;
cout << "\n";
}
*/

return 0;
}
