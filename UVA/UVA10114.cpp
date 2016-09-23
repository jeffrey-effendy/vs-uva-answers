#include "C.h"
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA10114");
	t->begin();
	double rates[101];
	int duration, k;
	double down, loan;
	while (cin >> duration >> down >> loan >> k && duration >= 0)
	{
		int month;
		double rate;
		for (int i = 0; i < duration; i++)
		{
			rates[i] = -1;
		}
		for (int i = 0; i < k; i++)
		{
			cin >> month >> rate;
			rates[month] = rate;
		}
		int i;
		double balance = loan;
		double payment = loan / duration;
		double carPrice = loan + down;
		for (i = 0; i < duration; i++)
		{
			if (rates[i] < 0)
			{
				if (i == 0)
				{
					rates[i] = 0;
				}
				else
				{
					rates[i] = rates[i - 1];
				}
			}
			carPrice *= (1 - rates[i]);
			if (balance < carPrice)
			{
				break;
			}
			balance -= payment;	
		}
		cout << i;
		if (i == 1)
		{
			cout << " month" << endl;
		}
		else
		{
			cout << " months" << endl;
		}
	}

	delete t;
	return 0;
}