#include "C.h"
#include <iostream>
#include <string>

using namespace std;

int isAst(char ch)
{
	if (ch == '*') return 1;
	else return 0;
}

int check(string str[], int rSize, int cSize, int r, int c)
{
	int n = 0;
	if (r != 0 && c != 0) n += isAst(str[r - 1][c - 1]);
	if (r != 0) n += isAst(str[r - 1][c]);
	if (r != 0 && c != cSize - 1) n += isAst(str[r - 1][c + 1]);
	if (c != 0) n += isAst(str[r][c - 1]);
	if (c != cSize - 1) n += isAst(str[r][c + 1]);
	if (r != rSize - 1 && c != 0) n += isAst(str[r + 1][c - 1]);
	if (r != rSize - 1) n += isAst(str[r + 1][c]);
	if (r != rSize - 1 && c != cSize - 1) n += isAst(str[r + 1][c + 1]);
	return n;
}

int main()
{
	Test *t = new Test("UVA10189");
	t->begin();
	string str[100];
	int n, m, c = 1;
	bool first = true;
	while (cin >> n >> m && n != 0 && m != 0)
	{
		if (!first)
			cout << endl;
		cout << "Field #" << c << ":" << endl;
		for (auto i = 0; i < n; i++)
			cin >> str[i];
		for (auto i = 0; i < n; i++)
		{
			for (auto j = 0; j < m; j++)
				if(str[i][j] != '*')
					str[i][j] = (char)(check(str, n, m, i, j) + '0');
			cout << str[i] << endl;
		}
		c++;
		first = false;
	}
	delete t;
	return 0;
}