#include "C.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	Test *t = new Test("UVA119");
	t->begin();
	bool first = true;
	int n;
	string name;
	while (cin >> n)
	{
		if (!first)
		{
			cout << endl;
		}
		map<string, int> bal;
		string names[11];
		for (int i = 0; i < n; i++)
		{
			cin >> name;
			names[i] = name;
			bal[name] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			string giver, receiver;
			int price, m;
			cin >> giver >> price >> m;
			if (m > 0)
			{
				bal[giver] -= (price / m) * m;
			}
			for (int j = 0; j < m; j++)
			{
				cin >> receiver;
				bal[receiver] += price / m;
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << names[i] << " " << bal[names[i]] << endl;
		}
		first = false;
	}
	delete t;
	return 0;
}