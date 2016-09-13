 #include "C.h"
#include <cmath>
#include <iostream>

using namespace std;

int jolly[3000];

int main()
{
	Test *t = new Test("UVA10038");
	t->begin();
	int n, a, b, diff;
	bool bit = true;
	while (cin >> n)
	{
		bit = true;
		fill(jolly, jolly + 3000, 0);
		cin >> a;
		for (auto i = 1; i < n; i++)
		{
			cin >> b;
			diff = abs(b - a);
			if (diff == 0 || diff >= n)
				bit = false;
			else if (jolly[diff]++ == 1)
				bit = false;
			a = b;
		}
		if (bit)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
	}
	delete t;
	return 0;
}