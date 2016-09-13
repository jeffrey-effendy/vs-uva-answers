#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int solution(vector<int> &A)
{
	vector<long long> sumOfA(A.size());
	long long sum = 0;
	for (int i = 0; i < A.size(); i++)
	{
		sum += A[i];
		A[i] = sum;
		cout << sum << " ";
	}
	cout << endl;
	for (int i = 0; i < A.size(); i++)
	{
		if (i == 0)
		{
			if (sumOfA[A.size() - 1] - sumOfA[0] == 0)
			{
				cout << " here " << sumOfA[A.size() - 1] << endl;
				return i;
			}
		}
		else if (i == A.size() - 1)
		{
			if (sumOfA[A.size() - 2] == 0)
			{
				return i;
			}
		}
		else if (sumOfA[i - 1] == sumOfA[A.size() - 1] - sumOfA[i])
		{
			return i;
		}
	}
	return -1;
}


int main() 
{
	vector<int> test = {-1, 3, -4, 5, 1, -6, 2, 1};
	cout << solution(test) << endl;
	system("pause");
	return 0;
}