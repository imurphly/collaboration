#include "sales.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

namespace SALES
{
	void setSales(Sales& s, const double ar[], int n)
	{
		if(n < QUARTERS)
		{
			for(int i=0; i<n ; ++i)
				s.sales[i] = ar[i];
			for(int i=n; i<QUARTERS;++i)
				s.sales[i] = 0;
		}
		else
		{
			for(int i=0; i< QUARTERS; ++i)
				s.sales[i] = ar[i];
		}

		//double max = min = total =s.sales[0];
		double temp, max, min, total;
max = min = total =s.sales[0];
		for(int i=1; i< QUARTERS; ++i)
		{
			temp = s.sales[i];
			max = (temp >max?temp: max);
			min = (temp < min? temp: min);
			total += temp;
		}
		s.average = total/QUARTERS;
		s.max = max;
		s.min = min;
	}

	void setSales(Sales& s)
	{
		cout << "Enter double items: ";
                cin >> s.sales[0];
		//double max = min = total =s.sales[0];
		double temp, max, min, total;
max = min = total =s.sales[0];
		for(int i=1; i< QUARTERS; ++i)
		{
			cin >> s.sales[i];
			temp = s.sales[i];
			max = (temp >max?temp: max);
			min = (temp < min? temp: min);
			total += temp;
		}
		s.average = total/QUARTERS;
		s.max = max;
		s.min = min;
	}

	void showSales(const Sales& s)
	{
		for(int i=0; i< QUARTERS; ++i)
		{cout << i << "th item: " << s.sales[i] << endl;}
		cout << "average: " << s.average << endl;
		cout << "max: " << s.max << endl;
		cout << "min: " << s.min << endl;
	}

}
