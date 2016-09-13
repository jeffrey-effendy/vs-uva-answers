#include "C.h"
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA299");
	t->begin();
	bool bubble;
	int n, c, swap;
	int car[51];
	cin >> n;
	for (auto i = 0; i < n; i++)
	{
		swap = 0;
		bubble = true;
		cin >> c;
		for (auto j = 0; j < c; j++) cin >> car[j];
		while(bubble)
		{
			bubble = false;
			for (auto j = 0; j < c-1; j++)
				if (car[j] > car[j + 1])
				{
					int temp = car[j];
					car[j] = car[j + 1];
					car[j + 1] = temp;
					bubble = true;
					swap++;
				}
		}
		cout << "Optimal train swapping takes " << swap << " swaps." << endl;
	}
	delete t;
	return 0;
}