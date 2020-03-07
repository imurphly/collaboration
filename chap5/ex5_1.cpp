#include <iostream>
#include <array>
#include <string>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::array;
using std::string;

struct car
{
	string manufacture;
	int year;
};

int main()
{
/*
	
	   {
	   cout << "Enter two integer, I'will compute the sum of all numbers between them: \n";
	   int num1, num2, sum = 0;
	   cin >> num1 >> num2;
	   for(int i = num1; i <= num2; ++i)
	   sum += i;
	   cout << "The sum is " << sum << endl;
	   }

	   {
	   const int size = 101;
	   array<long double, size> fact;
	   fact[1] = fact[0] = 1.0;
	   for(int i = 2; i < size; ++i)
	   fact[i] = i*fact[i-1];
	   cout << "100! = " << fact[size -1] << endl;
	   }


	   {
	   int num, sum;
	   cout << "Please input a number, enter '0' to quit: \n";
	   cin >> num;
	   sum = num;
	   cout << "now, sum is " << sum << endl;
	   while(num != 0)
	   {
	   cin >> num;
	   sum += num;
	   cout << "now, sum is " << sum << endl;
	   }
	   }

	   {
	   int count = 0;
	   int daphne, cleo;
	   daphne = cleo = 100;
	   do
	   {
	   daphne += 10;
	   cleo *= 1.05;
	   ++count;
	   }
	   while(daphne >= cleo);
	   cout << "At " << count << "th year, daphne = " << daphne << "$, cleo = " << cleo << "$\n";
	   }

	   {
	   string str[12] {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	   int num[12];
	   int i, sum=0;
	   cout << "Enter the number of sells in 12 months: \n";
	   for(i = 0; i < 12; ++i)
	   {
	   cout << str[i] << ": ";
	   cin >> num[i];
	   sum += num[i];
	   }
	   cout << "the sum is " << sum << endl;
	   }

	   {
	   const int year = 3;
	   string str[12] {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	   int num[year][12];
	   int i,j, sum=0;
	   for(j = 0; j < 3; ++j)
	   {

	   cout << j <<  "th year, enter the number of sells in 12 months: \n";
	for(i = 0; i < 12; ++i)
	{
		cout << str[i] << ": ";
		cin >> num[j][i];
		sum += num[j][i];
	}
}
cout << "the sum is " << sum << endl;
}

{
	cout << "How many cars you have? \n";
	int num, i;
	cin >> num;
	cin.get();
	car *cars = new car[num];
	for(i = 0; i < num; ++i)
	{
		cout << "Car #" << i+1 << ": \n Please enter the make: ";
		getline(cin, cars[i].manufacture);
		cout << "Please enter the year made: ";
		cin >> cars[i].year;
		cin.get();
	} 
}
*/

{
	// 8th
const int STR_LIM = 50;

char word[STR_LIM];
int count = 0;
cout << "Enter words (to stop, type the word done):\n";
while (cin >> word && strcmp("done", word))
++count;
cout << "You entered a total of " << count << " words.\n";
/*
while (cin.get() != '\n')
continue;
cin.get();
*/

}

{
string word;
int count = 0;
cout << "Enter words (to stop, type the word done):\n";
while (cin >> word && (word != "done"))
++count;
cout << "You entered a total of " << count << " words.\n";
/*
while (cin.get() != '\n')
continue;
cin.get();
*/

}

{
	int row;
	cout << "Enter number of rows: ";
        cin.get();
	cin >> row;
	int i, j;
	for(i = 1; i <=row; ++i)
	{
		for(j = 1; j <= row-i; ++j)
		{
                cout << ". ";
		}
                for(j = 1; j <= i; ++j)
                {cout << "* ";}
          cout << endl;
	}
}

return 0;
}
