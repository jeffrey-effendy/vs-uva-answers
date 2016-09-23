#include "C.h"
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA11764");
	t->begin();
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N;
		int prevH, H;
		int hi = 0, lo = 0;
		cin >> N;
		cin >> prevH;
		for (int j = 0; j < N - 1; j++)
		{
			cin >> H;
			if (H > prevH)
			{
				hi++;
			}
			else if (H < prevH)
			{
				lo++;
			}
			prevH = H;
		}
		cout << "Case " << i + 1 << ": " << hi << " " << lo << endl;
	}
	delete t;
	return 0;
}