/*---------------------------------------------------
 * Date    : 2020-03-03
 * Author  : LiuYan
 * Function: Practice in chapter 7th
 *
 *----------------------------------------------------*/

#include <iostream>
#include <string>
#include <cstring>


using std::cout;
using std::cin;
using std::endl;
using std::string;

struct box
{
char maker[40];
float height;
float width;
float length;
float volume;
};

const int slen = 30;
struct student
{
char fullname[slen];
char hobby[slen];
int ooplevel;
};

double HarmonicMean(const double a, const double b);
//void ShowArray(const double arr[], int n);
//int FillArray(double arr[], int limits);
double MeanValue(const double arr[], int n);
void ShowBox(box b);
void ShowBox(box *b);
long double probability(unsigned numbers, unsigned picks);
long int factorial(int n);
void ReverseArray(double arr[], int n);
//void ReValue(double r, double arr[], int n);
double* FillArray(double arr[], int limits);
void ShowArray(const double arr[], double * end);
void ReValue(double r, double arr[], double * end);

const char *season[4] {"Spring", "Summer", "Fall", "Winter"};
void FillExpend(double arr[], int n);
void ShowExpend(double arr[], int n);

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student *ps);
void display3(const student pa[], int n);
double calculate(double a, double b, double (*add)(double, double));
double add(double a, double b);
double multiple(double a, double b);

//倒着做
int main()
{

{
double result;
result = calculate(3, 4, multiple);
cout << "result: " << result << endl;
double (*type_1[2])(double , double) = {add, multiple};
for(int i =0; i< 2; ++i)
{cout << calculate(3,4,type_1[i]) << endl;}
}

/*
{
cout << "Enter class size: ";
int class_size;
cin >> class_size;
while((cin.get()!='\n'))
continue;
student *ptr = new student[class_size];
int entry = getinfo(ptr, class_size);
for(int i = 0; i < entry; ++i)
{
display1(ptr[i]);
display2(&ptr[i]);
}
display3(ptr, entry);
delete []ptr;
cout << "Done.\n";
}

{
double arr[4];
FillExpend(arr, 4);
ShowExpend(arr, 4);
}


{
double factor;
const int max = 5;
double arr[max];
double * end= FillArray(arr, max);
ShowArray(arr, end);
cout << "Enter revaluation factor: ";
while(!(cin >> factor))
{
cin.clear();
while(cin.get() != '\n')
continue;
cout << "Please input a  double factor: ";
}
ReValue(factor, arr, end);
ShowArray(arr, end);
cout << "Done!\n";
}


{
const int max = 5;
double arr[max];
int size = FillArray(arr, max);
ShowArray(arr, size);
ReverseArray(arr, size);
ShowArray(arr, size);
ReverseArray(arr+1, size-2);
ShowArray(arr, size);
}

{
cout << "4! = "  << factorial(4) << endl;
}


{
using namespace std;
double total, choices;
double mtotal;
double probability1, probability2;
cout << "Enter total number of game card choices and\n number of picks allowed for the field:\n";
while ((cin >> total >> choices) && choices <= total)
{
cout << "Enter total number of game card choices for the mega number:\n";
if (!(cin >> mtotal))
break;
cout << "The chances of getting all " << choices << " picks is one in"
<< (probability1 = probability(total, choices) ) << ".\n";
cout << "The chances of getting the megaspot is one in "
<< (probability2 = probability(mtotal, 1) ) << ".\n";
cout << "You have one chance in ";
cout << probability1 * probability2; // compute the probability
cout << " of winning.\n";
cout << "Next set of numbers (q to quit): ";
}
cout << "bye\n";
}


{
box b{"Liu Yan", 4.0, 5.0,6.0,};
box *pb = &b;
ShowBox(pb);
}

{
const int max = 10;
double arr[max];
int size = FillArray(arr, max);
ShowArray(arr, size);
cout << "Mean value: " << MeanValue(arr, size) << endl;
}

{
double a, b, mean;
do
{
cout << "Enter two double(one of them=0 to quit): \n";
cin >> a >> b;
mean = HarmonicMean(a, b);
cout << "The Harmonic mean value of a and b is " << mean << endl;
}
while((a != 0)&&(b != 0));
}
*/

return 0;
}

double HarmonicMean(const double a, const double b)
{
return 2*a*b/(a + b);
}

