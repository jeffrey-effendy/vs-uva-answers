#include "C.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Test *t = new Test("UVA12577");
	t->begin();
	int i = 0;
	string str;
	while (cin >> str && str != "*")
	{
		i++;
		cout << "Case " << i << ": ";
		if (str == "Hajj")
		{
			cout << "Hajj-e-Akbar" << endl;
		}
		else
		{
			cout << "Hajj-e-Asghar" << endl;
		}
	}
	delete t;
	return 0;
}