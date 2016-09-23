#include "C.h"
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA10963");
	t->begin();
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		if (i != 0)
		{
			cout << endl;
		}
		int w, top, bot;
		int min = 9999, max = -1;
		cin >> w;
		for (int j = 0; j < w; j++)
		{
			cin >> top >> bot;
			if (min > top - bot)
			{
				min = top - bot;
			}
			if (max < top - bot)
			{
				max = top - bot;
			}
		}
		if (min == max)
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