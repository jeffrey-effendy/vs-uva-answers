#include "C.h"
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA100");
	t->begin();
	int i, j, count, max, n;
	while (cin >> i >> j)
	{
		max = 0;
		cout << i << " " << j << " ";
		if (i > j)
		{
			int temp = i;
			i = j;
			j = temp;
		}
		for (int k = i; k <= j; k++)
		{
			count = 1;
			n = k;
			while (n != 1)
			{
				n = n % 2 ? n * 3 + 1 : n / 2;
				count++;
			}
			if (max < count)
				max = count;
		}
		cout << max << endl;
	}
	delete t;
	return 0;
}