/*
void ShowArray(const double arr[], int n)
{
int i;
for(i = 0; i < n; ++i)
 {
cout << "Property #" << (i+1) << ": $";
cout << arr[i] << ", " << endl;
 }
}


int FillArray(double arr[], int limits)
{
int count=0, i=0;
while((i < limits))
 {
cout << "Property #" << i+1 << ": ";
while(!(cin >> arr[i]))
 {
cin.clear();
while(cin.get() != '\n')
continue;
cout << "Please Enter a double number: ";
 }
if(arr[i] > 0)
{++count;
 ++i;}
else if(arr[i] <= 0)
break;
 }
return count;
}
*/

double* FillArray(double arr[], int limits)
{
int count=0, i=0;
while((i < limits))
 {
cout << "Property #" << i+1 << ": ";
while(!(cin >> arr[i]))
 {
cin.clear();
while(cin.get() != '\n')
continue;
cout << "Please Enter a double number: ";
 }
if(arr[i] > 0)
{++count;
 ++i;}
else if(arr[i] <= 0)
break;
 }
return arr+count;
}

void ShowArray(const double arr[], double * end)
{
for(const double * pt = arr; pt != end; ++pt)
 {
cout << "Property #: $";
cout << *pt << ", " << endl;
 }
}

void ReValue(double r, double arr[], double * end)
{
for(double * pt = arr; pt != end; ++pt)
 *pt *= r;
}

/*
void ReValue(double r, double arr[], int n)
{
for(int i = 0; i < n; ++i)
    arr[i] *= r;
}
*/


double MeanValue(const double arr[], int n)
{
double Total = 0.0;
const double *pt;
for(pt = arr; pt != (arr + n); ++pt)
{
Total += *pt;
}
return Total/n;
}

void ReverseArray(double arr[], int n)
{
int i;
double temp;
for(i = 0; i < n/2; ++i)
{
temp = arr[i];
arr[i] = arr[n-1-i];
arr[n-1-i] = temp;
}
}

void ShowBox(box b)
{
cout << "maker: " << b.maker << endl;
cout << "height: " << b.height << endl;
cout << "width: " << b.width << endl;
cout << "length: " << b.length << endl;
cout << "volume: " << b.volume << endl;
}

void ShowBox(box *b)
{
cout << "maker: " << b->maker << endl;
cout << "height: " << b->height << endl;
cout << "width: " << b->width << endl;
cout << "length: " << b->length << endl;
b->volume = (b->height)*(b->width)*(b->length);
cout << "volume: " << b->volume << endl;
}

long double probability(unsigned numbers, unsigned picks)
{
long double result = 1.0; // here come some local variables
long double n;
unsigned p;
for (n = numbers, p = picks; p > 0; n--, p--)
result = result * n / p ;
return result;
}

long int factorial(int n)
{
if((n == 0)||(n == 1)) 
return 1;
else if(n > 1)
return n*factorial(n-1);
}

void FillExpend(double arr[], int n)
{
int i;
for(i = 0; i < n; ++i)
 {
cout << season[i] << ":$ ";
cin >> arr[i];
 }

}

void ShowExpend(double arr[], int n)
{
int i;
double total = 0.0;
for(i = 0; i < n; ++i)
 {
cout << season[i] << ":$ " << arr[i] << ", " << endl;
total +=arr[i];
 }
cout << "Total expend: " << total << "$.\n";
}


int getinfo(student pa[], int n)
{
int count=0, i=0;
while(i < n)
 {
cout << "student #" << i+1 << ": ";
cin.getline(pa[i].fullname, slen);
if(pa[i].fullname[0] == '\0')
break;
cout << "hobby: ";
cin.getline(pa[i].hobby, slen);
cout << "ooplevel: ";
cin >> pa[i].ooplevel;
cin.get();
++count;
 ++i;
 }
return count;
}

void display1(student st)
{
cout << "name: " << st.fullname << "\n hobby: " << st.hobby << "\n ooplevel: " << st.ooplevel << endl;
}

void display2(const student *ps)
{
cout << "name: " << ps->fullname << "\n hobby: " << ps->hobby << "\n ooplevel: " << ps->ooplevel << endl;
}

void display3(const student pa[], int n)
{
int i;
for(i = 0; i < n; ++i)
{
cout << "name: " << (pa+i)->fullname << "\n hobby: " << (pa+i)->hobby << "\n ooplevel: " << (pa+i)->ooplevel << endl;
}
}

double add(double a, double b)
{return a+b;}

double calculate(double a, double b, double (*add)(double , double ))
{
return add(a, b);
}

double multiple(double a, double b)
{
return a*b;
}
