#include "C.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Test *t = new Test("UVA10324");
	t->begin();
	string str;
	int index = 1;
	int n, i, j;
	while (cin >> str)
	{
		cout << "Case " << index++ << ":" << endl;
		cin >> n;
		for (int k = 0; k < n; k++)
		{
			cin >> i >> j;
			int min = i < j ? i : j;
			int max = i > j ? i : j;
			int counter = 0;
			for (int l = min; l <= max; l++)
			{
				counter += str[l] - 48;
			}
			if (counter == max - min + 1 || counter == 0)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
	}
	delete t;
	return 0;
}