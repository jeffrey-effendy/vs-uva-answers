#include "C.h"
#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b)
{
	if (a == 0)
	{
		return b;
	}
	return gcd(b%a, a);
}

int main()
{
	Test *t = new Test("UVA106");
	t -> begin();
	long long n;
	while (cin >> n)
	{
		bool triple[1000001] = { false };
		long long first = 0;
		long long second = 0;
		for (int r = 1; r <= ceil(sqrt(n)); r++)
		{
			for (int s = 1; s < r; s++)
			{
				long long x = r*r - s*s;
				long long y = 2 * r*s;
				long long z = r*r + s*s;
				if (gcd(x, y) == 1)
				{
					if (x*x + y*y == z*z && z <= n)
					{
						first++;
						for (int k = 1; k <= n / z; k++)
						{
							triple[k*x] = true;
							triple[k*y] = true;
							triple[k*z] = true;
						}
					}
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (!triple[i])
			{
				second++;
			}
		}
		cout << first << " " << second << endl;
	}
	delete t;
	return 0;
}