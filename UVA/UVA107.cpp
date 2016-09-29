#include "C.h"
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

const float epsilon = 0.0000001;

int main()
{
	Test *t = new Test("UVA107");
	t->begin();
	long long initial_height, n_workers;
	int N, tree_height;
	while (cin >> initial_height >> n_workers && (initial_height != 0 || n_workers != 0))
	{
		N = 1;
		tree_height = 1;
		if (n_workers > 1)
		{
			while (fabs(log(N + 1) / log(N) - log(initial_height) / log(n_workers)) > epsilon)
			{
				N++;
			}
			tree_height = floor(log(n_workers) / log(N) + 0.5) + 1;
			long long height_stack = 0;
			for (int i = 0; i < tree_height; i++)
			{
				height_stack += pow(N + 1, i) * pow(N, tree_height - i - 1);
			}
			cout << (pow(N, tree_height - 1) - 1) / (N - 1) << " " << height_stack << endl;
		}
		else
		{
			tree_height = (int)(log(initial_height) / log(2) + 0.5) + 1;
			cout << tree_height - 1 << " " << pow(2, tree_height) - 1 << endl;
		}
	}
	delete t;
	return 0;
}