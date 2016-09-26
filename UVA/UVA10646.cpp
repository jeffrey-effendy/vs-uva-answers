#include "C.h"
#include <iostream>
#include <string>

using namespace std;

int value(string card)
{
	if (isdigit(card[0]))
	{
		return (int)(card[0] - '0');
	}
	else
	{
		return 10;
	}
}

int main()
{
	Test *t = new Test("UVA10646");
	t->begin();
	int T;
	string hand[52], pile[52];
	string card;
	int cardToDispose, Y;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		for (int j = 26; j >= 0; j--)
		{
			cin >> card;
			pile[j] = card;
		}
		for (int j = 24; j >= 0; j--)
		{
			cin >> card;
			hand[j] = card;
		}
		cardToDispose = 0;
		Y = 0;
		for (int j = 0; j < 3; j++)
		{
			int topVal = value(pile[cardToDispose]);
			Y += topVal;
			cardToDispose += (10 - topVal) + 1;
		}
		cout << "Case " << i + 1 << ": ";
		if (Y <= 27 - cardToDispose)
		{
			cout << pile[27 - Y] << endl;
		}
		else
		{
			cout << hand[52 - Y - cardToDispose] << endl;
		}
	}
	delete t;
	return 0;
}