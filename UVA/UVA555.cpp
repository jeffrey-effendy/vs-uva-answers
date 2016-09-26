#include "C.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int suitMapper(char ch)
{
	switch (ch)
	{
	case 'C':
		return 0;
	case 'D':
		return 1;
	case 'S':
		return 2;
	default:
		return 3;
	}
}

int valMapper(char ch)
{
	switch (ch)
	{
	case 'T':
		return 10;
	case 'J':
		return 11;
	case 'Q':
		return 12;
	case 'K':
		return 13;
	case 'A':
		return 14;
	default:
		return (int)(ch - '0');
	}
}

bool compare(string a, string b)
{
	int aval = suitMapper(a[0]) * 14 + valMapper(a[1]);
	int bval = suitMapper(b[0]) * 14 + valMapper(b[1]);
	return aval < bval;
}

int main()
{
	Test *t = new Test("UVA555");
	t->begin();
	string dealer;
	string cards;
	string hands[4][13];
	int dir;
	while (cin >> dealer && dealer[0] != '#')
	{
		switch (dealer[0])
		{
		case 'S':
			dir = 0;
			break;
		case 'W':
			dir = 1;
			break;
		case 'N':
			dir = 2;
			break;
		default:
			dir = 3;
		}
		int currDir = dir;
		for (int i = 0; i < 52; i++)
		{
			if (i == 0 || i == 26)
			{
				cin >> cards;
			}
			currDir = (currDir + 1) % 4;
			hands[currDir][i / 4] = cards.substr((i % 26) * 2, 2);
		}
		for (int i = 0; i < 4; i++)
		{
			switch (i)
			{
			case 0:
				cout << "S:";
				break;
			case 1:
				cout << "W:";
				break;
			case 2:
				cout << "N:";
				break;
			default:
				cout << "E:";
			}
			sort(hands[i], hands[i] + 13, compare);
			for (int j = 0; j < 13; j++)
			{
				cout << " " << hands[i][j];
			}
			cout << endl;
		}
	}
	delete t;
	return 0;
}