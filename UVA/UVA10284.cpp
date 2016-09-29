#include "C.h"
#include <iostream>

using namespace std;

int board[8][8];

void pfill(int i, int j, bool white)
{
	if (white && i - 1 >= 0 && j - 1 >= 0)
	{
		board[i - 1][j - 1] += 1;
	}
	if (white && i - 1 >= 0 && j + 1 <= 7)
	{
		board[i - 1][j + 1] += 1;
	}
	if (!white && i + 1 <= 7 && j - 1 >= 0)
	{
		board[i + 1][j - 1] += 1;
	}
	if (!white && i + 1 <= 7 && j + 1 <= 7)
	{
		board[i + 1][j + 1] += 1;
	}
}

void kfill(int i, int j)
{
	if (i - 1 >= 0 && j - 1 >= 0)
	{
		board[i - 1][j - 1] += 1;
	}
	if (i - 1 >= 0)
	{
		board[i - 1][j] += 1;
	}
	if (i - 1 >= 0 && j + 1 <= 7)
	{
		board[i - 1][j + 1] += 1;
	}
	if (j - 1 >= 0)
	{
		board[i][j - 1] += 1;
	}
	if (j + 1 <= 7)
	{
		board[i][j + 1] += 1;
	}
	if (i + 1 <= 7 && j - 1 >= 0)
	{
		board[i + 1][j - 1] += 1;
	}
	if (i + 1 <= 7)
	{
		board[i + 1][j] += 1;
	}
	if (i + 1 <= 7 && j + 1 <= 7)
	{
		board[i + 1][j + 1] += 1;
	}
}

void nfill(int i, int j)
{
	if (i - 1 >= 0 && j - 2 >= 0)
	{
		board[i - 1][j - 2] += 1;
	}
	if (i - 1 >= 0 && j + 2 <= 7)
	{
		board[i - 1][j + 2] += 1;
	}
	if (i - 2 >= 0 && j - 1 >= 0)
	{
		board[i - 2][j - 1] += 1;
	}
	if (i - 2 >= 0 && j + 1 <= 7)
	{
		board[i - 2][j + 1] += 1;
	}
	if (i + 1 <= 7 && j - 2 >= 0)
	{
		board[i + 1][j - 2] += 1;
	}
	if (i + 1 <= 7 && j + 2 <= 7)
	{
		board[i + 1][j + 2] += 1;
	}
	if (i + 2 <= 7 && j - 1 >= 0)
	{
		board[i + 2][j - 1] += 1;
	}
	if (i + 2 <= 7 && j + 1 <= 7)
	{
		board[i + 2][j + 1] += 1;
	}
}

void bfill(int i, int j)
{
	int si = i, sj = j;
	for (si = i - 1, sj = j - 1; si >= 0 && sj >= 0; si--, sj--)
	{
		if (board[si][sj] < 0)
		{
			break;
		}
		board[si][sj] += 1;
	}
	for (si = i - 1, sj = j + 1; si >= 0 && sj <= 7; si--, sj++)
	{
		if (board[si][sj] < 0)
		{
			break;
		}
		board[si][sj] += 1;
	}
	for (si = i + 1, sj = j - 1; si <= 7 && sj >= 0; si++, sj--)
	{
		if (board[si][sj] < 0)
		{
			break;
		}
		board[si][sj] += 1;
	}
	for (si = i + 1, sj = j + 1; si <= 7 && sj <= 7; si++, sj++)
	{
		if (board[si][sj] < 0)
		{
			break;
		}
		board[si][sj] += 1;
	}
}

void rfill(int i, int j)
{
	int si = i, sj = j;
	for (si = i, sj = j - 1; sj >= 0; sj--)
	{
		if (board[si][sj] < 0)
		{
			break;
		}
		board[si][sj] += 1;
	}
	for (si = i, sj = j + 1; sj <= 7; sj++)
	{
		if (board[si][sj] < 0)
		{
			break;
		}
		board[si][sj] += 1;
	}
	for (si = i - 1, sj = j; si >= 0; si--)
	{
		if (board[si][sj] < 0)
		{
			break;
		}
		board[si][sj] += 1;
	}
	for (si = i + 1, sj = j; si <= 7; si++)
	{
		if (board[si][sj] < 0)
		{
			break;
		}
		board[si][sj] += 1;
	}
}

void qfill(int i, int j)
{
	bfill(i, j);
	rfill(i, j);
}

int main()
{
	Test *t = new Test("UVA10284");
	t->begin();
	string fen;
	int storage[50], storageSize;
	int pi, pj, safe;
	while (cin >> fen)
	{
		storageSize = 0;
		safe = 0;
		pi = 0;
		pj = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				board[i][j] = 0;
			}
		}
		for (int i = 0; i < fen.size(); i++)
		{
			if (isdigit(fen[i]))
			{
				pj += (int)(fen[i] - '0');
			}
			else if (fen[i] == '/')
			{
				pi++;
				pj = 0;
			}
			else
			{
				board[pi][pj] -= 100;
				if (fen[i] == 'p')
				{
					pfill(pi, pj, false);
				}
				else if (fen[i] == 'P')
				{
					pfill(pi, pj, true);
				}
				else if (tolower(fen[i]) == 'n')
				{
					nfill(pi, pj);
				}
				else if (tolower(fen[i]) == 'k')
				{
					kfill(pi, pj);
				}
				else if (tolower(fen[i]) == 'r')
				{
					storage[storageSize++] = 'r';
					storage[storageSize++] = pi;
					storage[storageSize++] = pj;
				}
				else if (tolower(fen[i]) == 'b')
				{
					storage[storageSize++] = 'b';
					storage[storageSize++] = pi;
					storage[storageSize++] = pj;
				}
				else if (tolower(fen[i]) == 'q')
				{
					storage[storageSize++] = 'q';
					storage[storageSize++] = pi;
					storage[storageSize++] = pj;
				}
				pj++;
			}
		}
		for (int i = 0; i < storageSize; i += 3)
		{
			if (storage[i] == 'r')
			{
				rfill(storage[i + 1], storage[i + 2]);
			}
			else if (storage[i] == 'b')
			{
				bfill(storage[i + 1], storage[i + 2]);
			}
			else if (storage[i] == 'q')
			{
				qfill(storage[i + 1], storage[i + 2]);
			}
		}
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (board[i][j] == 0)
				{
					safe++;
				}
			}
		}
		cout << safe << endl;
	}
	delete t;
	return 0;
}