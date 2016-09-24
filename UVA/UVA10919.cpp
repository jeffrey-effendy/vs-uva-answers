#include "C.h"
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA10919");
	t->begin();
	int k, m;
	bool taken[10001];
	while (cin >> k >> m && k != 0)
	{
		bool pass = true;
		for (int i = 0; i < 10000; i++)
		{
			taken[i] = false;
		}
		for (int i = 0; i < k; i++)
		{
			int cat;
			cin >> cat;
			taken[cat] = true;
		}
		for (int i = 0; i < m; i++)
		{
			int fulfilled = 0;
			int r, c;
			cin >> r >> c;
			for (int j = 0; j < r; j++)
			{
				int cat;
				cin >> cat;
				if (taken[cat])
				{
					fulfilled++;
				}
			}
			if (fulfilled < c)
			{
				pass = false;
			}
		}
		if (pass)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
	delete t;
	return 0;
}