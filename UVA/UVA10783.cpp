#include "C.h"
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA10783");
	t->begin();
	int n, a, b, sum;
	cin >> n;
	for (auto i = 0; i < n; i++)
	{
		sum = 0;
		cin >> a >> b;
		a = 2 * (a / 2) + 1;
		b = 2 * ((b - 1) / 2) + 1;
		if (b >= a)
			sum = ((b + 1)*(b + 1) - (a - 1)*(a - 1)) / 4;
		cout << "Case " << i+1 << ": " << sum << endl;
	}
	delete t;
	return 0;
}