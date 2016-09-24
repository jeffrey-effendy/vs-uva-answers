#include "C.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int f(int n)
{
	int temp = n;
	int sum = 0;
	while (temp != 0)
	{
		sum += temp % 10;
		temp /= 10;
	}
	return sum;
}

int g(string str)
{
	int sum = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (isalpha(str[i]))
		{
			sum += tolower(str[i]) - 'a' + 1;
		}
	}
	while (sum / 10 != 0)
	{
		sum = f(sum);
	}
	return sum;
}
int main()
{
	Test *t = new Test("UVA10424");
	t->begin();
	string str;
	while (getline(cin, str))
	{		
		int num = g(str);
		getline(cin, str);
		int den = g(str);
		if (num > den)
		{
			int temp = num;
			num = den;
			den = temp;
		}
		if (den == 0)
		{
			cout << endl;
		}
		else
		{
			cout << setprecision(2) << fixed << num * 100.0 / den << " %" << endl;
		}
	}	
	delete t;
	return 0;
}