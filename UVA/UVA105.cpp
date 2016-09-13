#include "C.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	Test *t = new Test("UVA105");
	t -> begin();
	int x[10000] = { 0 };
	int max = 0;
	int l, h, r;
	int ctr = 0;
	while (cin >> l >> h >> r)
	{
		for (int i = l; i < r; i++)
		{
			if (x[i] < h)
			{
				x[i] = h;
			}
		}
		if (r > max)
		{
			max = r;
		}
	}
	int currHeight = 0;
	bool first = true;
	for (int i = 0; i <= max; i++)
	{
		if (currHeight != x[i])
		{
			if (!first)
			{
				cout << " ";
			}
			cout << i << " " << x[i];
			currHeight = x[i];
			first = false;
		}
	}
	cout << endl;
	delete t;
	return 0;
}