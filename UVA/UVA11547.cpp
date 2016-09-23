#include "C.h"
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA11547");
	t -> begin();
	int k, n;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> n;
		cout << abs(((315 * n + 36962) / 10) % 10) << endl;
	}
	delete t;
	return 0;
}