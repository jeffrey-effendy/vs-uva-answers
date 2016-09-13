#include "C.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
	Test *t = new Test("UVA101");
	t->begin();
	int n;
	string box[25];
	string in;
	cin >> n;
	cin.ignore(80, '\n');
	for (int i = 0; i < n; i++) 
	{
		box[i] = char(i + 97);
	}
	while (getline(cin, in) && strcmp(in.c_str(), "quit") != 0)
	{
		bool move = in[0] == 'm';
		bool onto = in[9] == 'n' || in[9] == 't';
		bool pile = !move;
		bool over = !onto;
		string a = "";
		string b = "";
		if (isdigit(in[5]) && isdigit(in[6])) 
		{
			if (isdigit(in[13]) && isdigit(in[14])) 
			{
				a = a + in[5] + in[6];
				b = b + in[13] + in[14];
			}
			else if (isdigit(in[13])) 
			{
				a = a + in[5] + in[6];
				b = b + in[13];
			}
		}
		else if (isdigit(in[5])) 
		{
			a = a + in[5];
			b = b + in[12] + in[13];
		}
		else 
		{
			a = a + in[5];
			b = b + in[12];
		}
		char ca = char(atoi(a.c_str()) + 97);
		char cb = char(atoi(b.c_str()) + 97);
		string ra = "", rb = "";
		bool valid = true;
		if (move && onto) 
		{
			for (int i = 0; i < n; i++) 
			{
				if (box[i].find(ca) != string::npos)
				{
					if (box[i].find(cb) == string::npos)
					{
						while (box[i][box[i].size() - 1] != ca) {
							box[int(box[i][box[i].size() - 1]) - 97] += box[i][box[i].size() - 1];
							box[i].erase(box[i].size() - 1, 1);
						}
						box[i].erase(box[i].size()-1,1);
					} 
					else
					{
						valid = false;
					}
				}
			}
			if (valid)
			{
				for (int i = 0; i < n; i++)
				{
					if (box[i].find(cb) != string::npos)
					{
						while (box[i][box[i].size() - 1] != cb) {
							box[int(box[i][box[i].size() - 1]) - 97] += box[i][box[i].size() - 1];
							box[i].erase(box[i].size() - 1, 1);
						}
						box[i] += ca;
					}
				}
			}
		}
		else if (pile && onto) 
		{
			for (int i = 0; i < n; i++)
			{
				if (box[i].find(ca) != string::npos)
				{
					if (box[i].find(cb) == string::npos)
					{
						ra = box[i].substr(box[i].find(ca));
						box[i].resize(box[i].find(ca));
					}
					else
					{
						valid = false;
					}
				}
			}
			if (valid)
			{
				for (int i = 0; i < n; i++)
				{
					if (box[i].find(cb) != string::npos)
					{
						while (box[i][box[i].size() - 1] != cb) {
							box[int(box[i][box[i].size() - 1]) - 97] += box[i][box[i].size() - 1];
							box[i].erase(box[i].size() - 1, 1);
						}
						box[i] += ra;
					}
				}
			}
		}
		else if (move && over) 
		{
			for (int i = 0; i < n; i++)
			{
				if (box[i].find(ca) != string::npos)
				{
					if (box[i].find(cb) == string::npos)
					{
						while (box[i][box[i].size() - 1] != ca) {
							box[int(box[i][box[i].size() - 1]) - 97] += box[i][box[i].size() - 1];
							box[i].erase(box[i].size() - 1, 1);
						}
						box[i].erase(box[i].size() - 1, 1);
					}
					else
					{
						valid = false;
					}
				}
			}
			if (valid)
			{
				for (int i = 0; i < n; i++)
				{
					if (box[i].find(cb) != string::npos)
					{
						box[i] = box[i] + ca;
					}
				}
			}
		}
		else if (pile && over)
		{
			for (int i = 0; i < n; i++)
			{
				if (box[i].find(ca) != string::npos)
				{
					if (box[i].find(cb) == string::npos)
					{
						ra = box[i].substr(box[i].find(ca));
						box[i].resize(box[i].find(ca));
					}
					else
					{
						valid = false;
					}
				}
			}
			if (valid)
			{
				for (int i = 0; i < n; i++)
				{
					if (box[i].find(cb) != string::npos)
					{
						box[i] = box[i] + ra;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << i << ":";
		for (int j = 0; j < box[i].size(); j++)
		{
			 cout << " " << int(box[i][j]) - 97;
		}
		cout << endl;
	}
	delete t;
	return 0;
}