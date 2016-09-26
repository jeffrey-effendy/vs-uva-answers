#include "C.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

bool isOudler(string card)
{
	if (card == "one of trumps" || card == "twenty-one of trumps" || card == "fool")
	{
		return true;
	}
	else
	{
		return false;
	}
}

int value(string card)
{
	if (isOudler(card) || (card[0] == 'k' && card[1] == 'i'))
	{
		return 9;
	}
	else if (card[0] == 'q')
	{
		return 7;
	}
	else if (card[0] == 'k')
	{
		return 5;
	}
	else if (card[0] == 'j')
	{
		return 3;
	}
	else
	{
		return 1;
	}
}

int main()
{
	Test *t = new Test("UVA11225");
	t->begin();
	int T, N, nOudlers, cardValue, toWin;
	string card;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		nOudlers = 0;
		cardValue = 0;
		cin >> N;
		cin.ignore(80, '\n');
		for (int j = 0; j < N; j++)
		{
			getline(cin, card);
			if (isOudler(card))
			{
				nOudlers++;
			}
			cardValue += value(card);
		}
		switch (nOudlers)
		{
		case 0:
			toWin = 112;
			break;
		case 1:
			toWin = 102;
			break;
		case 2:
			toWin = 82;
			break;
		default:
			toWin = 72;
		}
		if (i != 0)
		{
			cout << endl;
		}
		cout << "Hand #" << i + 1 << endl;
		if (cardValue >= toWin)
		{
			cout << "Game won by " << floor((cardValue - toWin) / 2.0) << " point(s)." << endl;
		}
		else
		{
			cout << "Game lost by " << ceil((toWin - cardValue) / 2.0) << " point(s)." << endl;
		}
	}
	delete t;
	return 0;
}