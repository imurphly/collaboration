#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <array>
#include <iomanip>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::array;
using std::setw;
using std::ifstream;

const int strsize = 40;
const int bopsize = 5;
// Benevolent Order of Programmers name structure
struct bop {
char fullname[strsize]; // wordly name
char title[strsize]; // job title
char bopname[strsize]; // secret BOP name
int preference; // 0 = fullname, 1 = title, 2 = bopname
};
void showa(bop ar[], int n);
void showb(bop ar[], int n);
void showc(bop ar[], int n);
void showd(bop ar[], int n);

struct donate
{
string name;
double funds;
};

//倒着做题
int main()
{

{

string str;
                const int crit = 10000;
                int donater, count;
ifstream infile;
infile.open("donation.txt");
if(!infile.is_open())
{
cout << "Couldn't open the file donation.txt\n";
cout << "Program terminate.\n";
exit(EXIT_FAILURE);
}
 cout << "The programm aims to record the funds donated to \" upholding rights \". \n";
                cout << "Enter the numbers of donaters: ";
                infile >> donater;
                 getline(infile, str);
                cout << donater << endl;;
                donate * p_donate = new donate[donater];
                int i;
                for(i = 0; i < donater; ++i)
                {
cout << i+1 << "th donater's information. name= ";
getline(infile, p_donate[i].name);
cout << p_donate[i].name << endl;
cout << "funds= ";
infile >> p_donate[i].funds;
infile.get();
cout << p_donate[i].funds << endl;
}
infile.close();
                cout << "\n IMPORTTANT DONATERS: \n";
                for(i = 0; i< donater; ++i)
                {
                        if(p_donate[i].funds > 10000)
                        {
                                cout << p_donate[i].name << ", " << p_donate[i].funds << " yuan.\n";
                                ++count;
                        }

                }
             if(count == 0) 
              cout << "none\n";
             cout << "Patrons.\n";
            if(count == donater)
            cout << "none\n";
             else
              {for(i = 0; i< donater; ++i)
                {
                        if(p_donate[i].funds <= 10000)
                                cout << p_donate[i].name << ", " << p_donate[i].funds << " yuan.\n";
                }
              }
        }


/*
{
double ch;
const int size = 16;
char filename[size];
cout << "Enter the filename: \n";
cin.getline(filename, size);
ifstream infile;
infile.open(filename);
if(!infile.is_open())
{
cout << "Couldn't open the file " << filename << endl;
cout << "Program terminate.\n";
exit(EXIT_FAILURE);
}
do{
infile >> ch;
cout << ch << " ";}
while(infile.good());
cout << endl;
if(infile.eof())
cout << "end of the file reached.\n";
else if(infile.fail())
cout << "Program terminated by data mismatch.\n";
else
cout << "Program terminate by unknow reason.\n";
infile.close();
}


{
int vowels=0, consonants=0, others=0;
string word;
cout << "Enter words (q to quit): \n";
cin >> word;
while(word != "q")
 {
 if(isalpha(word[0]))
  {
  switch(word[0])
  {
 case 'a': ++vowels; break;
 case 'e': ++vowels; break;
 case 'i': ++vowels; break;
 case 'o': ++vowels; break;
 case 'u': ++vowels; break;
 default: ++consonants;break;
   }
  }
 else
 ++others;
cin >> word;
 }
cout << vowels << " words beginning with vowels.\n";
cout << consonants << " words beginning with consonants.\n";
cout << others << " others.\n";
}



	{
		const int crit = 10000;
		int donater, count;
		cout << "The programm aims to record the funds donated to \" upholding rights \". \n";
		cout << "Enter the numbers of donaters: ";
		cin >> donater;
                cin.get();
		donate * p_donate = new donate[donater];
		int i;
		for(i = 0; i < donater; ++i)
		{
cout << i+1 << "th donater's information. name= ";
getline(cin, p_donate[i].name);
cout << "funds= ";
cin >> p_donate[i].funds;
cin.get();
}
		cout << "\n IMPORTTANT DONATERS: \n";
		for(i = 0; i< donater; ++i)
		{
			if(p_donate[i].funds > 10000)
			{
				cout << p_donate[i].name << ", " << p_donate[i].funds << " yuan.\n";
				++count;
			}

		}
             if(count == 0) 
              cout << "none\n";
             cout << "Patrons.\n";
            if(count == donater)
            cout << "none\n";
             else
              {for(i = 0; i< donater; ++i)
                {
                        if(p_donate[i].funds <= 10000)
                                cout << p_donate[i].name << ", " << p_donate[i].funds << " yuan.\n";
                }
              }
	}


{
int salary;
double tax;
cout << "Enter your salary: ";
while(!(cin >> salary))
{
cout << "error.\n";
exit(EXIT_FAILURE);
}
if(salary < 0)
{
cout << "error.\n";
exit(EXIT_FAILURE);
}
else if((salary > 0)&&(salary <= 5000))
tax = 0.0;
else if((salary > 5000)&&(salary <= 15000))
tax = (salary - 5000)*0.1;
else if((salary > 15000)&&(salary <= 35000))
tax = 10000*0.1 + (salary - 15000)*0.15;
else
tax = 10000*0.1 + 20000*0.15 + (salary - 35000)*0.2;
cout << "Your income tax: " << tax << " tvarps.\n";
}


{
bop team[bopsize] = {
{"Wimp Macho", "Senior Programmer", "UNIXMAN", 0},
{"Raki Rhodes", "Junior Programmer", "ESATA", 1},
{"Celia Laiter", "Junior Analyst", "MIPS", 2},
{"Hoppy Hipman", "Analyst Trainee", "THUNDERBOLT", 1},
{"Pat Hand", "Junior Programmer", "LOOPY" ,2 } };
cout << "Benevolent Order of Programmers Report\n";
cout << "a. display by name b. display by title\n"
<< "c. display by bopname d. display by preference\n"
<< "q. quit\n";
cout << "Enter your choice: ";
char choice;
cin >> choice;
while (choice != 'q')
{
switch(choice)
{
case 'a' : showa(team, bopsize); break;
case 'b' : showb(team, bopsize); break;
case 'c' : showc(team, bopsize); break;
case 'd' : showd(team, bopsize); break;
default : cout << "Enter only a, b, c, d, or q.\n";
}
cout << """Next choice: """;
cin >> choice;
}
cout << "Bye!\n";
}


	
	   {
	   cout << "Please enter one of the following choices: \n";
	   cout << "a) carnivore" << setw(10) << "p) pianist\n";
	   cout << "t) tree     " << setw(10) << "g) game\n";
	   char ch;
	   cin.get(ch);
	   cin.get();
	   cout << ch;
	   while((ch != 'a')&&(ch !='p')&&(ch != 't')&&(ch != 'g'))
	   {cout << "Please enter a c, p, t, or g: ";
	   cin >> ch;
	   }
	   switch(ch)
	   {
	   case 'a': cout << "A maple is a carnivore.\n";break;
	   case 'p': cout << "A maple is a pianist.\n";break;
	   case 't': cout << "A maple is a tree.\n";break;
	   case 'g': cout << "A maple is a game.\n";break;
	   default: ;
	   }
	   }


	   {
	   const int size = 10;
	   double donation[size];
	   int i = 0;
	   while((i < size)&&(cin >> donation[i]))
	   { 
	   if(++i < size)
	   cin >> donation[i];
	   else
	   break;
	   }
	   double total = 0.0;
	   for(int j = 0; j < i; ++j)
	   {
	   total +=donation[j];
	   }
	   double average = total/i;
	   int count = 0;
	   for(int j = 0; j < i; ++j)
	   {if(donation[j] > average)
	   ++count;}
	   cout << average << " = average of numbers, and have " << count << " is large than average.\n";
	   }


	   {
	   char ch;
	   while(cin.get(ch))
	   {
	   if(ch == '@')
	   break;
	   else if(isdigit(ch))
	   ;
	   else
	   {
	   if(islower(ch))
	   ch = toupper(ch);
	   else if(isupper(ch))
	   ch = tolower(ch);
	   cout << ch;
	   }
	   }
	   cout << endl;
	   }
	 */

	return 0;
}


void showa(bop ar[], int n)
{
using namespace std;
for(int i = 0; i < n; i++)
cout << ar[i].fullname << "\n";
}
void showb(bop ar[], int n)
{
using namespace std;
for(int i = 0; i < n; i++)
cout << ar[i].title << "\n";
}
void showc(bop ar[], int n)
{
using namespace std;
for(int i = 0; i < n; i++)
cout << ar[i].bopname << "\n";
}
void showd(bop ar[], int n)
{
using namespace std;
for(int i = 0; i < n; i++)
if (ar[i].preference == 0)
cout << ar[i].fullname << "\n";
else if (ar[i].preference == 1)
cout << ar[i].title << "\n";
else if (ar[i].preference == 2)
cout << ar[i].bopname << "\n";
else
cout << "oops\n";
}
