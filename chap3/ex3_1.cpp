/*---------------------------------------------------
 * Date    : 2020-02-25
 * Author  : LiuYan
 * Function: finish the practices of chapter3
 *
 ----------------------------------------------------*/

#include <iostream>

typedef const int CINT;
using std::cout;
using std::cin;
using std::endl;

int main()
{

{
int height, foot, inch;
cout << "Please tell me your height in inch: __ inch\b\b\b\b\b\b\b";
cin >> height;
const int rate = 12;
foot = height/rate;
inch = height%rate;
cout << "You are " << foot << " foot, " << inch << " inch tall.\n";
}

{
int foot, inch;
double pound;
cout << "Please tell me your height and weight in foot, inch, and pound: \n";
cin >> foot >> inch >> pound;
double m, kg;
m = (foot*12 + inch)*0.0254;
kg= pound/2.2;
cout << "You are " << m << " miles tall, " << kg << " kg weight.\n";
}

{
int degree, minute, second;
double latitude;
cout << "Enter a latitude in degrees, minutes, and seconds:\n First, enter the degrees: ";
cin >> degree;
cout << "Next, enter the minutes of arcs: ";
cin >> minute;
cout << "Finally, enter the seconds of arcs: ";
cin >> second;
latitude = degree + minute/60.0 + second/60.0/60.0;
cout << degree << " degrees, " << minute << " minutes, " << second << " seconds = " << latitude << " degrees\n";
}

{
CINT dh = 24, hm = 60, ms = 60;
long int sec;
int day, hour, minute, second;
cout << "Enter the number of seconds: ";
cin >> sec;
day = sec/(ms*hm*dh);
hour = sec%(ms*hm*dh)/(ms*hm);
minute = sec%(ms*hm*dh)%(ms*hm)/(ms);
second = sec%(ms*hm*dh)%(ms*hm)%(ms);
cout << sec << "seconds = " << day << " days, " << hour << " hours, " << minute << " minutes, " << second << " seconds.\n";
}

{
long int USA, world;
cout << "Enter the world's population: ";
cin >> world;
cout << "Enter the population of USA: ";
cin >> USA;
double rate = double(USA)/double(world)*100.0;
cout << "The population of USA is " << rate << "\% of the world population.\n"; 
}

{
double mile, gallon, average;
cout << "How many miles you have drived: ";
cin >> mile;
cout << "How many oil you have used: ";
cin >> gallon;
average = mile/gallon;
cout << "You drived " << average << " mile every gallon\n";
}

{
double liter, europe;
cout << "You drive 100 kilometer need oil liter: ";
cin >> liter;
europe = 62.14*3.875/liter;
cout << "As european method, you used one gallon to drive miles of:  " << europe << endl;
}
return 0;
}
