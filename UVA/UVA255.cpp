#include "C.h"
#include <algorithm>
#include <iostream>

using namespace std;

bool inBetween(int a, int x, int y)
{
	return a >= min(x, y) && a <= max(x, y);
}

int main()
{
	Test *t = new Test("UVA255");
	t->begin();
	int board[8][8];
	int km, qm, destQm;
	while (cin >> km >> qm >> destQm)
	{
		int ki = km / 8;
		int kj = km % 8;
		int qi = qm / 8;
		int qj = qm % 8;
		int destQi = destQm / 8;
		int destQj = destQm % 8;
		if (km == qm)
		{
			cout << "Illegal state" << endl;
		}
		else if ((qi != destQi && qj != destQj) || (inBetween(ki, qi, destQi) && kj == qj && qj == destQj) || (inBetween(kj, qj, destQj) && ki == qi && qi == destQi) || (qm == destQm))
		{
			cout << "Illegal move" << endl;
		}
		else
		{
			bool canKingMove = false;
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					board[i][j] = 0;
					if (i == destQi && j == destQj)
					{
						board[i][j] += 2;
					}
					else if (i == destQi || j == destQj)
					{
						board[i][j]++;
					}
					if (i >= ki - 1 && i <= ki + 1 && j == kj)
					{
						board[i][j]--;
					}
					else if (j >= kj - 1 && j <= kj + 1 && i == ki)
					{
						board[i][j]--;
					}
					if (board[i][j] == -1 && !(ki == i && kj == j))
					{
						canKingMove = true;
					}
				}
			}
			if (board[destQi][destQj] == 1)
			{
				cout << "Move not allowed" << endl;
			}
			else
			{
				if (canKingMove)
				{
					cout << "Continue" << endl;
				}
				else
				{
					cout << "Stop" << endl;
				}
			}
		}
	}
	delete t;
	return 0;
}