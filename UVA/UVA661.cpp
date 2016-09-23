#include "C.h"
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA661");
	t->begin();
	bool blown;
	int n, m, c;
	int max, currC, seq = 1;
	int devices[21];
	while (cin >> n >> m >> c && !(n == 0 && m == 0 && c == 0))
	{
		blown = false;
		currC = 0;
		max = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> devices[i];
		}
		for (int i = 0; i < m; i++)
		{
			int a;
			cin >> a;
			currC += devices[a - 1];
			devices[a - 1] *= -1;
			if (max < currC)
			{
				max = currC;
			}
			if (currC > c)
			{
				blown = true;
			}
		}
		cout << "Sequence " << seq++ << endl;
		if (blown)
		{
			cout << "Fuse was blown." << endl;
		}
		else
		{
			cout << "Fuse was not blown." << endl;
			cout << "Maximal power consumption was " << max << " amperes." << endl;
		}
		cout << endl;
	}
	delete t;
	return 0;
}