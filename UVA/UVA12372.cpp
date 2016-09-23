#include "C.h"
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA12372");
	t->begin();
	int T;
	int l, w, h;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> l >> w >> h;
		cout << "Case " << i + 1 << ": ";
		if (l > 20 || w > 20 || h > 20)
		{
			cout << "bad" << endl;
		}
		else
		{
			cout << "good" << endl;
		}
	}
	delete t;
	return 0;
}