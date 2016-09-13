#include "C.h"
#include <iostream>
#include <string>

using namespace std;

int bit = 0;

void findAndReplace(string *str)
{
	for (auto i = (*str).begin(); i != (*str).end(); ++i)
	{
		if (*i == '"')
		{
			if (!bit)
				cout << "``";
			else
				cout << "''";
			bit = !bit;
		}
		else
			cout << (*i);
	}
	cout << endl;
}

int main()
{
	Test *t = new Test("UVA272");
	t->begin();
	string str;
	while (getline(cin, str)) 
	{
		findAndReplace(&str);
	}
	delete t;
	return 0;
}