#include "C.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Test *t = new Test("UVA12403");
	t->begin();
	int T;
	string str;
	int a;
	int bal = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> str;
		if (str == "donate")
		{
			cin >> a;
			bal += a;
		}
		else
		{
			cout << bal << endl;
		}
	}
	delete t;
	return 0;
}