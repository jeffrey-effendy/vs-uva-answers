#include "C.h"
#include <iostream>

using namespace std;

int suitMapper(string card)
{
	switch (card[1])
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

int valMapper(string card)
{
	switch (card[0])
	{
	case 'T':
		return 8;
	case 'J':
		return 9;
	case 'Q':
		return 10;
	case 'K':
		return 11;
	case 'A':
		return 12;
	default:
		return (int)(card[0] - '0' - 2);
	}
}

void rankCard(string hand[], int size, int& handRank, int value[], int& valueSize)
{
	int suitVal[4][13];
	int val[13];
	int rank;
	bool twoFlag, threeFlag;
	int oneCount, twoCount;
	for (int i = 0; i < 13; i++)
	{
		val[i] = 0;
		for (int j = 0; j < 4; j++)
		{
			suitVal[j][i] = 0;
		}
	}
	for (int i = 0; i < size; i++)
	{
		suitVal[suitMapper(hand[i])][valMapper(hand[i])]++;
		val[valMapper(hand[i])]++;
	}
	
	rank = 8;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (suitVal[i][j] > 0 && suitVal[i][j + 1] > 0 && suitVal[i][j + 2] > 0 && suitVal[i][j + 3] > 0 && suitVal[i][j + 4] > 0)
			{
				handRank = rank;
				value[0] = j + 4;
				valueSize = 1;
				return;
			}
		}
	}

	rank = 7;
	for (int i = 0; i < 13; i++)
	{
		if (val[i] == 4)
		{
			handRank = rank;
			value[0] = i;
			valueSize = 1;
			return;
		}
	}

	rank = 6;
	threeFlag = false;
	twoFlag = false;
	for (int i = 0; i < 13; i++)
	{
		if (val[i] == 3)
		{
			threeFlag = true;
			value[0] = i;
		}
		if (val[i] == 2)
		{
			twoFlag = true;
		}
	}
	if (threeFlag && twoFlag)
	{
		handRank = rank;
		valueSize = 1;
		return;
	}

	rank = 5;
	for (int i = 0; i < 4; i++)
	{
		int vPtr = 0;
		for (int j = 12; j >= 0; j--)
		{
			if (suitVal[i][j] > 0)
			{
				for (int k = 0; k < suitVal[i][j]; k++)
				{
					value[vPtr++] = j;
				}
			}
		}
		if (vPtr == 5)
		{
			handRank = rank;
			valueSize = 5;
			return;
		}
	}

	rank = 4;
	for (int i = 0; i < 13; i++)
	{
		if (val[i] > 0 && val[i + 1] > 0 && val[i + 2] > 0 && val[i + 3] > 0 && val[i + 4] > 0)
		{
			handRank = rank;
			value[0] = i + 4;
			valueSize = 1;
			return;
		}
	}

	rank = 3;
	for (int i = 0; i < 13; i++)
	{
		if (val[i] == 3)
		{
			handRank = rank;
			value[0] = i;
			valueSize = 1;
			return;
		}
	}

	rank = 2;
	twoCount = 0;
	for (int i = 12; i >= 0; i--)
	{
		if (val[i] == 2)
		{
			value[twoCount++] = i;
		}
		else if (val[i] == 1)
		{
			value[2] = i;
		}
	}
	if (twoCount == 2)
	{
		handRank = rank;
		valueSize = 3;
		return;
	}

	rank = 1;
	twoFlag = false;
	oneCount = 1;
	for (int i = 12; i >= 0; i--)
	{
		if (val[i] == 2)
		{
			value[0] = i;
			twoFlag = true;
		}
		else if (val[i] == 1)
		{
			value[oneCount++] = i;
		}
	}
	if (twoFlag)
	{
		handRank = rank;
		valueSize = 4;
		return;
	}

	rank = 0;
	oneCount = 0;
	for (int i = 12; i >= 0; i--)
	{
		if (val[i] > 0)
		{
			for (int j = 0; j < val[i]; j++)
			{
				value[oneCount++] = i;
			}
		}
	}
	handRank = rank;
	valueSize = 5;
	return;
}

int main()
{
	Test *t = new Test("UVA10315");
	t->begin();
	string card;
	string blackHand[5], whiteHand[5];
	int blackRank, whiteRank;
	int blackVal[6], whiteVal[6];
	int blackValSize, whiteValSize;
	int ptr;
	while (cin >> card)
	{
		ptr = 0;
		blackHand[ptr++] = card;
		for (int i = 0; i < 9; i++)
		{
			cin >> card;
			if (ptr > 4)
			{
				whiteHand[ptr % 5] = card;
				ptr++;
			}
			else
			{
				blackHand[ptr++] = card;
			}
		}
		for (int i = 0; i < 5; i++)
		{
			blackVal[i] = 0;
			whiteVal[i] = 0;
		}
		rankCard(blackHand, 5, blackRank, blackVal, blackValSize);
		rankCard(whiteHand, 5, whiteRank, whiteVal, whiteValSize);
		bool blackWin = false, whiteWin = false;
		if (blackRank < whiteRank)
		{
			whiteWin = true;
		}
		else if (blackRank > whiteRank)
		{
			blackWin = true;
		}
		else
		{
			for (int i = 0; i < blackValSize; i++)
			{
				if (blackVal[i] < whiteVal[i])
				{
					whiteWin = true;
					break;
				}
				else if (blackVal[i] > whiteVal[i])
				{
					blackWin = true;
					break;
				}
			}
		}
		if (blackWin == whiteWin)
		{
			cout << "Tie." << endl;
		}
		else if (blackWin)
		{
			cout << "Black wins." << endl;
		}
		else if (whiteWin)
		{
			cout << "White wins." << endl;
		}
	}
	delete t;
	return 0;
}