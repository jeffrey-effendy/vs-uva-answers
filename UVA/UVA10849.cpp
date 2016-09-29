#include "C.h"
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA10849");
	t->begin();
	int C, T, N, di, dj, ti, tj;
	int meeti1, meeti2, meetj1, meetj2;
	cin >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> T >> N;
		for (int j = 0; j < T; j++)
		{
			cin >> di >> dj >> ti >> tj;
			if (di == ti && dj == tj)
			{
				cout << 0 << endl;
			}
			else if (abs(di - dj + ti - tj) % 2 == 1)
			{
				cout << "no move" << endl;
			}
			else
			{
				meeti1 = (di - dj + ti + tj) / 2;
				meetj1 = (ti + tj - di + dj) / 2;
				meeti2 = (ti - tj + di + dj) / 2;
				meetj2 = (di + dj - ti + tj) / 2;
				if ((meeti1 == di || meeti1 == ti) && (meetj1 == dj || meetj1 == tj))
				{
					cout << 1 << endl;
				}
				else if ((meeti2 == di || meeti2 == ti) && (meetj2 == dj || meetj2 == tj))
				{
					cout << 1 << endl;
				}
				else if ((meetj1 < 0 && meetj2 > N - 1) || (meetj2 < 0 && meetj1 > N - 1))
				{
					cout << 3 << endl;
				}
				else
				{
					cout << 2 << endl;
				}
			}
		}
	}
	delete t;
	return 0;
}