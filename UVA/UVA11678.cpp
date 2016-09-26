#include "C.h"
#include <iostream>
#include <map>

using namespace std;

int main()
{
	Test *t = new Test("UVA11678");
	t->begin();
	int A, B, card;
	int AUniqueCard, BUniqueCard;
	map<int, bool> ACard;
	map<int, bool> BCard;
	while (cin >> A >> B && !(A == 0 && B == 0))
	{
		AUniqueCard = 0;
		BUniqueCard = 0;
		ACard.clear();
		BCard.clear();
		for (int i = 0; i < A; i++)
		{
			cin >> card;
			if (!ACard[card])
			{
				AUniqueCard++;
				ACard[card] = true;
			}
		}
		for (int i = 0; i < B; i++)
		{
			cin >> card;
			if (!BCard[card])
			{
				if (ACard[card])
				{
					AUniqueCard--;
					BUniqueCard--;
				}
				BUniqueCard++;
				BCard[card] = true;
			}
		}
		cout << (AUniqueCard < BUniqueCard ? AUniqueCard : BUniqueCard) << endl;
	}
	delete t;
	return 0;
}