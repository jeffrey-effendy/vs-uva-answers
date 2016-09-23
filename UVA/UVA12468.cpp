#include "C.h"
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA12468");
	t->begin();
	int from, to;
	while (cin >> from >> to && !(from == -1 && to == -1))
	{
		int n = abs(to - from);
		cout << (n < 100 - n ? n : 100 - n) << endl;
	}
	delete t;
	return 0;
}