#include "C.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cardValue(string card)
{
	switch (card[1])
	{
	case 'J':
		return 1;
	case 'Q':
		return 2;
	case 'K':
		return 3;
	case 'A':
		return 4;
	default:
		return 0;
	}
}

int main()
{
	Test *t = new Test("UVA162");
	t->begin();
	vector<string> player, dealer, table;
	string card;
	bool playerTurn;
	while (cin >> card && card[0] != '#')
	{
		player.push_back(card);
		playerTurn = false;
		for (int i = 0; i < 51; i++)
		{
			cin >> card;
			if (!playerTurn)
			{
				dealer.push_back(card);
			}
			else
			{
				player.push_back(card);
			}
			playerTurn = !playerTurn;
		}
		string cardOnTable;
		int penalty = 0;
		while ((player.size() != 0 && playerTurn) || ( dealer.size() != 0 && !playerTurn))
		{
			if (playerTurn)
			{
				cardOnTable = player.back();
				player.pop_back();
			}
			else
			{
				cardOnTable = dealer.back();
				dealer.pop_back();
			}
			table.push_back(cardOnTable);
			if (cardValue(cardOnTable) > 0)
			{
				playerTurn = !playerTurn;
				penalty = cardValue(cardOnTable);
			}
			else
			{
				if (penalty > 0)
				{
					penalty--;
					if (penalty == 0)
					{
						playerTurn = !playerTurn;
						if (playerTurn)
						{
							player.insert(player.begin(), table.rbegin(), table.rend());
						}
						else
						{
							dealer.insert(dealer.begin(), table.rbegin(), table.rend());
						}
						table.clear();
					}
				}
				else
				{
					playerTurn = !playerTurn;
				}
			}
		}
		if (player.size() == 0 && playerTurn)
		{
			cout << "1" << setw(3) << right << dealer.size() << endl;
		}
		else
		{
			cout << "2" << setw(3) << right << player.size() << endl;
		}
		player.clear();
		dealer.clear();
		table.clear();
	}
	delete t;
	return 0;
}