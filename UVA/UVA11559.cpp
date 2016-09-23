#include "C.h"
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA11559");
	t->begin();
	int P, B, H, W;
	while (cin >> P >> B >> H >> W)
	{
		int priceW = 5000001;
		for (int i = 0; i < H; i++)
		{
			int price;
			cin >> price;
			for (int j = 0; j < W; j++)
			{
				int nBed;
				cin >> nBed;
				if (nBed >= P && priceW > price)
				{
					priceW = price;
				}
			}
		}
		if (priceW * P <= B)
		{
			cout << priceW * P << endl;
		}
		else
		{
			cout << "stay home" << endl;
		}
	}
	delete t;
	return 0;
}