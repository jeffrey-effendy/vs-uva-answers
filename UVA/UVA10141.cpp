#include "C.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Test *t = new Test("UVA10141");
	t->begin();
	int n, p, index = 1;
	string dummy;
	while (cin >> n >> p && !(n == 0 && p == 0))
	{
		cin.ignore(100, '\n');
		for (int i = 0; i < n; i++)
		{
			getline(cin, dummy);
		}
		string proposal = "";
		int minPrice = 100000000;
		int maxCompliance = -1;
		for (int i = 0; i < p; i++)
		{
			string prop;
			float price;
			int nreq;
			getline(cin, prop);
			cin >> price >> nreq;
			cin.ignore(100, '\n');
			for (int k = 0; k < nreq; k++)
			{
				getline(cin, dummy);
			}
			if (maxCompliance < nreq)
			{
				maxCompliance = nreq;
				minPrice = price;
				proposal = prop;
			}
			else if (maxCompliance == nreq && minPrice > price)
			{
				minPrice = price;
				proposal = prop;
			}
		}
		if (index != 1)
		{
			cout << endl;
		}
		cout << "RFP #" << index++ << endl;
		cout << proposal << endl;
	}
	delete t;
	return 0;
}