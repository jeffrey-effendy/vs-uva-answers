#include "C.h"
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA11727");
	t -> begin();
	int T;
	int s[3];
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> s[0] >> s[1] >> s[2];
		sort(s, s + 3);
		cout << "Case " << i + 1 << ": " << s[1] << endl;
	}
	delete t;
	return 0;
}