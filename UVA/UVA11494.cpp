#include "C.h"
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA11494");
	t->begin();
	int di, dj, ti, tj;
	while (cin >> di >> dj >> ti >> tj && !(di == 0 && dj == 0 && ti == 0 && ti == 0))
	{
		if (di == ti && dj == tj)
		{
			cout << 0 << endl;
		}
		else if (abs(di - ti) == abs(dj - tj) || di == ti || dj == tj)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 2 << endl;
		}
	}
	delete t;
	return 0;
}