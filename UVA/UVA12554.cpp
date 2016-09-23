#include "C.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Test *t = new Test("UVA12554");
	t->begin();
	int n;
	string names[101];
	string songs[16] = { 
		"Happy", "birthday", "to", "you",
		"Happy", "birthday", "to", "you",
		"Happy", "birthday", "to", "Rujia",
		"Happy", "birthday", "to", "you"
	};
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> names[i];
	}
	int iName = 0;
	int iSong = 0;
	bool completed = false;
	while (!(iSong == 0 && completed))
	{
		cout << names[iName] << ": " << songs[iSong] << endl;
		iName = (iName + 1) % n;
		iSong = (iSong + 1) % 16;
		if (iName == 0)
		{
			completed = true;
		}
	}
	delete t;
	return 0;
}