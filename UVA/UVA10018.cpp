#include "C.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool isPali(unsigned int i)
{
	string st = to_string(i);
	return equal(st.begin(), st.end(), st.rbegin());
}

int main()
{
	Test *t = new Test("UVA10018");
	t->begin();
	int n, iter;
	unsigned int a;
	cin >> n;
	for (auto i = 0; i < n; i++)
	{
		iter = 0;
		cin >> a;
		do
		{
			string st_a = to_string(a);
			reverse(st_a.begin(), st_a.end());
			a += stoi(st_a);
			iter++;
		} while (!isPali(a));
		cout << iter << " " << a << endl;
	}
	delete t;
	return 0;
}
