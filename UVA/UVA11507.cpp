#include "C.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Test *t = new Test("UVA11507");
	t->begin();
	int T;
	while (cin >> T && T != 0)
	{
		string str;
		string curr = "+x";
		for (int i = 0; i < T - 1; i++)
		{
			cin >> str;
			if (str == "No")
			{
				continue;
			}
			if (curr == "+x")
			{
				curr = str;
			}
			else if (curr == "-x")
			{
				curr = (str[0] == '+' ? "-" : "+") + str.substr(1, 1);
			}
			else if ((curr == "+y" || curr == "-y") && str[1] == 'y')
			{
				if (str[0] == curr[0])
				{
					curr = "-x";
				}
				else
				{
					curr = "+x";
				}
			}
			else if ((curr == "+z" || curr == "-z") && str[1] == 'z')
			{
				if (str[0] == curr[0])
				{
					curr = "-x";
				}
				else
				{
					curr = "+x";
				}
			}
		}
		cout << curr << endl;
	}
	delete t;
	return 0;
}