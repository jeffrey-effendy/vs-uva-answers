#include "C.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Test *t = new Test("UVA12289");
	t->begin();
	int T;
	string str;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> str;
		if (str.length() == 5)
		{
			cout << 3 << endl;
		}
		else
		{
			int oneFlag = 0;
			if (str[0] == 'o')
			{
				oneFlag++;
			}
			if (str[1] == 'n')
			{
				oneFlag++;
			}
			if (str[2] == 'e')
			{
				oneFlag++;
			}
			if (oneFlag >= 2)
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 2 << endl;
			}
		}
	}
	delete t;
	return 0;
}