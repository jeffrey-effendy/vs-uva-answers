#include "C.h"
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA11799");
	t->begin();
	int T, N, s;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int max = -1;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> s;
			if (max < s)
			{
				max = s;
			}
		}
		cout << "Case " << i + 1 << ": " << max << endl;
	}
	delete t;
	return 0;
}