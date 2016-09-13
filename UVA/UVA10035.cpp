#include "C.h"
#include <iostream>
#include <string>

using namespace std;

int carry = 0;

int main()
{
	Test *t = new Test("UVA10035");
	t->begin();
	int nc;
	long long a, b;
	while (cin >> a >> b && (a != 0 || b != 0))
	{
		nc = 0;
		carry = 0;
		while ((a != 0 && b != 0) || carry)
		{
			if (a % 10 + b % 10 + carry > 9) carry = 1;
			else carry = 0;
			nc += carry;
			a /= 10;
			b /= 10;
		}
		if (nc == 0) cout << "No carry operation." << endl;
		else if (nc == 1) cout << "1 carry operation." << endl;
		else cout << nc << " carry operations." << endl;
	}
	delete t;
	return 0;
}