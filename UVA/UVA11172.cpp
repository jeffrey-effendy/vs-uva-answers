#include "C.h"
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA11172");
	t -> begin();
	int N, a, b;
	cin >> N;
	for (auto i = 0; i < N; i++)
	{
		cin >> a >> b;
		if (a < b)
			cout << "<" << endl;
		else if (a > b)
			cout << ">" << endl;
		else
			cout << "=" << endl;
	}
	delete t;
	return 0;
}
