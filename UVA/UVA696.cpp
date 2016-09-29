#include "C.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA696");
	t->begin();
	int m, n;
	while (cin >> m >> n && !(m == 0 && n == 0))
	{
		if (m == 0 || n == 0)
		{
			cout << 0;
		}
		else if (m == 1 || n == 1)
		{
			cout << max(m, n);
		}
		else if (m == 2 || n == 2)
		{
			cout << ((ceil(max(m, n) / 4.0) - 1) * 2 + min(2, (max(m, n) - 1) % 4 + 1)) * 2;
		}
		else
		{
			cout << ceil((m * n) / 2.0);
		}
		cout << " knights may be placed on a " << m << " row " << n << " column board." << endl;
	}
	delete t;
	return 0;
}