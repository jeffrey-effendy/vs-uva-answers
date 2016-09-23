#include "C.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Test *t = new Test("UVA1124");
	t -> begin();
	string input;
	while (getline(cin, input))
	{
		cout << input << endl;
	}
	delete t;
	return 0;
}