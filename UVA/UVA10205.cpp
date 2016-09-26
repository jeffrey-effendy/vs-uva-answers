#include "C.h"
#include <iostream>
#include <string>

using namespace std;

string valMapper(int n)
{
	n--;
	int val = n % 13;
	switch (val)
	{
	case 9:
		return "Jack";
	case 10:
		return "Queen";
	case 11:
		return "King";
	case 12:
		return "Ace";
	default:
		return to_string(val + 2);
	}
}

string faceMapper(int n)
{
	n--;
	int suit = n / 13;
	switch(suit)
	{
	case 0:
		return "Clubs";
	case 1:
		return "Diamonds";
	case 2:
		return "Hearts";
	case 3:
		return "Spades";
	}
}

int main()
{
	Test *t = new Test("UVA10205");
	t->begin();
	int deck[52];
	int shuffledDeck[52];
	int shuffles[100][52];
	int T, N, card;
	string shuffleType;
	cin >> T;
	for (int k = 0; k < T; k++)
	{
		cin >> N;
		for (int i = 0; i < 52; i++)
		{
			deck[i] = i + 1;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < 52; j++)
			{
				cin >> card;
				shuffles[i][j] = card;
			}
		}
		cin.ignore(80, '\n');
		while (getline(cin, shuffleType) && shuffleType.size() > 0)
		{
			for (int i = 0; i < 52; i++)
			{
				shuffledDeck[i] = deck[shuffles[stoi(shuffleType) - 1][i] - 1];
			}
			for (int i = 0; i < 52; i++)
			{
				deck[i] = shuffledDeck[i];
			}
		}
		if (k != 0)
		{
			cout << endl;
		}
		for (int i = 0; i < 52; i++)
		{
			cout << valMapper(deck[i]) << " of " << faceMapper(deck[i]) << endl;
		}
	}
	delete t;
	return 0;
}