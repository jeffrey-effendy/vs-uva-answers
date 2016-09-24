#include "C.h"
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA11683");
	t->begin();
	int W, H;
	while (cin >> H >> W && H != 0)
	{
		int prevHeight = 0;
		int res = 0;
		for (int i = 0; i < W; i++)
		{
			int x;
			cin >> x;
			int height = H - x;
			res += max(0, height - prevHeight);
			prevHeight = height;			
		}
		cout << res << endl;
	}
	delete t;
	return 0;
}