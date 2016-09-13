#include "C.h"
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA10055");
	t->begin();
	long long i, j;
	while (cin >> i >> j)
	{
		if (i < j)
			cout << j - i << endl;
		else
			cout << i - j << endl;
	}
	delete t;
	return 0;
}