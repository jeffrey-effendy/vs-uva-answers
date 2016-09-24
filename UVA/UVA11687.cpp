#include "C.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Test *t = new Test("UVA11687");
	t->begin();
	string x;
	while (cin >> x && x != "END")
	{
		int index = 0;
		string prevX = "";
		while (prevX != x)
		{
			prevX = x;
			x = to_string(x.size());
			index++;
		}
		cout << index << endl;
	}
	delete t;
	return 0;
}