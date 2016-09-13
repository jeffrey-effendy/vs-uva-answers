#include "C.h"
#include <iostream>
#include <string>

using namespace std;

void decode(string *str)
{
	for (auto i = (*str).begin(); i != (*str).end(); ++i)
	{
		cout << (char)((*i) - 7);
	}
	cout << endl;
}

int main()
{
	Test *t = new Test("UVA458");
	t->begin();
	string str;
	while (getline(cin, str))
	{
		decode(&str);
	}
	delete t;
	return 0;
}