#include "C.h"
#include <iostream>

using namespace std;

int mile(int n)
{
	return 10 * ((n / 30) + 1);
}

int juice(int n)
{
	return 15 * ((n / 60) + 1);
}

int main()
{
	Test *t = new Test("UVA12157");
	t->begin();
	int T, N, c;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int tM = 0, tJ = 0;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> c;
			tM += mile(c);
			tJ += juice(c);
		}
		cout << "Case " << i + 1 << ": ";
		if (tM < tJ)
		{
			cout << "Mile " << tM << endl;
		}
		else if (tJ < tM)
		{
			cout << "Juice " << tJ << endl;
		}
		else
		{
			cout << "Mile Juice " << tM << endl;
		}
	}
	delete t;
	return 0;
}