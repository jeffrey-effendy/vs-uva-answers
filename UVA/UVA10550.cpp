#include "C.h"
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA10550");
	t -> begin();
	int a, b, c, d;
	while (cin >> a >> b >> c >> d && (a != 0 || b != 0 || c != 0 || d != 0))
	{
		int turn = 0;
		turn += 720;
		turn += (a - b) < 0 ? (40 + a - b) * 9 : (a - b) * 9;
		turn += 360;
		turn += (c - b) < 0 ? (40 + c - b) * 9 : (c - b) * 9;
		turn += (c - d) < 0 ? (40 + c - d) * 9 : (c - d) * 9;
		cout << turn << endl;
	}
	delete t;
	return 0;
}