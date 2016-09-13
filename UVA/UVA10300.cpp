#include "C.h"
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA10300");
	t->begin();
	int n, f;
	long long a, b, c, sum;
	cin >> n;
	for (auto i = 0; i < n; i++)
	{
		sum = 0;
		cin >> f;
		for (auto j = 0; j < f; j++)
		{
			cin >> a >> b >> c;
			sum += a * c;
		}
		cout << sum << endl;
	}
	delete t;
	return 0;
}