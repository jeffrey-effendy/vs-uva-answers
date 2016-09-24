#include "C.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Test *t = new Test("UVA11956");
	t->begin();
	int T, currPtr;
	unsigned char bytes[101];
	string input;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		currPtr = 0;
		cin >> input;
		for (int j = 0; j < 100; j++)
		{
			bytes[j] = 0;
		}
		for (int j = 0; j < input.length(); j++)
		{
			if (input[j] == '>')
			{
				currPtr = (currPtr + 1) % 100;
			}
			else if (input[j] == '<')
			{
				currPtr = (currPtr - 1) < 0 ? 99 : currPtr - 1;
			}
			else if (input[j] == '+')
			{
				bytes[currPtr]++;
			}
			else if (input[j] == '-')
			{
				bytes[currPtr]--;
			}
		}
		cout << dec << "Case " << i + 1 << ":";
		for (int j = 0; j < 100; j++)
		{
			cout << hex << uppercase << " " << ((int)bytes[j] < 16 ? "0" : "") << (int)bytes[j];
		}
		cout << endl;
	}
	delete t;
	return 0;
}