#include "C.h"
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA12247");
	t->begin();
	bool cards[53];
	int M[3], F[3], status;
	bool useF[3];
	while (cin >> F[0] >> F[1] >> F[2] >> M[0] >> M[1] && !(F[0] == 0 && F[1] == 0 && F[2] == 0 && M[0] == 0 && M[1] == 0))
	{
		status = 0;
		for (int i = 0; i < 52; i++)
		{
			cards[i] = false;
		}
		cards[M[0] - 1] = true; cards[M[1] - 1] = true;
		cards[F[0] - 1] = true; cards[F[1] - 1] = true; cards[F[2] - 1] = true;
		useF[0] = false; useF[1] = false; useF[2] = false;
		sort(M, M + 2);
		sort(F, F + 3);
		for (int i = 1; i >= 0; i--)
		{
			for (int j = 0; j < 3; j++)
			{
				if (M[i] < F[j] && !useF[j])
				{
					useF[j] = true;
					status++;
					break;
				}
			}
		}
		if (status == 2)
		{
			cout << "-1" << endl;
		}
		else if (status == 0)
		{
			int card = -1;
			for (int i = 0; i < 52; i++)
			{
				if (!cards[i])
				{
					card = i + 1;
					break;
				}
			}
			cout << card << endl;
		}
		else
		{
			int cardToBeat = -1;
			int card = -1;
			for (int i = 0; i < 3; i++)
			{
				if (cardToBeat < F[i] && !useF[i])
				{
					cardToBeat = F[i];
				}
			}
			for (int i = cardToBeat; i < 52; i++)
			{
				if (!cards[i])
				{
					card = i + 1;
					break;
				}
			}
			cout << card << endl;
		}
	}
	delete t;
	return 0;
}