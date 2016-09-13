#include "C.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Test *t = new Test("UVA102");
	t->begin();
	int b[3];
	int g[3];
	int c[3];
	while (cin >> b[0] >> g[0] >> c[0] >> b[1] >> g[1] >> c[1] >> b[2] >> g[2] >> c[2])
	{
		int max = b[0] + c[1] + g[2];
		int sum = max + b[1] + b[2] + c[0] + c[2] + g[0] + g[1];
		string str = "BCG";

		if (max < b[0] + g[1] + c[2])
		{
			str = "BGC";
			max = b[0] + g[1] + c[2];
		}
		if (max < c[0] + b[1] + g[2])
		{
			str = "CBG";
			max = c[0] + b[1] + g[2];
		}
		if (max < c[0] + g[1] + b[2])
		{
			str = "CGB";
			max = c[0] + g[1] + b[2];
		}
		if (max < g[0] + b[1] + c[2])
		{
			str = "GBC";
			max = g[0] + b[1] + c[2];
		}
		if (max < g[0] + c[1] + b[2])
		{
			str = "GCB";
			max = g[0] + c[1] + b[2];
		}
		cout << str << " " << sum - max << endl;
	}
	delete t;
	return 0;
}