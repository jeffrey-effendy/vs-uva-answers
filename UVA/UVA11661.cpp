#include "C.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Test *t = new Test("UVA11661");
	t->begin();
	int d;
	while (cin >> d && d != 0)
	{
		string road;
		cin >> road;
		int dpos = 9999999, rpos = 99999999;
		int dist = 9999999;
		for (int i = 0; i < d; i++)
		{
			if (road[i] == 'Z')
			{
				dist = 0;
				break;
			}
			else if (road[i] == 'D')
			{
				dpos = i;
				if (dist > abs(dpos - rpos))
				{
					dist = abs(dpos - rpos);
				}
			}
			else if (road[i] == 'R')
			{
				rpos = i;
				if (dist > abs(dpos - rpos))
				{
					dist = abs(dpos - rpos);
				}
			}
		}
		cout << dist << endl;
	}
	delete t;
	return 0;
}