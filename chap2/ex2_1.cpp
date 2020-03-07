/*---------------------------------------------------
 * Date    : 2020-02-25
 * Author  : LiuYan
 * Function: print my name and address.
 *
 ----------------------------------------------------*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void MyFunct_1();
void MyFunct_2();
double CelsiusToFahrenheit(double c);
double LightYear(double c);
void PrintTime(int hour, int minute);

int main()
{
	{
		cout << "LiuYan, QingDao City\n\n";
	}

        {
       const int rate = 220;
       int distance;
       cout << "Please input the distance: ";
        cin >> distance;
       int mile = rate*distance;
       cout << "It equals to " << mile << " miles\n\n"; 
           }
 
{
MyFunct_1();
MyFunct_1();
MyFunct_2();
MyFunct_2();

cout << endl;
}

{
    const int rate = 12;
       int age;
       cout << "Enter your age: ";
        cin >> age;
       int mile = rate*age;
       cout << "It equals to " << mile << " months\n\n";

}

{
double cel;
cout << "PLease enter a Celsius value: ";
cin >> cel;
cout << cel << " degree Celsuis is "<< CelsiusToFahrenheit(cel) << " degree Fahrenheit\n\n";
}

{
double ly;
cout << "Enter the number of light years: ";
cin >> ly;
cout << ly << "light years = " << LightYear(ly) << " astronomical units\n\n";
}

{
int hour, minute;
cout << "Enter the number of hours: ";
cin >> hour;
cout << "Enter the number of minutes: ";
cin >> minute;
PrintTime(hour, minute);
}
	return 0;
}

void MyFunct_1()
{
cout << "Three blind mice" << endl;
}

void MyFunct_2()
{
cout << "See how they run" << endl;
}

double CelsiusToFahrenheit(double c)
{
double f = 1.8*c + 32.0;
return f;
}

double LightYear(double c)
{
double f = 63240*c;
return f;
}

void PrintTime(int hour, int minute)
{
cout << "Time: " << hour << ":" << minute << endl;
}
