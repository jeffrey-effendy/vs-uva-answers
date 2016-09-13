#include "C.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Box
{
public:
	vector<int> attrs;
	int id;

	Box() {}

	void insert(vector<int> attrs, int id)
	{
		this->id = id;
		this->attrs = attrs;
		sort(this->attrs.begin(), this->attrs.end());
	}

	bool fitInto(const Box& other)
	{
		int size = this->attrs.size() < other.attrs.size() ? this->attrs.size() : other.attrs.size();
		for (int i = 0; i < size; i++)
		{
			if (this->attrs[i] >= other.attrs[i])
			{
				return false;
			}
		}
		return true;
	}
};

bool boxCompare(const Box& boxA, const Box& boxB)
{
	int size = boxA.attrs.size() < boxB.attrs.size() ? boxA.attrs.size() : boxB.attrs.size();
	for (int i = 0; i < size; i++)
	{
		if (boxA.attrs[i] < boxB.attrs[i])
		{
			return true;
		}
		else if (boxA.attrs[i] > boxB.attrs[i])
		{
			return false;
		}
	}
	return false;
}

int main()
{
	Test *t = new Test("UVA103");
	t->begin();
	int n, d, a;
	while (cin >> n >> d)
	{
		vector<Box> box(30);
		for (int i = 0; i < n; i++)
		{
			vector<int> attrs;
			for (int j = 0; j < d; j++)
			{
				cin >> a;
				attrs.push_back(a);
			}
			box[i].insert(attrs, i);
		}
		sort(box.begin(), box.end(), boxCompare);
		vector< vector<int> > L(30);
		int max = 0;
		L[0].push_back(0);
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (box[L[j][L[j].size() - 1]].fitInto(box[i]))
				{
					if (L[i].size() < L[j].size())
					{
						L[i] = L[j];
					}
				}
			}
			L[i].push_back(i);
			if (L[i].size() > L[max].size())
			{
				max = i;
			}
		}
		cout << L[max].size() << endl;
		for (int i = 0; i < L[max].size(); i++)
		{
			if (i != 0)
			{
				cout << " ";
			}
			cout << box[L[max][i]].id + 1;
		}
		cout << endl;
	}
	delete t;
	return 0;
}