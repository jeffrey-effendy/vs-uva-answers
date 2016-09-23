#include "C.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	Test *t = new Test("UVA12015");
	t->begin();
	vector<string> sites;
	string str;
	int T, r, max;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		sites.clear();
		max = -1;
		for (int j = 0; j < 10; j++)
		{
			cin >> str >> r;
			if (max < r)
			{
				max = r;
				sites.clear();
				sites.push_back(str);
			}
			else if (max == r)
			{
				sites.push_back(str);
			}
		}
		cout << "Case #" << i + 1 << ":" << endl;
		for (int j = 0; j < sites.size(); j++)
		{
			cout << sites[j] << endl;
		}
	}
	delete t;
	return 0;
}