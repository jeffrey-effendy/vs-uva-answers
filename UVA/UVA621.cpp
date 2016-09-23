#include "C.h"
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	Test *t = new Test("UVA621");
	t->begin();
	regex plus("1|4|78");
	regex minus("([[:digit:]]+)?35");
	regex star("9([[:digit:]]+)?4");
	string str;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> str;
		if (regex_match(str, plus))
		{
			cout << "+" << endl;
		}
		else if (regex_match(str, minus))
		{
			cout << "-" << endl;
		}
		else if (regex_match(str, star))
		{
			cout << "*" << endl;
		}
		else
		{
			cout << "?" << endl;
		}
	}
	delete t;
	return 0;
}