#include "C.h"
#include <iostream>
#include <string>

using namespace std;

int suitMapper(char ch)
{
	switch (ch)
	{
	case 'S':
		return 0;
	case 'H':
		return 1;
	case 'D':
		return 2;
	default:
		return 3;
	}
}

int faceMapper(char ch)
{
	switch (ch)
	{
	case 'J':
		return 0;
	case 'Q':
		return 1;
	case 'K':
		return 2;
	default:
		return 3;
	}
}

bool isFace(char ch)
{
	return ch == 'J' || ch == 'Q' || ch == 'K' || ch == 'A';
}

int main()
{
	Test *t = new Test("UVA462");
	t->begin();
	string card;
	int face[4][4];
	int suitSize[4];
	int basePoint;
	int extraPoint;
	bool allSuitStopped;
	while (cin >> card)
	{
		for (int i = 0; i < 4; i++)
		{
			suitSize[i] = 0;
			for (int j = 0; j < 4; j++)
			{
				face[i][j] = 0;
			}
		}
		basePoint = 0;
		extraPoint = 0;
		allSuitStopped = true;
		for (int i = 0; i < 13; i++)
		{
			if (i > 0)
			{
				cin >> card;
			}
			if (isFace(card[0]))
			{
				face[suitMapper(card[1])][faceMapper(card[0])]++;
				basePoint += faceMapper(card[0]) + 1;
			}
			suitSize[suitMapper(card[1])]++;
		}
		for (int i = 0; i < 4; i++)
		{
			if (face[i][faceMapper('K')] && suitSize[i] == 1)
			{
				basePoint -= face[i][faceMapper('K')];
			}
			if (face[i][faceMapper('Q')] && suitSize[i] <= 2)
			{
				basePoint -= face[i][faceMapper('Q')];
			}
			if (face[i][faceMapper('J')] && suitSize[i] <= 3)
			{
				basePoint -= face[i][faceMapper('J')];
			}
			if (suitSize[i] == 2)
			{
				extraPoint += 1;
			}
			else if (suitSize[i] <= 1)
			{
				extraPoint += 2;
			}
			if (face[i][faceMapper('A')] || (face[i][faceMapper('K')] && suitSize[i] > 1) || (face[i][faceMapper('Q')] && suitSize[i] > 2))
			{
				allSuitStopped = allSuitStopped && true;
			}
			else
			{
				allSuitStopped = allSuitStopped && false;
			}
		}
		if (basePoint + extraPoint < 14)
		{
			cout << "PASS" << endl;
		}
		else if (basePoint >= 16 && allSuitStopped)
		{
			cout << "BID NO-TRUMP" << endl;
		}
		else
		{
			cout << "BID ";
			int max = suitSize[0];
			string ch = "S";
			if (suitSize[1] > max)
			{
				max = suitSize[1];
				ch = "H";
			}
			if (suitSize[2] > max)
			{
				max = suitSize[2];
				ch = "D";
			}
			if (suitSize[3] > max)
			{
				max = suitSize[3];
				ch = "C";
			}
			cout << ch << endl;
		}
	}
	delete t;
	return 0;
}