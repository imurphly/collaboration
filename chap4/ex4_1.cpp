#include <iostream>
#include <string>
#include <cstring>
#include <array>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::array;

struct CandyBar
{
	string bland;
	float weight;
	int calories;
};

struct pizza
{
	string bland;
	float diameter;
	float weight;
};

int main()
{

	{
		const int size = 20;
		char f_name[size];
		char l_name[size];
		char grade;
		int age;
		cout << "What is your first name? ";
		cin.getline(f_name, size);
		cout << "What is your last name? ";
		cin.getline(l_name, size);
		cout << "What letter grade do you deserve? ";
		cin >> grade;
		cout << "What is your age? ";
		cin >> age;
		cout << "Name: " << l_name << ", " << f_name << endl << "Grade: " << char(grade+1) << endl << "Age: " << age << endl;
	}

	{
		string name, dessert;
		int year;
		cout << "This year is: ";
		cin >> year;
		cin.get();
		cout << "Please tell me your name: ";
		getline(cin, name);
		cout << "And your favorate dessert is: ";
		getline(cin, dessert);
		cout << "I have some delicious " << dessert << " for you, " << name << endl;
	}


	{
		const int size = 20;
		char f_name[size];
		char l_name[size];
		cout << "Enter your first name? ";
		cin.getline(f_name, size);
		cout << "Enter your last name? ";
		cin.getline(l_name,size);
		char *name = new char[strlen(f_name) + 1];
		strcpy(name, f_name);
		strcat(name, ", ");
		strcat(name, l_name);
		cout << "Here's the information in a single string: " << name << endl;
		delete []name;
	}


	{
		string f_name, l_name, name;
		cout << "Enter your first name? ";
		getline(cin, f_name);
		cout << "Enter your last name? ";
		getline(cin, l_name);
		name = f_name + ", " + l_name;
		cout << "Here's the information in a single string: " << name << endl;
	}


	{
		CandyBar snack {"Mocha Munch", 2.3, 350};
		cout << "snack is made by " << snack.bland <<", weight " << snack.weight << "g, calories " << snack.calories << endl;
	}

	{
		CandyBar snack[3] = {{"Mocha Munch", 13.2, 30},{"Mocha Munch", 60.67, 350},{"Mocha Munch", 32.80, 35}};
		cout << "snack[0]: , made by "<< snack[0].bland <<", weight " << snack[0].weight << "g, calories " << snack[0].calories << endl;
		cout << "snack[1]: , made by "<< snack[1].bland <<", weight " << snack[1].weight << "g, calories " << snack[1].calories << endl;
		cout << "snack[2]: , made by "<< snack[2].bland <<", weight " << snack[2].weight << "g, calories " << snack[2].calories << endl;
	}

	{
		pizza p01;
		cout << "Please input p01's bland, diameter and weight:\n ";
		cin >> p01.bland >> p01.diameter >> p01.weight;
	}

	{
		pizza *p01 = new pizza;
		cout << "Please input p01's diameter, bland and weight:\n ";
		cin >> p01->diameter  >> p01->bland >> p01->weight;
	}

	{
		CandyBar *snack = new CandyBar[3];
		delete []snack;
	}


	{
		array<double, 3> score;
		cout << "Please input your three score: \n";
		cin >> score[0] >> score[1] >> score[2];
		double average = (score[0] + score[1] + score[2])/3;
		cout << "You input " << sizeof(score)/sizeof(double) << "data, and your average score is " << average << endl;
	}
	return 0;
}
